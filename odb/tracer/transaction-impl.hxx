// file      : odb/tracer/transaction-impl.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2010 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_TRANSACTION_IMPL_HXX
#define ODB_TRACER_TRANSACTION_IMPL_HXX

#include <odb/pre.hxx>

#include <odb/transaction.hxx>

#include <odb/tracer/details/export.hxx>

namespace odb
{
  namespace tracer
  {
    class database;
    class transaction;

    class LIBODB_TRACER_EXPORT transaction_impl: public odb::transaction_impl
    {
    protected:
      friend class database;
      friend class transaction;

      typedef tracer::database database_type;

      transaction_impl (database_type&);

      virtual
      ~transaction_impl ();

      virtual void
      commit ();

      virtual void
      rollback ();

    private:
      bool finilized_;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_TRACER_TRANSACTION_IMPL_HXX
