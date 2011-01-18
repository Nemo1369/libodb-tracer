// file      : odb/tracer/database.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_DATABASE_HXX
#define ODB_TRACER_DATABASE_HXX

#include <odb/pre.hxx>

#include <odb/database.hxx>
#include <odb/tracer/transaction-impl.hxx>

#include <odb/tracer/details/export.hxx>

namespace odb
{
  namespace tracer
  {
    class LIBODB_TRACER_EXPORT database: public odb::database
    {
    public:
      virtual
      ~database ();

      virtual unsigned long long
      execute (const char* statement, std::size_t length);

      virtual transaction_impl*
      begin ();
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_TRACER_DATABASE_HXX
