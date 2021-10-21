#pragma once
// Language Processor Classes, so on.

#include <iostream>
#include <string>
#include <vector>

#include "../codering.hpp"

namespace Gentleman
{

    // Enums

    enum Types {
        Char,
        Signed_char,
        Unsigned_char,
        Short,
        Short_int,
        Signed_short,
        Signed_short_int,
        Unsigned_short,
        Unsigned_short_int,
        Int,
        Signed,
        Signed_int,
        Unsigned,
        Unsigned_int,
        Long,
        Long_int,
        Signed_long,
        Signed_long_int,
        Unsigned_long,
        Unsigned_long_int,
        Long_long,
        Long_long_int,
        Signed_long_long,
        Signed_long_long_int,
        Unsigned_long_long,
        Unsigned_long_long_int,
        Float,
        Double,
        Long_Double,
        String,
        Void
    };

    // Classes

    class Function_Argument {
    public:
        Types argument_type;
        std::string argument_name;
    };

    class Function
    {
    public:
        std::string name;
        bool collect_return_type = false; // < >'s
        bool is_lambdad = false; // { }'s
        Types return_type;
        std::string c_code = "";
        std::string c_before_lambda = "";
        std::string c_after_lambda = "";
        std::vector<Gentleman::Function_Argument> function_arguments;
    };
    
}