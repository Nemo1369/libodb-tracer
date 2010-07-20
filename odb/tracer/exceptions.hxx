// file      : odb/tracer/exceptions.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2010 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_EXCEPTIONS_HXX
#define ODB_TRACER_EXCEPTIONS_HXX

#include <string>

#include <odb/exceptions.hxx>

namespace odb
{
  namespace tracer
  {
    struct database_exception: odb::database_exception
    {
      database_exception (const std::string&);
      ~database_exception () throw ();

      virtual char const*
      what () const throw ();

    private:
      std::string what_;
    };
  }
}

#endif // ODB_TRACER_EXCEPTIONS_HXX
