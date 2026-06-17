#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = 0;
    for (int n = 1; n <= N; n++) 
        sum += n;

    cout << sum / 10 << endl;
    return 0;
}