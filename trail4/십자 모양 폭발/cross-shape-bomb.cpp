#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> grid;
int r, c;

int main() {
    cin >> n;

    grid.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    r -= 1; // index
    c -= 1;
    int range = grid[r][c];
    for (int i = 0; i < range; i++) {
        if (0 <= r + i && r + i < n)
            grid[r + i][c] = 0;
        if (0 <= r - i && r - i < n)
            grid[r - i][c] = 0;
        if (0 <= c + i && c + i < n)
            grid[r][c + i] = 0;
        if (0 <= c - i && c - i < n)
            grid[r][c - i] = 0;
    }

    for (int j = 0; j < n; j++) {
        int widx = n - 1;              // 맨 아래부터 채워나감
        for (int i = n - 1; i >= 0; i--) {
            if (grid[i][j] != 0)
                grid[widx--][j] = grid[i][j];
        }
        while (widx >= 0) {
            grid[widx--][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
