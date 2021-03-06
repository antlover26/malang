#ifndef AST_VISITOR_H
#define AST_VISITOR_H

struct Ast_Visitor
{
    virtual ~Ast_Visitor() {}
    virtual void visit(struct Import_Node&) = 0;
    virtual void visit(struct Variable_Node&) = 0;
    virtual void visit(struct Assign_Node&) = 0;
    virtual void visit(struct Decl_Node&) = 0;
    virtual void visit(struct Fn_Node&) = 0;
    virtual void visit(struct List_Node&) = 0;
    virtual void visit(struct Integer_Node&) = 0;
    virtual void visit(struct Real_Node&) = 0;
    virtual void visit(struct String_Node&) = 0;
    virtual void visit(struct Boolean_Node&) = 0;
    virtual void visit(struct Character_Node&) = 0;
    virtual void visit(struct Logical_Or_Node&) = 0;
    virtual void visit(struct Logical_And_Node&) = 0;
    virtual void visit(struct Inclusive_Or_Node&) = 0;
    virtual void visit(struct Exclusive_Or_Node&) = 0;
    virtual void visit(struct And_Node&) = 0;
    virtual void visit(struct Equals_Node&) = 0;
    virtual void visit(struct Not_Equals_Node&) = 0;
    virtual void visit(struct Less_Than_Node&) = 0;
    virtual void visit(struct Less_Than_Equals_Node&) = 0;
    virtual void visit(struct Greater_Than_Node&) = 0;
    virtual void visit(struct Greater_Than_Equals_Node&) = 0;
    virtual void visit(struct Left_Shift_Node&) = 0;
    virtual void visit(struct Right_Shift_Node&) = 0;
    virtual void visit(struct Add_Node&) = 0;
    virtual void visit(struct Subtract_Node&) = 0;
    virtual void visit(struct Multiply_Node&) = 0;
    virtual void visit(struct Divide_Node&) = 0;
    virtual void visit(struct Modulo_Node&) = 0;
    virtual void visit(struct Call_Node&) = 0;
    virtual void visit(struct Index_Node&) = 0;
    virtual void visit(struct Member_Accessor_Node&) = 0;
    virtual void visit(struct Negate_Node&) = 0;
    virtual void visit(struct Positive_Node&) = 0;
    virtual void visit(struct Not_Node&) = 0;
    virtual void visit(struct Invert_Node&) = 0;
    virtual void visit(struct Type_Def_Node&) = 0;
    virtual void visit(struct Type_Alias_Node&) = 0;
    virtual void visit(struct Unalias_Node&) = 0;
    virtual void visit(struct Extend_Node&) = 0;
    virtual void visit(struct Constructor_Node&) = 0;
    virtual void visit(struct Type_Node&) = 0;
    virtual void visit(struct Decl_Assign_Node&) = 0;
    virtual void visit(struct Return_Node&) = 0;
    virtual void visit(struct Break_Node&) = 0;
    virtual void visit(struct Continue_Node&) = 0;
    virtual void visit(struct While_Node&) = 0;
    virtual void visit(struct For_Node&) = 0;
    virtual void visit(struct If_Else_Node&) = 0;
    virtual void visit(struct Array_Literal_Node&) = 0;
    virtual void visit(struct New_Array_Node&) = 0;
};

#endif /* AST_VISITOR_H */
