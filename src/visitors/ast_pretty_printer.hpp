#ifndef AST_PRETTY_PRINTER_H
#define AST_PRETTY_PRINTER_H

#include <string>
#include <sstream>
#include <vector>
#include "../ast/ast_visitor.hpp"

struct Ast_Pretty_Printer : Ast_Visitor
{
    Ast_Pretty_Printer()
        : indent_level(0)
        {}
    virtual void visit(struct Import_Node&) override;
    virtual void visit(struct Variable_Node&) override;
    virtual void visit(struct Assign_Node&) override;
    virtual void visit(struct Decl_Node&) override;
    virtual void visit(struct Fn_Node&) override;
    virtual void visit(struct List_Node&) override;
    virtual void visit(struct Integer_Node&) override;
    virtual void visit(struct Real_Node&) override;
    virtual void visit(struct String_Node&) override;
    virtual void visit(struct Boolean_Node&) override;
    virtual void visit(struct Character_Node&) override;
    virtual void visit(struct Logical_Or_Node&) override;
    virtual void visit(struct Logical_And_Node&) override;
    virtual void visit(struct Inclusive_Or_Node&) override;
    virtual void visit(struct Exclusive_Or_Node&) override;
    virtual void visit(struct And_Node&) override;
    virtual void visit(struct Equals_Node&) override;
    virtual void visit(struct Not_Equals_Node&) override;
    virtual void visit(struct Less_Than_Node&) override;
    virtual void visit(struct Less_Than_Equals_Node&) override;
    virtual void visit(struct Greater_Than_Node&) override;
    virtual void visit(struct Greater_Than_Equals_Node&) override;
    virtual void visit(struct Left_Shift_Node&) override;
    virtual void visit(struct Right_Shift_Node&) override;
    virtual void visit(struct Add_Node&) override;
    virtual void visit(struct Subtract_Node&) override;
    virtual void visit(struct Multiply_Node&) override;
    virtual void visit(struct Divide_Node&) override;
    virtual void visit(struct Modulo_Node&) override;
    virtual void visit(struct Call_Node&) override;
    virtual void visit(struct Index_Node&) override;
    virtual void visit(struct Member_Accessor_Node&) override;
    virtual void visit(struct Negate_Node&) override;
    virtual void visit(struct Positive_Node&) override;
    virtual void visit(struct Not_Node&) override;
    virtual void visit(struct Invert_Node&) override;
    virtual void visit(struct Constructor_Node&) override;
    virtual void visit(struct Type_Def_Node&) override;
    virtual void visit(struct Type_Alias_Node&) override;
    virtual void visit(struct Unalias_Node&) override;
    virtual void visit(struct Extend_Node&) override;
    virtual void visit(struct Type_Node&) override;
    virtual void visit(struct Decl_Assign_Node&) override;
    virtual void visit(struct Return_Node&) override;
    virtual void visit(struct Break_Node&) override;
    virtual void visit(struct Continue_Node&) override;
    virtual void visit(struct While_Node&) override;
    virtual void visit(struct For_Node&) override;
    virtual void visit(struct If_Else_Node&) override;
    virtual void visit(struct Array_Literal_Node&) override;
    virtual void visit(struct New_Array_Node&) override;

    std::vector<std::string> to_strings(struct Ast &ast);
    std::string to_string(struct Ast_Node &n);
    void reset();
private:
    int indent_level;
    void indent();
    void dedent();
    void do_indention();
    void do_body(const std::vector<Ast_Node*> &body);
    std::stringstream str;
};

#endif /* AST_PRETTY_PRINTER_H */
