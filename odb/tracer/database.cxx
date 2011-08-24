// file      : odb/tracer/database.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/tracer/database.hxx>
#include <odb/tracer/connection.hxx>

namespace odb
{
  namespace tracer
  {
    database::
    ~database ()
    {
    }

    transaction_impl* database::
    begin ()
    {
      return new transaction_impl (*this);
    }

    connection_ptr database::
    connection ()
    {
      // Go through the virtual connection_() function instead of
      // directly to allow overriding.
      //
      return connection_ptr (
        static_cast<tracer::connection*> (connection_ ()));
    }

    odb::connection* database::
    connection_ ()
    {
      return new (details::shared) connection_type (*this);
    }
  }
}
