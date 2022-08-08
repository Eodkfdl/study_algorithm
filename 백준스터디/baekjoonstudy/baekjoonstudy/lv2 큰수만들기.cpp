#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int i = k + 1;
    int s = 0;
    //맨앞자리의 수는 number의 index중  k+1번째 까지 선택이가능하다
    // 맨앞자리의 수가 결정 되었으면 맨앞자리의 인덱스에서  k+1-맨앞자리수의 만큼범위내에서 다음번째 숫자가 결정될수 있다
    // 같은방식으로 number의길이-k의 길이의 answer가 결정된다.
    while (answer.size() < (number.size() - k)) {
        char t = '0';
        int index = 0;
        for (int j = s; j < i; j++) {
            if (t < number[j]) {
                t = number[j];
                index = j;
            }
        }
        answer += to_string(t - 48);
        //
        i -= (index - s);
        s = (index + 1);
    }
    return answer;
}
int main() {
    string s;
    int k;
    cin >> k;
    cin >> s;
    cout << solution(s,k);
}