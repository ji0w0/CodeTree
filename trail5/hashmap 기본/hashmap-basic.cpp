#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, int> map;

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
        }
    }
    return 0;
}