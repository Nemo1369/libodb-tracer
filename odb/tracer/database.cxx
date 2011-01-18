// file      : odb/tracer/database.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2009-2011 Code Synthesis Tools CC
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

    unsigned long long database::
    execute (const char*, std::size_t)
    {
      return 0;
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
