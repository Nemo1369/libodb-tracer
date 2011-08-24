// file      : odb/tracer/transaction-impl.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <iostream>

#include <odb/tracer/database.hxx>
#include <odb/tracer/connection.hxx>
#include <odb/tracer/transaction-impl.hxx>

using std::cout;
using std::endl;

namespace odb
{
  namespace tracer
  {
    transaction_impl::
    transaction_impl (database_type& db)
        : odb::transaction_impl (db), finalized_ (false)
    {
    }

    transaction_impl::
    transaction_impl (connection_ptr c)
        : odb::transaction_impl (c->database (), *c),
          finalized_ (false),
          connection_ (c)
    {
    }

    transaction_impl::
    ~transaction_impl ()
    {
      if (!finalized_)
        cout << "end transaction without commit/rollback" << endl;
    }

    void transaction_impl::
    start ()
    {
      // Grab a connection if we don't already have one.
      //
      if (connection_ == 0)
      {
        connection_ = static_cast<database_type&> (database_).connection ();
        odb::transaction_impl::connection_ = connection_.get ();
      }

      cout << "begin transaction" << endl;
    }

    void transaction_impl::
    commit ()
    {
      cout << "commit transaction" << endl;
      finalized_ = true;
    }

    void transaction_impl::
    rollback ()
    {
      cout << "rollback transaction" << endl;
      finalized_ = true;
    }
  }
}
