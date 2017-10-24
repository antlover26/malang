#ifndef MALANG_IR_IR_CALL_HPP
#define MALANG_IR_IR_CALL_HPP

#include <vector>
#include "ir.hpp"
#include "ir_values.hpp"

struct IR_Call : IR_RValue
{
    virtual ~IR_Call() {}
    IR_Call(const Source_Location &src_loc, struct IR_Value *callee, const std::vector<IR_Value*> &arguments)
        : IR_RValue(src_loc)
        , callee(callee)
        , arguments(std::move(arguments))
        {}
    virtual struct Type_Info *get_type() const override;
    struct Function_Type_Info *get_fn_type() const;
    IR_Value *callee;
    std::vector<IR_Value*> arguments;

    IR_NODE_OVERRIDES;
};

struct IR_Call_Method : IR_Call
{
    virtual ~IR_Call_Method() {}
    IR_Call_Method(const Source_Location &src_loc, struct IR_Value *callee, const std::vector<IR_Value*> &arguments)
        : IR_Call(src_loc, callee, arguments)
        {}
    IR_NODE_OVERRIDES;
};

struct IR_Call_Virtual_Method : IR_Call
{
    virtual ~IR_Call_Virtual_Method() {}
    IR_Call_Virtual_Method(const Source_Location &src_loc, struct IR_Value *callee, const std::vector<IR_Value*> &arguments)
        : IR_Call(src_loc, callee, arguments)
        {}
    IR_NODE_OVERRIDES;
};

struct IR_Allocate_Locals : IR_Node
{
    virtual ~IR_Allocate_Locals() {}
    IR_Allocate_Locals(const Source_Location &src_loc, uint16_t num_to_alloc)
        : IR_Node(src_loc)
        , num_to_alloc(num_to_alloc)
        {}

    uint16_t num_to_alloc;
    IR_NODE_OVERRIDES;
};

#endif /* MALANG_IR_IR_CALL_HPP */
