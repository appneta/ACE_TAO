/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_MARSHALS_H_
#define _TAO_IDL_MARSHALS_H_

#include "marshalC.h"


#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

class POA_Marshal;
typedef POA_Marshal *POA_Marshal_ptr;
class  POA_Marshal :  public virtual PortableServer::ServantBase
{
protected:
  POA_Marshal (void);

public:
  POA_Marshal (const POA_Marshal& rhs);
  virtual ~POA_Marshal (void);


  virtual CORBA::Boolean _is_a (
      const char* logical_type_id,
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  virtual void* _downcast (
      const char* logical_type_id
    );

  static void _is_a_skel (
      CORBA::ServerRequest &req,
      void *obj,
      void *context,
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  static void _non_existent_skel (
      CORBA::ServerRequest &req,
      void *obj,
      void *context,
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  virtual void _dispatch (
      CORBA::ServerRequest &_tao_req,
      void *_tao_context,
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  ::Marshal *_this (
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  virtual const char* _interface_repository_id (void) const;

  virtual void test_short (
      CORBA::Short s1,
      CORBA::Short_out s2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void test_short_skel (
      CORBA::ServerRequest &_tao_req, 
      void *_tao_obj, 
      void *_tao_context, 
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  virtual void test_long (
      CORBA::Long l1,
      CORBA::Long_out l2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void test_long_skel (
      CORBA::ServerRequest &_tao_req, 
      void *_tao_obj, 
      void *_tao_context, 
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  virtual void test_octet (
      CORBA::Octet o1,
      CORBA::Octet_out o2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void test_octet_skel (
      CORBA::ServerRequest &_tao_req, 
      void *_tao_obj, 
      void *_tao_context, 
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  virtual void test_char (
      CORBA::Char c1,
      CORBA::Char_out c2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void test_char_skel (
      CORBA::ServerRequest &_tao_req, 
      void *_tao_obj, 
      void *_tao_context, 
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  virtual void test_double (
      CORBA::Double d1,
      CORBA::Double_out d2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void test_double_skel (
      CORBA::ServerRequest &_tao_req, 
      void *_tao_obj, 
      void *_tao_context, 
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  virtual void test_struct (
      const Marshal::Marshal_Struct & ms1,
      Marshal::Marshal_Struct_out ms2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void test_struct_skel (
      CORBA::ServerRequest &_tao_req, 
      void *_tao_obj, 
      void *_tao_context, 
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  virtual void test_union (
      const Marshal::Marshal_Union & u1,
      Marshal::Marshal_Union_out u2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void test_union_skel (
      CORBA::ServerRequest &_tao_req, 
      void *_tao_obj, 
      void *_tao_context, 
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  virtual void test_any (
      const CORBA::Any & a1,
      CORBA::Any_out a2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void test_any_skel (
      CORBA::ServerRequest &_tao_req, 
      void *_tao_obj, 
      void *_tao_context, 
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  virtual void test_sequence (
      const Marshal::AnySeq & as1,
      Marshal::AnySeq_out as2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void test_sequence_skel (
      CORBA::ServerRequest &_tao_req, 
      void *_tao_obj, 
      void *_tao_context, 
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );

  virtual void test_recursive (
      const Marshal::Marshal_Recursive & mr1,
      Marshal::Marshal_Recursive_out mr2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void test_recursive_skel (
      CORBA::ServerRequest &_tao_req, 
      void *_tao_obj, 
      void *_tao_context, 
      CORBA::Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );


};


#if !defined (_MARSHAL___THRU_POA_COLLOCATED_SH_)
#define _MARSHAL___THRU_POA_COLLOCATED_SH_

class  _tao_thru_poa_collocated_Marshal   : public virtual ::Marshal
{
public:
  _tao_thru_poa_collocated_Marshal (
      TAO_Stub *stub
    );
  virtual CORBA::Boolean _is_a(
      const CORBA::Char *logical_type_id,
      CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
    );
  
  virtual CORBA::Boolean _non_existent(
      CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
    );
  
    virtual void test_short (
      CORBA::Short s1,
      CORBA::Short_out s2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void test_long (
      CORBA::Long l1,
      CORBA::Long_out l2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void test_octet (
      CORBA::Octet o1,
      CORBA::Octet_out o2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void test_char (
      CORBA::Char c1,
      CORBA::Char_out c2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void test_double (
      CORBA::Double d1,
      CORBA::Double_out d2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void test_struct (
      const Marshal::Marshal_Struct & ms1,
      Marshal::Marshal_Struct_out ms2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void test_union (
      const Marshal::Marshal_Union & u1,
      Marshal::Marshal_Union_out u2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void test_any (
      const CORBA::Any & a1,
      CORBA::Any_out a2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void test_sequence (
      const Marshal::AnySeq & as1,
      Marshal::AnySeq_out as2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void test_recursive (
      const Marshal::Marshal_Recursive & mr1,
      Marshal::Marshal_Recursive_out mr2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

};


#endif /* end #if !defined */

// TIE class: Refer to CORBA v2.2, Section 20.34.4
template <class T>
class  POA_Marshal_tie : public POA_Marshal
{
public:
  POA_Marshal_tie (T &t);
  // the T& ctor
  POA_Marshal_tie (T &t, PortableServer::POA_ptr poa);
  // ctor taking a POA
  POA_Marshal_tie (T *tp, CORBA::Boolean release=1);
  // ctor taking pointer and an ownership flag
  POA_Marshal_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release=1);
  // ctor with T*, ownership flag and a POA
  ~POA_Marshal_tie (void);
  // dtor
  
  // TIE specific functions
  T *_tied_object (void);
  // return the underlying object
  void _tied_object (T &obj);
  // set the underlying object
  void _tied_object (T *obj, CORBA::Boolean release=1);
  // set the underlying object and the ownership flag
  CORBA::Boolean _is_owner (void);
  // do we own it
  void _is_owner (CORBA::Boolean b);
  // set the ownership
  
  // overridden ServantBase operations
  PortableServer::POA_ptr _default_POA (
      CORBA::Environment &env = 
        TAO_default_environment ()
    );
  void test_short (
      CORBA::Short s1,
      CORBA::Short_out s2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  void test_long (
      CORBA::Long l1,
      CORBA::Long_out l2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  void test_octet (
      CORBA::Octet o1,
      CORBA::Octet_out o2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  void test_char (
      CORBA::Char c1,
      CORBA::Char_out c2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  void test_double (
      CORBA::Double d1,
      CORBA::Double_out d2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  void test_struct (
      const Marshal::Marshal_Struct & ms1,
      Marshal::Marshal_Struct_out ms2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  void test_union (
      const Marshal::Marshal_Union & u1,
      Marshal::Marshal_Union_out u2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  void test_any (
      const CORBA::Any & a1,
      CORBA::Any_out a2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  void test_sequence (
      const Marshal::AnySeq & as1,
      Marshal::AnySeq_out as2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  void test_recursive (
      const Marshal::Marshal_Recursive & mr1,
      Marshal::Marshal_Recursive_out mr2
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

private:
  T *ptr_;
  PortableServer::POA_var poa_;
  CORBA::Boolean rel_;
  
  // copy and assignment are not allowed
  POA_Marshal_tie (const POA_Marshal_tie &);
  void operator= (const POA_Marshal_tie &);
};


#include "marshalS_T.h"

#if defined (__ACE_INLINE__)
#include "marshalS.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* ifndef */
