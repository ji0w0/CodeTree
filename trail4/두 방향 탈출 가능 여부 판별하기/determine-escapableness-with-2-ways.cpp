#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    if (grid[0][0] == 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int,int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    int dx[2] = {1, 0}; // 아래, 오른쪽
    int dy[2] = {0, 1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 2; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m
                && !visited[nx][ny] && grid[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    cout << (visited[n - 1][m - 1] ? 1 : 0) << "\n";

    return 0;
}