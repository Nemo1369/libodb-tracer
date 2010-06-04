// file      : odb/tracer/transaction.ixx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2010 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/tracer/database.hxx>
#include <odb/tracer/transaction-impl.hxx>

namespace odb
{
  namespace tracer
  {
    inline transaction::
    transaction (transaction_impl* impl)
        : odb::transaction (impl)
    {
    }

    inline transaction::database_type& transaction::
    database ()
    {
      return static_cast<database_type&> (odb::transaction::database ());
    }

    inline transaction_impl& transaction::
    implementation ()
    {
      // We can use static_cast here since we have an instance of
      // tracer::transaction.
      //
      return static_cast<transaction_impl&> (
        odb::transaction::implementation ());
    }
  }
}
