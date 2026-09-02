#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> diff(N + 2, 0);

    for (int i = 0; i < K; i++)
    {
        int A, B;
        cin >> A >> B;

        diff[A]++;
        diff[B + 1]--;
    }

    int current = 0;
    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        current += diff[i];
        answer = max(answer, current);
    }

    cout << answer << '\n';

    return 0;
}