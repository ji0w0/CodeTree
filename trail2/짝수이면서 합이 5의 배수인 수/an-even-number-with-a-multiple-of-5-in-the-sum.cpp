#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N % 2 == 0)
    {
        int ten = N / 10;
        int one = N % 10;

        if ((ten + one) % 5 == 0 )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}