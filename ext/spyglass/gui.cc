#include "gui.h"

static VALUE GuiModule;

namespace Spyglass {
  namespace GUI {
    void define_ruby_module() {
      GuiModule = rb_define_module_under(Spyglass::get_ruby_module(), "GUI");

      // Module methods
      rb_define_singleton_method(GuiModule, "wait_key", RUBY_METHOD_FUNC(rb_wait_key), 1);
    }

    VALUE get_ruby_module() {
      return GuiModule;
    }

    static VALUE rb_wait_key(VALUE klass, VALUE timeout) {
      Check_Type(timeout, T_FIXNUM);

      int msecs = FIX2INT(timeout);
      int key = cv::waitKey(msecs);

      return INT2FIX(key);
    }
  }
}
