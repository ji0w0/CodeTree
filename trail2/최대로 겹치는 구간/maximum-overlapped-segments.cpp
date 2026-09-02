#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> events;

    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;

        events.push_back({A, 1}); // 시작
        events.push_back({B, -1}); // 끝
    }

    // 같은 좌표라면 끝(-1)을 먼저 처리
    sort(events.begin(), events.end(), [](const auto& a, const auto& b)
    {
        if (a.first != b.first)
            return a.first < b.first;

        return a.second < b.second;
    });

    int current = 0;
    int answer = 0;

    for (auto [x, type] : events)
    {
        current += type;
        answer = max(answer, current);
    }

    cout << answer << '\n';

    return 0;
}