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
    for (int i = 1; i <= N; ++i) {
        int k;
        cin >> k;
        set.insert(k);
    }

    cout << set.size() << endl;
    
    return 0;
}