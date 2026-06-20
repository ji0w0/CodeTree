#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string str;
    cin >> str;

    unordered_map<char, int> freqMap;
    unordered_map<char, int> indexMap;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        freqMap[ch]++;

        if (freqMap[ch] == 1) {
            indexMap[ch] = i;
        }
    }

    int minIndex = str.length();
    for (const auto& [ch, freq] : freqMap) {
        if (freq == 1 && indexMap[ch] < minIndex) {
            minIndex = indexMap[ch];
        }
    }

    if (minIndex < str.length()) {
        cout << str[minIndex] << endl;
    } else {
        cout << "None" << endl;
    }

    return 0;
}