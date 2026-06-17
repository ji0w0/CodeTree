#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>
using namespace std;

int main() {
    // 표준 입출력 동기화 해제 + cin/cout tie 해제 -> 입력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 번호 -> 이름: 번호가 1~N의 연속된 정수이므로 unordered_map 대신 vector 사용
    // (해시 연산 없이 인덱스로 바로 접근 가능해 더 빠르고 메모리도 적게 씀)
    vector<string> intToStr(N + 1);
    unordered_map<string, int> strToInt;
    strToInt.reserve(N);

    for (int i = 1; i <= N; i++) {
        cin >> intToStr[i];
        strToInt[intToStr[i]] = i;
    }

    // 출력을 한 번에 모아서 처리 -> endl로 인한 매번 flush 비용 제거
    string output;
    output.reserve(M * 8); // 줄당 평균 길이 가정하여 미리 예약 (재할당 줄이기)

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;

        if (isdigit(str[0])) { // isdigit: 문자가 숫자인지 판별한다.
            output += intToStr[stoi(str)];
        } else {
            output += to_string(strToInt[str]);
        }
        output += '\n';
    }

    cout << output;

    return 0;
}