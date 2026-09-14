#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        bool flag1 = false, flag2 = false;
        int prev1 = 0, prev2 = 0;
        int seq1 = 0, seq2 = 0;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == prev1) seq1++;
            else seq1 = 1;
            prev1 = grid[i][j];
            if (seq1 >= m) flag1 = true;
            
            if (grid[j][i] == prev2) seq2++;
            else seq2 = 1;
            prev2 = grid[j][i];
            if (seq2 >= m) flag2 = true;
        }
        if (flag1) result++;
        if (flag2) result++;
    }

    cout << result;

    return 0;
}
