// file      : odb/tracer/transaction.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_TRANSACTION_HXX
#define ODB_TRACER_TRANSACTION_HXX

#include <odb/pre.hxx>

#include <odb/transaction.hxx>

#include <odb/tracer/details/export.hxx>

namespace odb
{
  namespace tracer
  {
    class database;
    class transaction_impl;

    class LIBODB_TRACER_EXPORT transaction: public odb::transaction
    {
    public:
      typedef odb::database database_type;

      explicit
      transaction (transaction_impl*);

      // Return the database this transaction is on.
      //
      database_type&
      database ();

      // Return current transaction or throw if there is no transaction
      // in effect.
      //
      static transaction&
      current ();

      // Set the current thread's transaction.
      //
      static void
      current (transaction&);

    public:
      transaction_impl&
      implementation ();
    };
  }
}

#include <odb/tracer/transaction.ixx>

#include <odb/post.hxx>

#endif // ODB_TRACER_TRANSACTION_HXX
