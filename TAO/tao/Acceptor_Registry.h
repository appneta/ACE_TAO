// This may look like C, but it's really -*- C++ -*-

//=============================================================================
/**
 *  @file     Acceptor_Registry.h
 *
 *  $Id$
 *
 *   Interface for the TAO pluggable protocol framework.
 *
 *
 *  @author  Fred Kuhns <fredk@cs.wustl.edu>  Ossama Othman <ossama@uci.edu>
 */
//=============================================================================


#ifndef TAO_ACCEPTOR_REGISTRY_H
#define TAO_ACCEPTOR_REGISTRY_H
#include "ace/pre.h"

#include "tao/Pluggable.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/corbafwd.h"
#include "tao/Resource_Factory.h"

// Forward declarations.
class ACE_Addr;
class ACE_Reactor;
class ACE_CString;
class TAO_ORB_Core;
class TAO_Acceptor_Filter;

class TAO_Stub;
class TAO_Profile;
class TAO_MProfile;


typedef TAO_Acceptor** TAO_AcceptorSetIterator;

/**
 * @class TAO_Acceptor_Registry
 *
 * @brief Acceptor Registry and Generic Acceptor interface definitions.
 * All loaded ESIOP or GIOP acceptor bridges must register with
 * this object.
 *
 * This class maintains a list os acceptor factories
 * for all loaded ORB protocols.
 * There is one Acceptor_Registry per ORB_Core.
 */
class TAO_Export TAO_Acceptor_Registry
{
public:
  // = Initialization and termination methods.
  ///  Default constructor.
  TAO_Acceptor_Registry (void);

  ///  Default destructor.
  ~TAO_Acceptor_Registry (void);

  /// Initialize all registered acceptors.  Return -1 on error.
  int open (TAO_ORB_Core *orb_core,
            ACE_Reactor *reactor,
            CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Close all open acceptors.
  int close_all (void);

  /// Returns the total number of endpoints in all of its acceptors.
  size_t endpoint_count (void);

  /**
   * Use <filter> to populate <mprofile> object with profiles.
   * Different filters implement different strategies for selection
   * of endpoints to be included into <mprofile>.
   */
  int make_mprofile (const TAO_ObjectKey& object_key,
                     TAO_MProfile &mprofile,
                     TAO_Acceptor_Filter *filter);

  /// Check if there is at least one profile in <mprofile> that
  /// corresponds to a collocated object.
  int is_collocated (const TAO_MProfile& mprofile);

  /// Return the acceptor bridges
  TAO_Acceptor *get_acceptor (CORBA::ULong tag);

  // = Iterator.
  TAO_AcceptorSetIterator begin (void);
  TAO_AcceptorSetIterator end (void);

private:

  /// Create a default acceptor for all loaded protocols.
  int open_default (TAO_ORB_Core *orb_core,
                    ACE_Reactor *reactor,
                    const char *options);

  /// Create a default acceptor using the specified protocol factory.
  int open_default (TAO_ORB_Core *orb_core,
                    ACE_Reactor *reactor,
                    int major,
                    int minor,
                    TAO_ProtocolFactorySetItor &factory,
                    const char *options);

  /// Extract endpoint-specific options from the endpoint string.
  void extract_endpoint_options (ACE_CString &addrs,
                                 ACE_CString &options,
                                 TAO_Protocol_Factory *factory);

  /// Extract endpoint/address specific version from the endpoint
  /// string.
  void extract_endpoint_version (ACE_CString &address,
                                 int &major,
                                 int &minor);

  /// Iterator through addrs in the string <iop>, and create an
  /// acceptor for each one.
  int open_i (TAO_ORB_Core *orb_core,
              ACE_Reactor *reactor,
              ACE_CString &address,
              TAO_ProtocolFactorySetItor &factory,
              CORBA::Environment &ACE_TRY_ENV);

private:
  // The acceptor registry should not be copied.
  ACE_UNIMPLEMENTED_FUNC (TAO_Acceptor_Registry (const TAO_Acceptor_Registry&))
  ACE_UNIMPLEMENTED_FUNC (void operator= (const TAO_Acceptor_Registry&))

private:
  /// List of acceptors that are currently open.
  TAO_Acceptor **acceptors_;

  /// Number of acceptors that are currently open.
  size_t size_;
};

#if defined(__ACE_INLINE__)
#include "tao/Acceptor_Registry.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_ACCEPTOR_REGISTRY_H */
