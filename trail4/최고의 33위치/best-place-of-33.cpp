#include <iostream>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];

        }
    }

    int max = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < N - 2; j++) {
            int sum = 0;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    sum += grid[x][y];
                }
            }
            if (max < sum)
                max = sum;
        }
    }
    
    cout << max;
    
    return 0;
}
