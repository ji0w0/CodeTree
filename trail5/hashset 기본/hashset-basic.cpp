#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    unordered_set<int> set;
    set.reserve(N);
    for (int i = 1; i <= N; ++i) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int k;
            cin >> k;
            set.insert(k);
        } else if (cmd == "remove") {
            int k;
            cin >> k;
            set.erase(k);
        } else if (cmd == "find") {
            int k;
            cin >> k;
            auto it = set.find(k);
            if (it != set.end()) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
    }
    
    return 0;
}