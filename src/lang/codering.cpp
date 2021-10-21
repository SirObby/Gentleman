#include <iostream>
#include <vector>
#include <string>

#include "codering.hpp"
#include "std/base.hpp"
#include "std/lang_proc.hpp"

using namespace std;

std::vector<Gentleman::Token> _handle_codering(std::string c)
{
    std::vector<Gentleman::Token> gt;

    struct lexer_stuff
    {
        bool comment = false;
        bool string = false;
        bool get_type = false;
        bool get_args = false;
        Gentleman::Token current_token;
        std::string str;
        std::string pre_token;
        std::string lambda_code;
        std::string argument_0;
        std::string captured_type;
        int argument_count = 0;

        // What standard function are we running?
        bool unknown_command = true;
        bool external_command = false;

        bool _func = false;

        // What standard function arguments?

        std::string _func_name = "";

    } lexer_stuff;

    for (int i = 0; i < c.size(); i++)
    {

        bool handled = false;

        if (!(lexer_stuff.comment) && !(lexer_stuff.string))
        {

            // Removing garbage.
            std::string filtered_pre_token = "";

            for (size_t i2 = 0; i2 < lexer_stuff.pre_token.size(); i2++)
            {
                if (!(lexer_stuff.pre_token[i2] == *"") && !(lexer_stuff.pre_token[i2] == *" "))
                {
                    filtered_pre_token += lexer_stuff.pre_token[i2];
                }
            }

            // Handling comments
            if (c[i] == *"/" && c[i + 1] == *"*")
            {
                lexer_stuff.current_token.type = Gentleman::Token_Type::COMMENT_BLOCK_START;
                lexer_stuff.comment = true;
                handled = true;

                gt.push_back(lexer_stuff.current_token);
                lexer_stuff.current_token = Gentleman::Token();
            }

            if (c[i] == *"*" && c[i - 1] == *"/")
            {
                handled = true;
            }

            if (c[i] == *"/" && c[i - 1] == *"*")
            {
                handled = true;
            }

            // Handling strings
            if (c[i] == *"\"")
            {
                handled = true;
                lexer_stuff.string = true;
            }

            // Handling newlines.
            if (c[i] == *"\n")
            { // Newlines do not affect tokenizing. They are "ignored", but "handled".
                handled = true;
                cout << "\n"; // Debugging, makes unhandled pre_tokens look nicer.
            }

            // Capturing <type>

            if (lexer_stuff.get_type && c[i] == *">")
            {
                lexer_stuff.captured_type = filtered_pre_token;
                lexer_stuff.pre_token = "";
            }

            if (c[i - 1] == *"<")
            {
                lexer_stuff.pre_token = "";
                lexer_stuff.get_type = true;
            }

            // Capturing (arguments). 

            if(c[i - 1] == *"(") {
                lexer_stuff.pre_token = "";
                lexer_stuff.get_args = true;
                lexer_stuff.argument_count = 0;
            }

            if(c[i - 1] == *")") {
                
            }

            /*
            Handling functions and running functions.
            Also, reading THIS part of the code, will make you insane.
            */

            if (filtered_pre_token == "func")
            {
                lexer_stuff._func = true;
                lexer_stuff._func_name = "";
            }

            if(lexer_stuff._func) {
                if(lexer_stuff.get_args && lexer_stuff._func_name == "") {
                    lexer_stuff._func_name = filtered_pre_token;
                    cout << "Function name: " <<  lexer_stuff._func_name << "\n";
                }
            }

            if (!handled)
            {
                lexer_stuff.pre_token += c[i];
                cout << filtered_pre_token << "\n";
                //cout << c[i];
            }
        }
        else
        {

            if (lexer_stuff.comment)
            {
                if (c[i] == *"*" && c[i + 1] == *"/")
                {
                    lexer_stuff.current_token.type = Gentleman::Token_Type::COMMENT_BLOCK_END;
                    lexer_stuff.comment = false;

                    gt.push_back(lexer_stuff.current_token);
                    lexer_stuff.current_token = Gentleman::Token();
                }
            }

            if (lexer_stuff.string)
            {
                if (c[i] == *"\"")
                {
                    lexer_stuff.string = false;
                }
                else
                {
                    lexer_stuff.str += c[i];
                }
            }
        }

        /*if (!(handled))
        {
            string m = "Sire, we have found that the following pre_token was not handled: " + c[i];
            cout << m;
            break;
        }*/
    }

    return gt;
};

Gentleman::Token::Token()
{
    Token::type = Gentleman::Token_Type::UNHANDLED;
}