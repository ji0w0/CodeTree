#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;

    int len = A.length();
    char last = A[len - 1];

    for (int i = 0; i < len; i++) {
        if (A[0] == last) {
            A.erase(A.begin());
            A.push_back(last);
        } else {
            break;
        }
    }

    int result = 0, count = 0;
    char cur;
    for (auto a : A) {
        if (cur != a) {
            cur = a;
            result += (0 < count
                        ? (count < 10 ? 2 : 3)
                        : 0);
            count = 1;
        } else {
            count += 1;
        }
    }

    result += (0 < count && count < 10 ? 2 : 3);

    cout << result;


    return 0;
}
