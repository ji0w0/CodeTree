#include <iostream>

using namespace std;

int N, M;
int grid[20][20];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int result = -1;
    for (int n = 1; n <= N; n++) {
        for (int m = 1; m <= M; m++) {

            bool success = false;
            for (int i = 0; i <= N - n; i++) {
                for (int j = 0; j <= M - m; j++) {

                    // 직사각형 내부
                    bool noMinus = true;
                    for (int x = i; x < i + n; x++) {
                        for (int y = j; y < j + m; y++) {
                            if (grid[x][y] <= 0) {
                                noMinus = false;
                                break;
                            }
                        }
                        if (!noMinus) break;
                    }

                    if (noMinus) {
                        success = true;
                        break;
                    }
                }
                if (success) break;
            }

            if (success && result < n * m) {
                result = n * m;
            }
        }
    }

    cout << result;

    return 0;
}
