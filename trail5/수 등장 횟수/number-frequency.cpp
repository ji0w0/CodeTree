#include <iostream>
#include <unordered_map>
using namespace std;

int main() {    
    int N, M;
    cin >> N >> M;

    unordered_map<int, int> nums;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums[num] += 1;
    }

    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;
        cout << nums[num] << " ";
    }

    return 0;
}