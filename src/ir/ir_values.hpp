#ifndef MALANG_IR_IR_VALUES_HPP
#define MALANG_IR_IR_VALUES_HPP

#include "ir.hpp"

struct IR_Value : IR_Node
{
    virtual struct IR_Type *get_type() const;
    virtual bool can_lvalue() const = 0;
    virtual bool can_rvalue() const = 0;
};

struct IR_LValue : IR_Value
{
    virtual bool can_lvalue() const final;
    virtual bool can_rvalue() const final;
    METADATA_OVERRIDES;
};

struct IR_RValue : IR_Value
{
    virtual bool can_lvalue() const final;
    virtual bool can_rvalue() const final;
    METADATA_OVERRIDES;
};

#endif /* MALANG_IR_IR_VALUES_HPP */
