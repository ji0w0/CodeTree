#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for (int k = 0; k <= 2 * (n - 1); k++) {
        int cost = k * k + (k + 1) * (k + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;

                for (int x = -1 * k; x <= k; x++) { // 마름모 모양 채굴
                    for (int y = -1 * k; y <= k; y++) {
                        int dx = i + x;
                        int dy = j + y;
                        if (0 > dx || dx >= n || 0 > dy || dy >= n)
                            continue;
                        if (abs(x) + abs(y) > k)
                            continue;
                        if (grid[dx][dy])
                            count += 1;
                    }
                }

                if (0 <= count * m - cost && result < count) {
                    result = count;
                }
            }
        }
    }

    cout << result;

    return 0;
}
