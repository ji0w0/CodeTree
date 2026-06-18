#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;

    unordered_map<int, int> map;
    map.reserve(N);

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        map[n]++;
    }

    long long count = 0;
    for (const auto& [num1, freq1] : map) {
        int complement = K - num1;
        for (const auto& [num2, freq2] : map) {
            if (num2 < num1) continue;
            int num3 = complement - num2;
            if (num3 < num2) continue;
            auto it = map.find(num3);
            if (it == map.end()) continue;
            int freq3 = it->second;
            
            if (num3 == num1 && num3 == num2) {
                count += freq1 * (freq1 - 1) * (freq1 - 2) / 6; // num1 == num2 == num3
            } else if (num1 == num2) {
                count += freq1 * (freq1 - 1) / 2 * freq3; // num1 == num2 < num3
            } else if (num2 == num3) {
                count += (long long)freq1 * freq3 * (freq3 - 1) / 2; // num1 < num2 == num3
            } else {
                count += (long long)freq1 * freq2 * freq3; // num1 < num2 < num3
            }
        }
    }

    cout << count << endl;

    return 0;
}