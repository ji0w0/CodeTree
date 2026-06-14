#include <algorithm>
#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    int bigger = max(n, m);
    for (int i = bigger; i >= 1; i--)
    {
        if (n % i == 0 && m % i == 0)
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}