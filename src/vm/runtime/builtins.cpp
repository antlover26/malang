#include <string>
#include <sstream>
#include "builtins.hpp"
#include "../../type_map.hpp"
#include "../vm.hpp"
#include "../runtime.hpp"

#include <stdio.h>

static
void println_int(Malang_VM &vm)
{
    auto top = vm.pop_data().as_fixnum();
    printf("%d\n", top);
}

static
void println_object(Malang_VM &vm)
{
    auto top = vm.pop_data().as_object();
    printf("%s\n", top->type->name().c_str());
}

static
void println_buffer(Malang_VM &vm)
{
    auto top = vm.pop_data().as_object();
    assert(top->object_tag == Buffer);
    auto buffer = reinterpret_cast<Malang_Buffer*>(top);
    printf("%.*s\n", buffer->size, buffer->data);
}

static
void println_double(Malang_VM &vm)
{
    auto top = vm.pop_data().as_double();
    printf("%lf\n", top);
}

static
void println_bool(Malang_VM &vm)
{
    auto top = vm.pop_data().as_fixnum();
    if (top == 0)
        printf("false\n");
    else
        printf("true\n");
}

static
void println_string(Malang_VM &vm)
{
    static bool once = true;
    static uint16_t length_idx = 0, intern_data_idx = 0;
    if (once)
    {
        auto str_ty = vm.gc->types()->get_string();
        if (!str_ty->get_field_index("length", length_idx))
        {
            printf("no length field in strings ???\n");
            abort();
        }
        if (!str_ty->get_field_index(".intern_data", intern_data_idx))
        {
            printf("no .intern_data field in strings ???\n");
            abort();
        }
        once = false;
    }

    auto top = vm.pop_data().as_object();
    auto string = reinterpret_cast<Malang_Object_Body*>(top);
    auto len = string->fields[length_idx].as_fixnum();
    auto data = string->fields[intern_data_idx].as_pointer();
    printf("%.*s\n", len, static_cast<char*>(data));
}

static
void stack_trace(Malang_VM &vm)
{
    vm.stack_trace();
}

static
void gc_pause(Malang_VM &vm)
{
    vm.gc->disable_automatic();
}
static
void gc_resume(Malang_VM &vm)
{
    vm.gc->enable_automatic();
}
static
void gc_run(Malang_VM &vm)
{
    vm.gc->manual_run();
}

static
void breakpoint(Malang_VM &vm)
{
    vm.breaking = true;
}


void make_builtin(Bound_Function_Map &b, Type_Map &t, const std::string &name, Native_Code native_code, const std::vector<Type_Info*> &param_types, Type_Info *return_type)
{
    Function_Type_Info *fn;
    const auto is_native = true;
    fn = t.declare_function(param_types, return_type, is_native);
    b.add(name, fn, native_code);
}

void Malang_Runtime::runtime_builtins_init(Bound_Function_Map &b, Type_Map &t)
{
    make_builtin(b, t, "println", println_int,    {t.get_int()}, t.get_void());
    make_builtin(b, t, "println", println_bool,   {t.get_bool()}, t.get_void());
    //make_builtib(p, t, "println", println_string, {t.get_string()}, t.get_void());
    make_builtin(b, t, "println", println_object, {t.get_object()}, t.get_void());
    make_builtin(b, t, "println", println_double, {t.get_double()}, t.get_void());
    make_builtin(b, t, "println", println_buffer, {t.get_buffer()}, t.get_void());
    make_builtin(b, t, "println", println_string, {t.get_string()}, t.get_void());

    make_builtin(b, t, "stack_trace", stack_trace, {}, t.get_void());
    make_builtin(b, t, "gc_pause",    gc_pause,    {}, t.get_void());
    make_builtin(b, t, "gc_resume",   gc_resume,   {}, t.get_void());
    make_builtin(b, t, "gc_run",      gc_run,      {}, t.get_void());
    make_builtin(b, t, "breakpoint",  breakpoint,      {}, t.get_void());
}
