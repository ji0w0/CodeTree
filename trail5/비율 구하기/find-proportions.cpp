#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    map<string, int> map;
    for (int i = 1; i <= N; ++i) {
        string color;
        cin >> color;
        map[color]++;
    }

    cout << fixed << setprecision(4);
    for (const auto& [color, count] : map) {
        float percentage = (static_cast<float>(count) / N) * 100;

        cout << color << " " << percentage << '\n';
    }
    
    return 0;
}