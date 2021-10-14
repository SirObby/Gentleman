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

        
    }
    else
    {
        cout << "Missing argument 0;";
    }

    return 0;
}