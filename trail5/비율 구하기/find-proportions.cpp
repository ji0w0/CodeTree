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

    for (const auto& [color, count] : map) {
        float percentage = (static_cast<float>(count) / N) * 100;

        cout << color << " " << fixed << setprecision(4) << percentage << endl;
    }
    
    return 0;
}