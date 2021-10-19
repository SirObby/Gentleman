#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "lang/codering.hpp"

using namespace std;

void _handle_build(std::vector<std::string> v)
{

    bool output = false;
    std::string code = "";

    for (size_t i = 0; i < v.size(); i++)
    {
        if (!(output))
        {

            if (v[i] == "-o")
                output = true;

            std::string file = v[i];
            ifstream o;
            o.open(file);

            if (o.good())
            {

                if (o.is_open())
                {

                    while (!o.eof())
                    {
                        std::string line;
                        getline(o, line);
                        code += line;
                        //cout << line << "\n";
                    }
                }
            }
            o.close();
        }
    }

    cout << code;
    
    std::vector<Gentleman::Token> tokens =  _handle_codering(code);
};