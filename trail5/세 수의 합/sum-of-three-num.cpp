#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;

    int arr[N];
    unordered_map<int, int> map;
    map.reserve(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        map[arr[i]]++;
    }

    int count = 0;
    for(int i = 0; i < N; i++) {
        map[arr[i]]--;
        for(int j = 0; j < i; j++) {
            if(map.count(K - arr[i] - arr[j]) > 0)
                count += map[K - arr[i] - arr[j]];
        }
    }

    cout << count << endl;

    return 0;
}