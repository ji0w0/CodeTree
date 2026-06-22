#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    int a[K], b[K];
    for (int i = 0; i < K; ++i) cin >> a[i] >> b[i];

    int arr[N + 1];
    for (int i = 1; i <= N; ++i) arr[i] = i;

    unordered_set<int> sets[N + 1];
    for (int i = 1; i <= N; ++i) sets[i].insert(i);

    for (int rep = 0; rep < 3; ++rep) {
        for (int i = 0; i < K; ++i) {
            int pa = arr[a[i]];
            int pb = arr[b[i]];

            swap(arr[a[i]], arr[b[i]]);

            sets[pa].insert(b[i]);
            sets[pb].insert(a[i]);
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << sets[i].size() << '\n';
    }

    return 0;
}