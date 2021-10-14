#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *args[])
{
    vector<string> v;

    for (size_t i = 0; i < argc; i++)
    {
        v.push_back(args[i]);
    }

    cout << "sus";
    return 0;
}