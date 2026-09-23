#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> blocks;
int s1, e1;
int s2, e2;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        blocks.push_back(num);
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    for (int i = e1 - 1; i >= s1 - 1; i--)
        blocks.erase(blocks.begin() + i);

    for (int i = e2 - 1; i >= s2 - 1; i--)
        blocks.erase(blocks.begin() + i);

    cout << blocks.size() << endl;
    for (auto b : blocks)
        cout << b << endl;

    return 0;
}
