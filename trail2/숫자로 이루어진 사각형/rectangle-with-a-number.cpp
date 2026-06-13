#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int num = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            cout << num++ << " ";

            if (num > 9) {
                num = 1;
            }
        }
        cout << endl;
    }

    return 0;
}