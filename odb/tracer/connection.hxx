// file      : odb/tracer/connection.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_CONNECTION_HXX
#define ODB_TRACER_CONNECTION_HXX

#include <odb/pre.hxx>

#include <odb/connection.hxx>
#include <odb/details/shared-ptr.hxx>

#include <odb/tracer/transaction-impl.hxx>
#include <odb/tracer/details/export.hxx>

namespace odb
{
  namespace tracer
  {
    class database;

    class connection;
    typedef details::shared_ptr<connection> connection_ptr;

    class LIBODB_TRACER_EXPORT connection: public odb::connection
    {
    public:
      typedef tracer::database database_type;

      connection (database_type&);

      virtual unsigned long long
      execute (const char* statement, std::size_t length);

      virtual transaction_impl*
      begin ();
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_TRACER_CONNECTION_HXX
