#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int L;
    cin >> L;

    vector<int> A(L), B(L), C(L), D(L);
    for (int i = 0; i < L; i++) cin >> A[i];
    for (int i = 0; i < L; i++) cin >> B[i];
    for (int i = 0; i < L; i++) cin >> C[i];
    for (int i = 0; i < L; i++) cin >> D[i];

    unordered_map<int, int> abSum;
    abSum.reserve(L * L);
    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++)
            abSum[A[i] + B[j]]++;

    int count = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            auto it = abSum.find(-(C[i] + D[j]));
            if (it != abSum.end())
                count += it->second;
        }
    }

    cout << count << endl;

    return 0;
}