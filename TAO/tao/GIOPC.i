/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

// *************************************************************
// Inline operations for class GIOP::IORAddressingInfo_var
// *************************************************************

ACE_INLINE
GIOP::IORAddressingInfo_var::IORAddressingInfo_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
GIOP::IORAddressingInfo_var::IORAddressingInfo_var (GIOP::IORAddressingInfo *p)
  : ptr_ (p)
{}

ACE_INLINE
GIOP::IORAddressingInfo_var::IORAddressingInfo_var (const GIOP::IORAddressingInfo_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, GIOP::IORAddressingInfo (*p.ptr_));
  else
    this->ptr_ = 0;
}

ACE_INLINE
GIOP::IORAddressingInfo_var::~IORAddressingInfo_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE GIOP::IORAddressingInfo_var &
GIOP::IORAddressingInfo_var::operator= (GIOP::IORAddressingInfo *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE GIOP::IORAddressingInfo_var &
GIOP::IORAddressingInfo_var::operator= (const GIOP::IORAddressingInfo_var &p)
{
  if (this != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (this->ptr_, GIOP::IORAddressingInfo (*p.ptr_), *this);
  }
  return *this;
}

ACE_INLINE const GIOP::IORAddressingInfo *
GIOP::IORAddressingInfo_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE GIOP::IORAddressingInfo *
GIOP::IORAddressingInfo_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
GIOP::IORAddressingInfo_var::operator const GIOP::IORAddressingInfo &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
GIOP::IORAddressingInfo_var::operator GIOP::IORAddressingInfo &() // cast
{
  return *this->ptr_;
}

ACE_INLINE
GIOP::IORAddressingInfo_var::operator GIOP::IORAddressingInfo &() const// cast
{
  return *this->ptr_;
}

ACE_INLINE const GIOP::IORAddressingInfo &
GIOP::IORAddressingInfo_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE GIOP::IORAddressingInfo &
GIOP::IORAddressingInfo_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size
ACE_INLINE GIOP::IORAddressingInfo *&
GIOP::IORAddressingInfo_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE GIOP::IORAddressingInfo *
GIOP::IORAddressingInfo_var::_retn (void)
{
  GIOP::IORAddressingInfo *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE GIOP::IORAddressingInfo *
GIOP::IORAddressingInfo_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class GIOP::IORAddressingInfo_out
// *************************************************************

ACE_INLINE
GIOP::IORAddressingInfo_out::IORAddressingInfo_out (GIOP::IORAddressingInfo *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
GIOP::IORAddressingInfo_out::IORAddressingInfo_out (GIOP::IORAddressingInfo_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
GIOP::IORAddressingInfo_out::IORAddressingInfo_out (const GIOP::IORAddressingInfo_out &p) // copy constructor
  : ptr_ (ACE_const_cast (GIOP::IORAddressingInfo_out&,p).ptr_)
{}

ACE_INLINE GIOP::IORAddressingInfo_out &
GIOP::IORAddressingInfo_out::operator= (const GIOP::IORAddressingInfo_out &p)
{
  this->ptr_ = ACE_const_cast (GIOP::IORAddressingInfo_out&,p).ptr_;
  return *this;
}

ACE_INLINE GIOP::IORAddressingInfo_out &
GIOP::IORAddressingInfo_out::operator= (GIOP::IORAddressingInfo *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
GIOP::IORAddressingInfo_out::operator GIOP::IORAddressingInfo *&() // cast
{
  return this->ptr_;
}

ACE_INLINE GIOP::IORAddressingInfo *&
GIOP::IORAddressingInfo_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE GIOP::IORAddressingInfo *
GIOP::IORAddressingInfo_out::operator-> (void)
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for union GIOP::TargetAddress
// *************************************************************

// destructor
ACE_INLINE
GIOP::TargetAddress::~TargetAddress (void)
{
  // finalize
  this->_reset (this->disc_, 1);
}

// this reset method is used by the decoding engine
ACE_INLINE void
GIOP::TargetAddress::_reset (void)
{
  this->_reset (this->disc_, 1);
  ACE_OS::memcpy (&this->u_, 0, sizeof (this->u_));
}

// the implicit _default () method
ACE_INLINE void
GIOP::TargetAddress::_default ()
{
  this->disc_ = -32768;
}

// accessor to set the discriminant
ACE_INLINE void
GIOP::TargetAddress::_d (CORBA::Short discval)
{
  this->disc_ = discval;
}
// accessor to get the discriminant
ACE_INLINE CORBA::Short
GIOP::TargetAddress::_d (void) const
{
  return this->disc_;
}


// accessor to set the member
ACE_INLINE void
GIOP::TargetAddress::object_key (const TAO_ObjectKey &val)
{
  // set the discriminant val
  this->_reset (0, 0);
  this->disc_ = 0;
  ACE_NEW (
      this->u_.object_key_,
      TAO_ObjectKey (val)
    );
}

// readonly get method
ACE_INLINE const TAO_ObjectKey &
GIOP::TargetAddress::object_key (void) const
{
  return *this->u_.object_key_;
}

// read/write get method
ACE_INLINE TAO_ObjectKey &
GIOP::TargetAddress::object_key (void)
{
  return *this->u_.object_key_;
}

// accessor to set the member
ACE_INLINE void
GIOP::TargetAddress::profile (const IOP::TaggedProfile &val)
{
  // set the discriminant val
  this->_reset (1, 0);
  this->disc_ = 1;
  ACE_NEW (
      this->u_.profile_,
      IOP::TaggedProfile (val)
    );
}

// readonly get method
ACE_INLINE const IOP::TaggedProfile &
GIOP::TargetAddress::profile (void) const
{
  return *this->u_.profile_;
}

// read/write get method
ACE_INLINE IOP::TaggedProfile &
GIOP::TargetAddress::profile (void)
{
  return *this->u_.profile_;
}

// accessor to set the member
ACE_INLINE void
GIOP::TargetAddress::ior (const GIOP::IORAddressingInfo &val)
{
  // set the discriminant val
  this->_reset (2, 0);
  this->disc_ = 2;
  ACE_NEW (
      this->u_.ior_,
      GIOP::IORAddressingInfo (val)
    );
}

// readonly get method
ACE_INLINE const GIOP::IORAddressingInfo &
GIOP::TargetAddress::ior (void) const
{
  return *this->u_.ior_;
}

// read/write get method
ACE_INLINE GIOP::IORAddressingInfo &
GIOP::TargetAddress::ior (void)
{
  return *this->u_.ior_;
}


#if !defined (_GIOP_TARGETADDRESS___VAR_CI_)
#define _GIOP_TARGETADDRESS___VAR_CI_

// *************************************************************
// Inline operations for class GIOP::TargetAddress_var
// *************************************************************

ACE_INLINE
GIOP::TargetAddress_var::TargetAddress_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
GIOP::TargetAddress_var::TargetAddress_var (GIOP::TargetAddress *p)
  : ptr_ (p)
{}

ACE_INLINE
GIOP::TargetAddress_var::TargetAddress_var (const GIOP::TargetAddress_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, GIOP::TargetAddress (*p.ptr_));
  else
    this->ptr_ = 0;
}

ACE_INLINE
GIOP::TargetAddress_var::~TargetAddress_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE GIOP::TargetAddress_var &
GIOP::TargetAddress_var::operator= (GIOP::TargetAddress *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE GIOP::TargetAddress_var &
GIOP::TargetAddress_var::operator= (const GIOP::TargetAddress_var &p)
{
  if (this != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (this->ptr_, GIOP::TargetAddress (*p.ptr_), *this);
  }
  return *this;
}

ACE_INLINE const GIOP::TargetAddress *
GIOP::TargetAddress_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE GIOP::TargetAddress *
GIOP::TargetAddress_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
GIOP::TargetAddress_var::operator const GIOP::TargetAddress &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
GIOP::TargetAddress_var::operator GIOP::TargetAddress &() // cast
{
  return *this->ptr_;
}

ACE_INLINE
GIOP::TargetAddress_var::operator GIOP::TargetAddress &() const// cast
{
  return *this->ptr_;
}

ACE_INLINE const GIOP::TargetAddress &
GIOP::TargetAddress_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE GIOP::TargetAddress &
GIOP::TargetAddress_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size
ACE_INLINE GIOP::TargetAddress *&
GIOP::TargetAddress_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE GIOP::TargetAddress *
GIOP::TargetAddress_var::_retn (void)
{
  GIOP::TargetAddress *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE GIOP::TargetAddress *
GIOP::TargetAddress_var::ptr (void) const
{
  return this->ptr_;
}


#endif /* end #if !defined */


#if !defined (_GIOP_TARGETADDRESS___OUT_CI_)
#define _GIOP_TARGETADDRESS___OUT_CI_

// *************************************************************
// Inline operations for class GIOP::TargetAddress_out
// *************************************************************

ACE_INLINE
GIOP::TargetAddress_out::TargetAddress_out (GIOP::TargetAddress *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
GIOP::TargetAddress_out::TargetAddress_out (GIOP::TargetAddress_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
GIOP::TargetAddress_out::TargetAddress_out (const GIOP::TargetAddress_out &p) // copy constructor
  : ptr_ (ACE_const_cast (GIOP::TargetAddress_out&,p).ptr_)
{}

ACE_INLINE GIOP::TargetAddress_out &
GIOP::TargetAddress_out::operator= (const GIOP::TargetAddress_out &p)
{
  this->ptr_ = ACE_const_cast (GIOP::TargetAddress_out&,p).ptr_;
  return *this;
}

ACE_INLINE GIOP::TargetAddress_out &
GIOP::TargetAddress_out::operator= (GIOP::TargetAddress *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
GIOP::TargetAddress_out::operator GIOP::TargetAddress *&() // cast
{
  return this->ptr_;
}

ACE_INLINE GIOP::TargetAddress *&
GIOP::TargetAddress_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE GIOP::TargetAddress *
GIOP::TargetAddress_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */


ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const GIOP::IORAddressingInfo &_tao_aggregate)
{
  if (
    (strm << _tao_aggregate.selected_profile_index) &&
    (strm << _tao_aggregate.ior)
  )
    return 1;
  else
    return 0;

}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, GIOP::IORAddressingInfo &_tao_aggregate)
{
  if (
    (strm >> _tao_aggregate.selected_profile_index) &&
    (strm >> _tao_aggregate.ior)
  )
    return 1;
  else
    return 0;

}


ACE_INLINE CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const GIOP::TargetAddress &_tao_union
  )
{
  if ( !(strm << _tao_union._d ()) )
    {
      return 0;
    }
  CORBA::Boolean result = 1;
  switch (_tao_union._d ())
  {
    case 0:
      {
        result = strm << _tao_union.object_key ();
      }
      break;
    case 1:
      {
        result = strm << _tao_union.profile ();
      }
      break;
    case 2:
      {
        result = strm << _tao_union.ior ();
      }
      break;
    default:
      break;
  }
  return result;
}

ACE_INLINE CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    GIOP::TargetAddress &_tao_union
  )
{
  CORBA::Short _tao_discriminant;
  if ( !(strm >> _tao_discriminant) )
    {
      return 0;
    }
  CORBA::Boolean result = 1;
  switch (_tao_discriminant)
  {
    case 0:
      {
        TAO_ObjectKey _tao_union_tmp;
        result = strm >> _tao_union_tmp;
        if (result)
          _tao_union.object_key (_tao_union_tmp);
      }
      break;
    case 1:
      {
        IOP::TaggedProfile _tao_union_tmp;
        result = strm >> _tao_union_tmp;
        if (result)
          _tao_union.profile (_tao_union_tmp);
      }
      break;
    case 2:
      {
        GIOP::IORAddressingInfo _tao_union_tmp;
        result = strm >> _tao_union_tmp;
        if (result)
          _tao_union.ior (_tao_union_tmp);
      }
      break;
    default:
      _tao_union._d (_tao_discriminant);
      break;
  }
  return result;
}
