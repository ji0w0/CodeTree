#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;

    unordered_map<int, int> map;
    map.reserve(N);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if (map.find(x) != map.end()) {
            if (map[x] > y) {
                map[x] = y;
            }
        } else {
            map[x] = y;
        }
    }

    long long sum = 0;
    for (const auto& [x, y] : map) {
        sum += y;
    }

    cout << sum << endl;
    
    return 0;
}