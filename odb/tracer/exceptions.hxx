// file      : odb/tracer/exceptions.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_EXCEPTIONS_HXX
#define ODB_TRACER_EXCEPTIONS_HXX

#include <odb/pre.hxx>

#include <string>

#include <odb/exceptions.hxx>

#include <odb/tracer/details/export.hxx>

namespace odb
{
  namespace tracer
  {
    struct LIBODB_TRACER_EXPORT database_exception: odb::database_exception
    {
      database_exception (const std::string&);
      ~database_exception () throw ();

      virtual const char*
      what () const throw ();

    private:
      std::string what_;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_TRACER_EXCEPTIONS_HXX
