#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, K;
    cin >> N >> K;

    unordered_map<int, int> map;
    map.reserve(N);

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        map[n]++;
    }

    vector<pair<int,int>> nums;
    nums.reserve(map.size());
    for (const auto& [num, cnt] : map) {
        nums.push_back({num, cnt});
    }

    sort(nums.begin(), nums.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first > b.first;
    });

    for (int i = 0; i < K; i++) {
        cout << nums[i].first << " ";
    }
    
    return 0;
}