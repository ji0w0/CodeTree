#include <iostream>
#include <vector>
using namespace std;

int n, m, q;
vector<vector<int>> a;

void blow(int floor, bool isRight, int dir) {
    // dir: 0=시작(양방향 시도), -1=위로 진행 중, 1=아래로 진행 중
    if (isRight) {
        int temp = a[floor][m - 1];
        for (int j = 0; j < m; j++) {
            int tmp2 = a[floor][j];
            a[floor][j] = temp;
            temp = tmp2;
        }
    } else {
        int temp = a[floor][0];
        for (int j = m - 1; j >= 0; j--) {
            int tmp2 = a[floor][j];
            a[floor][j] = temp;
            temp = tmp2;
        }
    }

    if (dir <= 0 && floor != 0) {
        bool match = false;
        for (int j = 0; j < m; j++) {
            if (a[floor][j] == a[floor - 1][j]) { match = true; break; }
        }
        if (match) blow(floor - 1, !isRight, -1);
    }

    if (dir >= 0 && floor != n - 1) {
        bool match = false;
        for (int j = 0; j < m; j++) {
            if (a[floor][j] == a[floor + 1][j]) { match = true; break; }
        }
        if (match) blow(floor + 1, !isRight, 1);
    }
}

int main() {
    cin >> n >> m >> q;
    a.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;
        bool isRight = (d == 'L');   // 테스트케이스로 검증된 매핑
        blow(r - 1, isRight, 0);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}