#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    map<int, int> map;;
    for (int i = 1; i <= N; ++i) {
        string cmd;

        cin >> cmd;
        if (cmd == "add") {
            int k, v;
            cin >> k >> v;
            map[k] = v;
        } else if (cmd == "remove") {
            int k;
            cin >> k;
            map.erase(k);
        } else if (cmd == "find") {
            int k;
            cin >> k;
            if (map.find(k) != map.end()) {
                cout << map[k] << endl;
            } else {
                cout << "None" << endl;
            }
        } else if (cmd == "print_list") {
            if (map.empty()) {
                cout << "None" << endl;
            } else {
                for (const auto& [key, value] : map) {
                    cout << value << " ";
                }
                cout << endl;
            }
        }
    }
    
    return 0;
}