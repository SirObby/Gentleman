#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void _handle_project(std::vector<std::string> v)
{

    if (v[2] == "init")
    {

        ofstream project_file;
        project_file.open("./gent.json");
        project_file << "{\n"
                     << "  \"gent\": {\n"
                     << "    \"compile\": \"C\",\n"
                     << "    \"build_directory\": \"./build\"\n"
                     << "  },\n"
                     << "  \"projects\": [\n"
                     << "    {\n"
                     << "      \"name\": \"example\",\n"
                     << "      \"version\": \"0.0.1\",\n"
                     << "      \"source_files\": \"./src\",\n"
                     << "      \"has_libs\": false\n"
                     << "    }\n"
                     << "  ]\n"
                     << "}\n";
        project_file.close();
    
        cout << "Created the project 'JSON' file in this directory."
        << "\nTo build this project run 'gent project build'\n";
    }
    else if (v[2] == "build")
    {
    }
    else if (v.size() < 3)
    {
        cout << "Missing argument[2], Allowed arguments \'init\', \'build\'"
             << "\n";
    }
};