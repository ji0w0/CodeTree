#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    auto bigger = n > m ? n : m;
    for (int i = bigger; i <= 10000; i++) {
        if (i % n == 0 && i % m == 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}