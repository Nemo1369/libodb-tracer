// file      : odb/tracer/forward.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2011 Code Synthesis Tools CC
// license   : GNU GPL v2; see accompanying LICENSE file

#ifndef ODB_TRACER_FORWARD_HXX
#define ODB_TRACER_FORWARD_HXX

#include <odb/pre.hxx>

#include <odb/forward.hxx>

namespace odb
{
  namespace tracer
  {
    class database;
    class connection;
    typedef details::shared_ptr<connection> connection_ptr;
    class transaction;
  }

  namespace details
  {
    template <>
    struct counter_type<tracer::connection>
    {
      typedef shared_base counter;
    };
  }
}

#include <odb/post.hxx>

#endif // ODB_TRACER_FORWARD_HXX
