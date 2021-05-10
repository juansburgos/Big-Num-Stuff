#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    vector<string> msg {"Voy a cambiar esto"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
