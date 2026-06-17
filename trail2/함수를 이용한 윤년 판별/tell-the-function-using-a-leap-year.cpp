#include <iostream>
using namespace std;

int main() {
    int y;
    cin >> y;

    if (y % 4 == 0)
    {
        if (y % 100 == 0)
        {
            if (y % 400 == 0)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        else
            cout << "true" << endl;
    }
    else
        cout << "false" << endl;
    return 0;
}