// This may look like C, but it's really -*- C++ -*-

#if !defined (TAO_CONNECT_H)
#  define TAO_CONNECT_H

// ============================================================================
//
// = LIBRARY
//    TAO
// 
// = FILENAME
//    connect.h
//
// = AUTHOR
//     Chris Cleeland
// 
// ============================================================================

#  include "ace/Reactor.h"
#  include "ace/Acceptor.h"
#  include "ace/SOCK_Acceptor.h"
#  include "ace/Synch.h"
#  include "ace/Svc_Handler.h"

// Forward Decls
class TAO_OA_Parameters;

class TAO_Client_Connection_Handler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
  // = TITLE
  //      <Svc_Handler> used on the client side and returned by the
  //      <TAO_CONNECTOR>.  
  // @@ Should this be in here or in the default_client.*?
{
public:
  // = Intialization method.
  TAO_Client_Connection_Handler (ACE_Thread_Manager * = 0);
  // Do-nothing constructor

  // = <Connector> hook.
  virtual int open (void *);
  // Initialization hook

  void in_use (CORBA::Boolean);
  // Set the in-use flag.

  CORBA::Boolean in_use (void);
  // Return state of the in-use flag.

private:
  CORBA::Boolean in_use_;
  // True value indicates that something is using this handler.
};

// = Useful typedef.

// If we are using TSS, there is no reason to use locking in the connector
#if defined (TAO_HAS_TSS_ORBCORE)
#  define ACE_CACHED_CONNECT_STRATEGY_LOCK ACE_SYNCH_RW_MUTEX
#else
#  define ACE_CACHED_CONNECT_STRATEGY_LOCK ACE_SYNCH_NULL_MUTEX
#endif

typedef ACE_Strategy_Connector<TAO_Client_Connection_Handler, ACE_SOCK_CONNECTOR> 
	TAO_CONNECTOR;

typedef ACE_Cached_Connect_Strategy<TAO_Client_Connection_Handler, 
	                            ACE_SOCK_CONNECTOR,
				    ACE_CACHED_CONNECT_STRATEGY_LOCK>
        TAO_CACHED_CONNECT_STRATEGY;

typedef ACE_NOOP_Creation_Strategy<TAO_Client_Connection_Handler> 
	TAO_NULL_CREATION_STRATEGY;

#if defined (TAO_HAS_CLIENT_CONCURRENCY)
  // @@ Chris, shouldn't this always be "potentially" the case, even
  // if a client didn't want to use it? 
  virtual CONCURRENCY_STRATEGY *concurrency_strategy (void);
#endif /* TAO_HAS_CLIENT_CONCURRENCY */

// @@ Is this really an *OA* connection handler anymore?  Seems like
// connections are really associated with ORBs in the POA-based
// architecture.
class TAO_OA_Connection_Handler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
  // = TITLE
  //    Handles requests on a single connection in a server.
  //
{
public:
  TAO_OA_Connection_Handler (ACE_Thread_Manager *t = ACE_Thread_Manager::instance ());
  // Constructor.
  
  virtual int open (void *);
  // Called by the framework when the handler is completely set up.
  // Argument is unused.
  
  virtual int svc (void);
  // Only used when the handler is turned into an active object by
  // calling <activate>.  This serves as the event loop in such cases.

  TAO_OA_Parameters *params (void);
  void params (TAO_OA_Parameters *p);

  // = Template Methods Called by <handle_input>

  virtual int read_message (CDR &msg, CORBA::Environment &env);
  // Extract a message from the stream associated with <peer()> and
  // place it into <msg>.  Return 0 if success, -1 with <errno> and
  // <env> set if problems.

  virtual int handle_message (CDR &msg, int &response_required,
                              CDR &response, CORBA::Environment &env);
  // Handle processing of the request residing in <msg>, setting
  // <response_required> to zero if the request is for a oneway or
  // non-zero if for a two-way and <response> to any necessary
  // response (including errors).  In case of errors, -1 is returned
  // and additional information carried in <env>.

  virtual void send_response (CDR &response);
  // @@ Please document me...

protected:
  virtual int handle_input (ACE_HANDLE = ACE_INVALID_HANDLE);
  virtual int handle_close (ACE_HANDLE, ACE_Reactor_Mask);

private:
  typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> SUPERCLASS;

  TAO_OA_Parameters *params_;
};

typedef ACE_Strategy_Acceptor<TAO_OA_Connection_Handler, ACE_SOCK_ACCEPTOR> 
	TAO_ACCEPTOR;

// Declare that these two functions should be specialized.

#if defined (ACE_WIN32)
extern template size_t
ACE_Hash_Addr<ACE_INET_Addr>::hash_i (const ACE_INET_Addr &addr) const;
#endif /* ACE_WIN32 */

#endif /* TAO_CONNECT_H */
