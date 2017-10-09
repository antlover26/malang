#include <stdio.h>
#include <sstream>
#include "ast_decl.hpp"

Decl_Node::~Decl_Node()
{
    PRINT_DTOR;
}
std::string Decl_Node::to_string() const
{
    std::stringstream ss;
    ss << variable_name << " :";
    if (type)
    {
        ss << " " << type->name();
    }
    return ss.str();
}
METADATA_OVERRIDES_IMPL(Decl_Node);
