#pragma once

#include <iostream>
#include <vector>

namespace Gentleman
{
enum Token_Type{
    COMMENT_BLOCK_START, //  /*
    COMMENT_BLOCK_END, // */
    COMMENT_LINE, // //
    NEWLINE, // \n
    FUNCTION,
    VARIABLE,
    VARIABLE_NAME,
    VARIABLE_VALUE,
    UNHANDLED, // sus.
    TARGET_TYPE_START, // <
    TARGET_TYPE_END, // >
    EQUALS, // =
    NOT_EQUALS_TO, // !=
    GREATER_THAN, // >
    GREATER_THAN_OR_EQUAL, // >=
    LESS_THAN, // <
    LESS_THAN_OR_EQUAL // =<
};

class Token
{
private:
public:
    Token_Type type;
    Token();
};
}

std::vector<Gentleman::Token> _handle_codering(std::string c);