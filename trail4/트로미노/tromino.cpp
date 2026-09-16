#include <iostream>

using namespace std;

int n, m;
int grid[200][200];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int max = 0;

    // ㄱㄴ 블록
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            int nums[4] = {
                grid[i][j],
                    grid[i][j + 1],
                    grid[i + 1][j],
                    grid[i + 1][j + 1],
            };

            int sum = 0;
            for (auto& n : nums)
                sum += n;

            for (auto& n : nums) {
                int value = sum - n;
                if (max < value)
                    max = value;
            }
        }
    }

    // 가로
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m; j++) {
            int value = 0;
            for (int x = i; x < i + 3; x++)
                value += grid[x][j];
            if (max < value)
                max = value;
        }
    }

    // 세로
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 2; j++) {
            int value = 0;
            for (int y = j; y < j + 3; y++)
                value += grid[i][y];
            if (max < value)
                max = value;
        }
    }

    cout << max;

    return 0;
}
