#include <iostream>
#include <string>
#include <vector>

#include "../codering.hpp"
#include "lang_proc.hpp"

using namespace std;

vector<Gentleman::Function> std_fn () {
    vector<Gentleman::Function> fns;

    // Arguments
    Gentleman::Function_Argument func_arg0;  func_arg0.argument_name = "name";    func_arg0.argument_type  =   Gentleman::String;

    // Functions
    Gentleman::Function func;
    func.name = "func";
    func.return_type = Gentleman::Void;
    func.is_lambdad = true;
    func.collect_return_type = true;
    func.c_before_lambda = "{selected_type} {0}() {\n{lambda_code}";
    func.c_after_lambda = "}";
    func.function_arguments.push_back(func_arg0);

    fns.push_back(func);

    Gentleman::Function C;
    C.name = "C";
    C.return_type = Gentleman::Void;
    C.is_lambdad = true;
    C.c_code = "{lambda_code}";

    fns.push_back(C);

    return fns;
}
