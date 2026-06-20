#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    map<int, int> map;
    for (int i = 1; i <= N; ++i) {
        int n;
        cin >> n;

        if (map.find(n) == map.end()) {
            map[n] = i;
        }
    }

    for (const auto& [key, value] : map) {
        cout << key << " " << value << '\n';
    }
    
    return 0;
}