#include <iostream>

#define MAX_X 100

using namespace std;

int n;
int blocks[MAX_X + 1];

int main() {
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;

        for(int z = x; z <= y; z++)
            blocks[z]++;
    }
    
    // 최댓값을 구합니다.
    int max = 0;
    for(int i = 1; i <= MAX_X; i++)
        if(blocks[i] > max)
            max = blocks[i];
    
    cout << max << "\n";
    return 0;
}