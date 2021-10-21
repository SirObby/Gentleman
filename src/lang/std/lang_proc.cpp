// Language Processor Classes, so on.

#include <iostream>
#include <string>
#include <vector>

#include "../codering.hpp"
#include "lang_proc.hpp"

std::string get_type_name(Gentleman::Types t) {
    switch (t)
    {
    case 0:
        return "char";
        break;
    case 1:
        return "signed char";
        break;
    case 2:
        return "unsigned char";
        break;
    case 3:
        return "short";
        break;
    case 4:
        return "short int";
        break;
    case 5:
        return "signed short";
        break;
    case 6:
        return "signed short int";
        break;
    case 7:
        return "unsigned short";
        break;
    case 8:
        return "usigned short int";
        break;
    case 9:
        return "int";
        break;
    case 10:
        return "signed int";
        break;
    case 11:
        return "unsigned";
        break;
    case 12:
        return "unsigned int";
        break;
    case 13:
        return "long";
        break;
    case 14:
        return "long int";
        break;
    case 15:
        return "signed long";
        break;
    case 16:
        return "signed long int";
        break;
    case 17:
        return "unsigned long";
        break;
    case 18:
        return "unsigned long int";
        break;
    case 19:
        return "long long";
        break;
    case 20:
        return "long long int";
        break;
    case 21:
        return "signed long long";
        break;
    case 22:
        return "signed long long int";
        break;
    case 23:
        return "unsigned long long";
        break;
    case 24:
        return "unsigned long long int";
        break;
    case 25:
        return "float";
        break;
    case 26:
        return "double";
        break;
    case 27:
        return "long double";
        break;
    case 28:
        return "string";
        break;
    case 29:
        return "void";
        break;
    default:
        return "unknown";
        break;
    }
}

std::string get_type_name(int t) {
    switch (t)
    {
    case 0:
        return "char";
        break;
    case 1:
        return "signed char";
        break;
    case 2:
        return "unsigned char";
        break;
    case 3:
        return "short";
        break;
    case 4:
        return "short int";
        break;
    case 5:
        return "signed short";
        break;
    case 6:
        return "signed short int";
        break;
    case 7:
        return "unsigned short";
        break;
    case 8:
        return "usigned short int";
        break;
    case 9:
        return "int";
        break;
    case 10:
        return "signed int";
        break;
    case 11:
        return "unsigned";
        break;
    case 12:
        return "unsigned int";
        break;
    case 13:
        return "long";
        break;
    case 14:
        return "long int";
        break;
    case 15:
        return "signed long";
        break;
    case 16:
        return "signed long int";
        break;
    case 17:
        return "unsigned long";
        break;
    case 18:
        return "unsigned long int";
        break;
    case 19:
        return "long long";
        break;
    case 20:
        return "long long int";
        break;
    case 21:
        return "signed long long";
        break;
    case 22:
        return "signed long long int";
        break;
    case 23:
        return "unsigned long long";
        break;
    case 24:
        return "unsigned long long int";
        break;
    case 25:
        return "float";
        break;
    case 26:
        return "double";
        break;
    case 27:
        return "long double";
        break;
    case 28:
        return "string";
        break;
    case 29:
        return "void";
        break;
    default:
        return "unknown";
        break;
    }
}