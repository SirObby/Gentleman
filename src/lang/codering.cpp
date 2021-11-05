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

    typedef struct _lexer_token lexer_token;
    struct _lexer_token
    {
        bool awaiting_eq = false; // Do we need an = sign?

        bool start_bracket = false; // (
        bool end_bracket = false;   // )

        bool name_defined = false;
        std::string name;
        bool translated = false;                   // Has this been translated to C yet?
        bool require_return_true_then = false;     // Does this function have to return true to execute then?
        std::vector<lexer_token> then_tokens = {}; // Does anything have to be triggered after this?
        std::string str_return_type = "";
        Gentleman::Types return_type = Gentleman::Types::Void;

        std::string c_code = ""; // This is generated during the parsing phase, or during lexing incase that is possible.
    };

    struct lexer
    {
        bool started_defining = false; // Have we started defining something?

        int functions = 0;
        std::string fn_name = "";
        lexer_token cur_tok;
        std::vector<lexer_token> tokens = {};

        int ss_i_o = 0;
        int ss_i = 0;
        std::vector<std::string> space_split = {"/* EMPTY */"};
        std::string _unspaced = ""; // Basically, joe.
        bool go_out = false;
    } lexer;

    for (size_t i = 0; i < c.size(); i++)
    {
        //printf(" %c ", c[i]);

        if (c[i] != ' ' /* || c[i] != '\0'*/)
        {
            lexer._unspaced += c[i];
        }

        if (c[i] == ' ' || c[i] == '\t')
        {
            //cout << "\n>" << lexer._unspaced << "\n";
            lexer.space_split.push_back(lexer._unspaced);
            lexer._unspaced = "";
            lexer.ss_i++;
            lexer.go_out = true;
        }

        if (i == c.size() - 1)
        {
            lexer.space_split.push_back(lexer._unspaced);
            lexer._unspaced = "";
            lexer.ss_i++;
            lexer.go_out = true;
        }

        if (lexer.ss_i != lexer.ss_i_o)
        {
            lexer.ss_i_o++;
            cout << /*i <<*/ lexer.space_split[lexer.ss_i] << " ";
        }
    }

    for (size_t i = 0; i < lexer.space_split.size(); i++)
    {
        if (lexer.started_defining)
        {
            if (!(lexer.cur_tok.name_defined))
            {
                if (lexer.space_split[lexer.ss_i - 1] == "int")
                {
                    lexer.cur_tok.str_return_type = "int";
                    lexer.cur_tok.return_type = Gentleman::Types::Int;
                    //printf("int\n");
                }

                lexer.cur_tok.name = lexer.space_split[lexer.ss_i];
                lexer.cur_tok.awaiting_eq = true;
                //cout << lexer.cur_tok.name;
            }

            for (size_t c_i = 0; c_i < lexer.space_split[i].size(); c_i++)
            {
                std::string element = lexer.space_split[i];

                if (lexer.cur_tok.awaiting_eq)
                {
                    if (lexer.space_split[lexer.ss_i - 1] == "=")
                    {
                        if (element[c_i] == '(')
                        {
                            lexer.cur_tok.awaiting_eq = false;
                            lexer.cur_tok.start_bracket = true;
                        }
                    }
                }

                if (lexer.cur_tok.start_bracket == true && lexer.cur_tok.end_bracket == false)
                {
                    if (element[c_i] == ')')
                    {
                        lexer.cur_tok.end_bracket = true;
                        //printf("%s %s %d %d", lexer.cur_tok.str_return_type, lexer.cur_tok.name, lexer.cur_tok.start_bracket, lexer.cur_tok.end_bracket);
                        cout << lexer.cur_tok.str_return_type << lexer.cur_tok.name << lexer.cur_tok.start_bracket << lexer.cur_tok.end_bracket << "\n";
                    }
                }
            }
        }

        if (lexer.space_split[lexer.ss_i] == "int")
        {
            if (!(lexer.started_defining))
            {
                lexer.started_defining = true;
                lexer.functions++;
            }
        }
    }

    return gt;
};

Gentleman::Token::Token()
{
    Token::type = Gentleman::Token_Type::UNHANDLED;
}