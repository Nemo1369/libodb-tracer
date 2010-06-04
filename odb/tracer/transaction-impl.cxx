// file      : odb/tracer/transaction-impl.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2010 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <iostream>

#include <odb/tracer/database.hxx>
#include <odb/tracer/transaction-impl.hxx>

using std::cout;
using std::endl;

namespace odb
{
  namespace tracer
  {
    transaction_impl::
    transaction_impl (database_type& db)
        : odb::transaction_impl (db), finilized_ (false)
    {
      cout << "begin transaction" << endl;
    }

    transaction_impl::
    transaction_impl (database_type& db, session_type& s)
        : odb::transaction_impl (db, s), finilized_ (false)
    {
      cout << "begin transaction" << endl;
    }

    transaction_impl::
    ~transaction_impl ()
    {
      if (!finilized_)
        cout << "end transaction without commit/rollback" << endl;
    }

    void transaction_impl::
    commit ()
    {
      cout << "commit transaction" << endl;
      finilized_ = true;
    }

    void transaction_impl::
    rollback ()
    {
      cout << "rollback transaction" << endl;
      finilized_ = true;
    }
  }
}
