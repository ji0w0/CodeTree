#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int sum = 0;
    for (int n = A; n <= B; n++)
    {
        bool is_prime = true;
        for(int i = 2; i < n; i++)
            if(n % i == 0)
            {
                is_prime = false;
                break;
            }

        if (is_prime)
            sum += n;
    }

    cout << sum << endl;

    return 0;
}