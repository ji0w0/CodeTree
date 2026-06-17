#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int count = 0;
    for (int n = A; n <= B; n++)
    {
        if (n % 3 == 0)
        {
            count++;
            continue;
        }

        string s = to_string(n);
        if (s.find('3') != string::npos || s.find('6') != string::npos || s.find('9') != string::npos)
            count++;
    }

    cout << count << endl;

    return 0;
}