// file      : odb/tracer/exceptions.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2010 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#include <odb/tracer/exceptions.hxx>

using namespace std;

namespace odb
{
  namespace tracer
  {
    database_exception::
    ~database_exception () throw ()
    {
    }

    database_exception::
    database_exception (const string& what)
        : what_ (what)
    {
    }

    char const* database_exception::
    what () const throw ()
    {
      return what_.c_str ();
    }
  }
}
