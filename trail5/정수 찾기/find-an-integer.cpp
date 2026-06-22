#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, M;
    cin >> N;

    unordered_set<int> set;
    for (int i = 1; i <= N; ++i) {
        int k;
        cin >> k;
        set.insert(k);
    }

    cin >> M;
    for (int i = 1; i <= M; ++i) {
        int k;
        cin >> k;
        auto it = set.find(k);
        if (it != set.end()) {
            cout << true << endl;
        } else {
            cout << false << endl;
        }
    }
    
    return 0;
}