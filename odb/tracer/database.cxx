// file      : odb/tracer/database.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2010 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/transaction.hxx>
#include <odb/tracer/database.hxx>

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
      if (odb::transaction::has_current ())
        throw already_in_transaction ();

      return new transaction_impl (*this);
    }
  }
}
