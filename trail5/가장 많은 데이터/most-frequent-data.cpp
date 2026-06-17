#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {    
    int N;
    cin >> N;

    unordered_map<string, int> map;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        map[s] += 1;
    }

    int max = 0;
    for(const auto& pair : map) {
        if(pair.second > max) {
            max = pair.second;
        }
    }
    cout << max << endl;

    return 0;
}