#include <iostream>
#include <vector>

using namespace std;

void _handle_help(std::vector<std::string> v)
{
    if (v[2] == "build")
    {
        cout << "usage: gent build <input>\n\nbuild compiles the source files you input.";
    }
    if (v[2] == "project")
    {
    }
    if (v[2] == "version")
    {
        cout << "usage: gent version\n\nList the version of the gentleman compiler.";
    }
}