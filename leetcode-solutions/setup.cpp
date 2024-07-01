#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <string>

using namespace std;

class LeetcodeWrtiter
{
public:
    int writeFile(string filename, string data)
    {
        if (filesystem::exists(filename))
        {
            cout << "[ / ] Creating `" << filename << "`" << endl;
        }

        ofstream file(filename, ios::out | ios::app);

        if (!file.is_open())
        {
            cerr << "[ - ] Failed to open file." << endl;
            return 1;
        }

        file << data;

        file.close();

        if (file.fail())
        {
            cerr << "[ - ] Failed to close the file." << endl;
            return 1;
        }

        cout << "[ WRITTEN ] Written " << data.size() << " bytes to " << filename << endl;

        return EXIT_SUCCESS;
    }
};

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "[ ! ] Usage " << argv[0] << " new \"filename\"" << endl;
        return 1;
    }
    string command = argv[1];
    if (command != "new")
    {
        cerr << "[ ! ] The first argument must be 'new'" << endl;
        return 1;
    }

    string filename = argv[2];

    // Read the multiline string from stdin
    stringstream buffer;
    buffer << cin.rdbuf();
    string data = buffer.str();

    // Calculate the size of the multiline string
    size_t dataSize = data.size();
    cout << "[ / ] Size of data to be written to file: " << dataSize << " bytes" << endl;

    // Execute filewriter
    LeetcodeWrtiter leet;
    leet.writeFile(filename, data);

    return EXIT_SUCCESS;
}