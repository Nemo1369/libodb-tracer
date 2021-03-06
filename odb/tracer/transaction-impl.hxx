// file      : odb/tracer/transaction-impl.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_TRANSACTION_IMPL_HXX
#define ODB_TRACER_TRANSACTION_IMPL_HXX

#include <odb/pre.hxx>

#include <odb/transaction.hxx>
#include <odb/details/shared-ptr.hxx>

#include <odb/tracer/forward.hxx>
#include <odb/tracer/details/export.hxx>

namespace odb
{
  namespace tracer
  {
    class LIBODB_TRACER_EXPORT transaction_impl: public odb::transaction_impl
    {
    public:
      typedef tracer::database database_type;

      transaction_impl (database_type&);
      transaction_impl (connection_ptr);

      virtual
      ~transaction_impl ();

      virtual void
      start ();

      virtual void
      commit ();

      virtual void
      rollback ();

    private:
      bool finalized_;
      connection_ptr connection_;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_TRACER_TRANSACTION_IMPL_HXX
