#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;

    unordered_map<string, int> map;
    map.reserve(N);

    int maxFreq = 0;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        sort(str.begin(), str.end());
        map[str]++;
        maxFreq = max(maxFreq, map[str]);
    }

    cout << maxFreq << endl;
    
    return 0;
}