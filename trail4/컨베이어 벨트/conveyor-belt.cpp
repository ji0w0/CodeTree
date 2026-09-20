#include <iostream>

using namespace std;

int n, t;
int u[400];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> u[i];
    for (int i = 0; i < n; i++) cin >> u[n + i];

    t %= (2 * n);

    for (int i = 0; i < n; i++) {
        int idx = i - t;
        idx += (2 * n);
        idx %= (2 * n);
        cout << u[idx] << ' ';
    }

    cout << '\n';

    for (int i = n; i < (2 * n); i++) {
        int idx = i - t;
        idx += (2 * n);
        idx %= (2 * n);
        cout << u[idx] << ' ';
    }

    return 0;
}
