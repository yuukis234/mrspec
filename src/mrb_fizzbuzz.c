/*
** mrb_fizzbuzz.c - FizzBuzz class
**
** Copyright (c) kiryuu eizi 2019
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_fizzbuzz.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  mrb_int len;
} mrb_fizzbuzz_data;

static const struct mrb_data_type mrb_fizzbuzz_data_type = {
  "mrb_fizzbuzz_data", mrb_free,
};

static mrb_value mrb_fizzbuzz_init(mrb_state *mrb, mrb_value self)
{
  mrb_fizzbuzz_data *data;
  char *str;
  mrb_int len;

  data = (mrb_fizzbuzz_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_fizzbuzz_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_fizzbuzz_data *)mrb_malloc(mrb, sizeof(mrb_fizzbuzz_data));
  data->str = str;
  data->len = len;
  DATA_PTR(self) = data;

  return self;
}

static mrb_value mrb_fizzbuzz_hello(mrb_state *mrb, mrb_value self)
{
  mrb_fizzbuzz_data *data = DATA_PTR(self);

  return mrb_str_new(mrb, data->str, data->len);
}

static mrb_value mrb_fizzbuzz_hi(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "hi!!");
}

void mrb_mrspec_gem_init(mrb_state *mrb)
{
  struct RClass *fizzbuzz;
  fizzbuzz = mrb_define_class(mrb, "FizzBuzz", mrb->object_class);
  mrb_define_method(mrb, fizzbuzz, "initialize", mrb_fizzbuzz_init, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, fizzbuzz, "hello", mrb_fizzbuzz_hello, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, fizzbuzz, "hi", mrb_fizzbuzz_hi, MRB_ARGS_NONE());
  DONE;
}

void mrb_mrspec_gem_final(mrb_state *mrb)
{
}

