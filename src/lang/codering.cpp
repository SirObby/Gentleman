#include <iostream>
#include <vector>
#include <string>

#include "codering.hpp"

using namespace std;

std::vector<Gentleman::Token> _handle_codering(std::string c)
{
    std::vector<Gentleman::Token> gt;

    struct lexer_stuff
    {
        bool comment = false;
        bool string = false;
        Gentleman::Token current_token;
        std::string str;
    } lexer_stuff;

    for (int i = 0; i < c.size(); i++)
    {

        bool handled = false;

        if (!(lexer_stuff.comment) && !(lexer_stuff.string))
        {

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

            if(c[i] == *"/" && c[i - 1] == *"*") {
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

            if (!handled)
            {
                cout << c[i] << "  ";
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