#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <filesystem>

#include "help.hpp"
#include "project.hpp"

namespace fs = std::filesystem;

using namespace std;

int main(int argc, char *argv[])
{

    vector<string> v;

    for (size_t i = 0; i < argc; i++)
    {
        v.push_back(argv[i]);
    }

    if (argc != 1)
    {

        if(v[1] == "build") {

        }

        if(v[1] == "project") {
            _handle_project(v);
        }

        if(v[1] == "version") {
            cout << "gent version 0.0.1 compiled on "
            << __DATE__
            << "\n";
        } 

        if(v[1] == "help") {
            _handle_help(v);
        }
        
    }
    else
    {
        cout << "gent is a tool for managing gentleman source code \n\nUsage:\n\n        gent <command> [<args>]\n\nThe commands are:\n\n"
        << "        build       compile source code.\n"
        << "        project     manage your gentleman project.\n"
        << "        version     list the version of gentleman.\n"
        << "\nUse \"gent help <command>\" for more information about a command."
        ;
    }

    return 0;
}