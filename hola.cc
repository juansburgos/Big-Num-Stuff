#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    vector<string> msg {"1 2 3 a ver si se rompe esto"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
