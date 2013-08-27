#ifndef SPYGLASS_POINT_H_
#define SPYGLASS_POINT_H_

#include "spyglass.h"

namespace Spyglass {
  namespace Point {
    void define_ruby_class();
    VALUE get_ruby_class();

    static VALUE rb_alloc(VALUE self);
    static void rb_free(cv::Point *point);
    static VALUE rb_initialize(VALUE self, VALUE x, VALUE y);
    static VALUE rb_get_x(VALUE self);
    static VALUE rb_get_y(VALUE self);
    static VALUE rb_set_x(VALUE self, VALUE x);
    static VALUE rb_set_y(VALUE self, VALUE y);

    VALUE point_from_cvrect(cv::Rect *rect);
  }
}

#endif
