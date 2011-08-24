// file      : odb/tracer/connection.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/transaction.hxx>

#include <odb/tracer/database.hxx>
#include <odb/tracer/connection.hxx>

namespace odb
{
  namespace tracer
  {
    connection::
    connection (database_type& db)
        : odb::connection (db)
    {
    }

    unsigned long long connection::
    execute (const char*, std::size_t)
    {
      return 0;
    }

    transaction_impl* connection::
    begin ()
    {
      return new transaction_impl (connection_ptr (inc_ref (this)));
    }
  }
}
