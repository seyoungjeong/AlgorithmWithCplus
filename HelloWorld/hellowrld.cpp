#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg { "Hello", "World!" };

    for (auto w: msg ) {
        cout << w << " ";
    }
    cout << endl;
    return 0;
}