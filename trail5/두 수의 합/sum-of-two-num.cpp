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

    int count = 0;
    for (const auto& [num, freq] : map) {
        int complement = K - num;
        if (complement == num) {
            count += (long long)freq * (freq - 1) / 2; // 같은 값끼리 짝지을 때는 조합으로 계산
        } else if (complement > num) { // 중복 계산 방지
            auto it = map.find(complement);
            if (it != map.end()) {
                count += (long long)freq * it->second;
            }
        }
    }

    cout << count << endl;

    return 0;
}