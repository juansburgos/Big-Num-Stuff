#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    vector<string> msg {"Puede ser pa? .123 vo sabe pa"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
