#include <iostream>
#include <vector>

using namespace std;

int n, m, q;
int a[100][100];

vector<vector<int>> extractSub(int r1, int c1, int r2, int c2) {
    vector<vector<int>> result;
    for (int i = r1 - 1; i < r2; i++) {
        vector<int> row;
        for (int j = c1 - 1; j < c2; j++) {
            row.push_back(a[i][j]);
        }
        result.push_back(row);
    }
    return result;
}

vector<vector<int>> rotateBorderClockwise(vector<vector<int>> sub) {
    int rows = sub.size();
    int cols = sub[0].size();
    if (rows <= 1 || cols <= 1) return sub;

    vector<int> border;
    for (int j = 0; j < cols; j++) border.push_back(sub[0][j]);
    for (int i = 1; i < rows; i++) border.push_back(sub[i][cols - 1]);
    for (int j = cols - 2; j >= 0; j--) border.push_back(sub[rows - 1][j]);
    for (int i = rows - 2; i >= 1; i--) border.push_back(sub[i][0]);

    int len = border.size();
    vector<int> shifted(len);
    for (int i = 0; i < len; i++) shifted[(i + 1) % len] = border[i];

    int idx = 0;
    for (int j = 0; j < cols; j++) sub[0][j] = shifted[idx++];
    for (int i = 1; i < rows; i++) sub[i][cols - 1] = shifted[idx++];
    for (int j = cols - 2; j >= 0; j--) sub[rows - 1][j] = shifted[idx++];
    for (int i = rows - 2; i >= 1; i--) sub[i][0] = shifted[idx++];

    return sub;
}

// r1, c1을 추가로 받아서 전역 좌표를 계산할 수 있게 함
vector<vector<int>> gaussianAverage(vector<vector<int>> sub, int r1, int c1) {
    int rows = sub.size();
    int cols = sub[0].size();
    vector<vector<int>> result = sub;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = sub[i][j];
            int count = 1;

            int gi = r1 - 1 + i; // 전역 행 인덱스
            int gj = c1 - 1 + j; // 전역 열 인덱스

            // 위
            if (i - 1 >= 0) { sum += sub[i - 1][j]; count++; }
            else if (gi - 1 >= 0) { sum += a[gi - 1][gj]; count++; }

            // 아래
            if (i + 1 < rows) { sum += sub[i + 1][j]; count++; }
            else if (gi + 1 < n) { sum += a[gi + 1][gj]; count++; }

            // 왼쪽
            if (j - 1 >= 0) { sum += sub[i][j - 1]; count++; }
            else if (gj - 1 >= 0) { sum += a[gi][gj - 1]; count++; }

            // 오른쪽
            if (j + 1 < cols) { sum += sub[i][j + 1]; count++; }
            else if (gj + 1 < m) { sum += a[gi][gj + 1]; count++; }

            result[i][j] = sum / count;
        }
    }
    return result;
}

void blow(int r1, int c1, int r2, int c2) {
    vector<vector<int>> sub = extractSub(r1, c1, r2, c2);
    sub = rotateBorderClockwise(sub);

    // 회전 결과를 먼저 a에 반영 (평균 계산 시 바깥 이웃은 여기서 그대로 읽음)
    for (int i = r1 - 1; i < r2; i++)
        for (int j = c1 - 1; j < c2; j++)
            a[i][j] = sub[i - r1 + 1][j - c1 + 1];

    sub = gaussianAverage(sub, r1, c1);

    for (int i = r1 - 1; i < r2; i++)
        for (int j = c1 - 1; j < c2; j++)
            a[i][j] = sub[i - r1 + 1][j - c1 + 1];
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        blow(r1, c1, r2, c2); // 호출 추가!
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}