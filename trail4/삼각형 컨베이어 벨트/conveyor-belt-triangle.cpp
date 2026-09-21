#include <iostream>

using namespace std;

int n, t;
int u[600];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> u[i];
    for (int i = 0; i < n; i++) cin >> u[n + i];
    for (int i = 0; i < n; i++) cin >> u[2 * n + i];

    t %= (3 * n);

    for (int i = 0; i < n; i++) {
        int idx = i - t;
        idx += (3 * n);
        idx %= (3 * n);
        cout << u[idx] << ' ';
    }

    cout << '\n';

    for (int i = n; i < (2 * n); i++) {
        int idx = i - t;
        idx += (3 * n);
        idx %= (3 * n);
        cout << u[idx] << ' ';
    }

    cout << '\n';

    for (int i = (2 * n); i < (3 * n); i++) {
        int idx = i - t;
        idx += (3 * n);
        idx %= (3 * n);
        cout << u[idx] << ' ';
    }

    return 0;
}
