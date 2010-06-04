// file      : odb/tracer/transaction-impl.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2010 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_TRANSACTION_IMPL_HXX
#define ODB_TRACER_TRANSACTION_IMPL_HXX

#include <odb/transaction.hxx>

namespace odb
{
  namespace tracer
  {
    class database;
    class transaction;

    class transaction_impl: public odb::transaction_impl
    {
    protected:
      friend class database;
      friend class transaction;

      typedef tracer::database database_type;

      transaction_impl (database_type&);
      transaction_impl (database_type&, session_type&);

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

#endif // ODB_TRACER_TRANSACTION_IMPL_HXX
