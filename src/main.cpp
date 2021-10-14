#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <filesystem>

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
        
        }

        if(v[1] == "version") {
            
        }

        if(v[1] == "help") {
            if(v[2] == "build") {
                cout << "usage: gent build <input>\n\nbuild compiles the source files you input.";
            }
            if(v[2] == "project") {
                
            }
            if(v[2] == "version") {
                cout << "usage: gent version\n\nList the version of the gentleman compiler.";
            }
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