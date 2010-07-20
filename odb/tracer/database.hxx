// file      : odb/tracer/database.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2010 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_DATABASE_HXX
#define ODB_TRACER_DATABASE_HXX

#include <odb/database.hxx>
#include <odb/tracer/transaction-impl.hxx>

namespace odb
{
  namespace tracer
  {
    class database: public odb::database
    {
    public:
      virtual
      ~database ();

      virtual transaction_impl*
      begin_transaction ();
    };
  }
}

#endif // ODB_TRACER_DATABASE_HXX
