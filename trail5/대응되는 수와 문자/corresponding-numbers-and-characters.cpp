#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, string> intMap;
    unordered_map<string, int> strMap;
    intMap.reserve(N);
    strMap.reserve(N);

    for (int i = 1; i <= N; i++) {
        cin >> intMap[i];
        strMap[intMap[i]] = i;
    }

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        
        if (isdigit(str[0])) { // isdigit: 문자가 숫자인지 판별한다.
            cout << intMap[stoi(str)] << endl;
        } else {
            cout << strMap[str] << endl;
        }
    }

    return 0;
}