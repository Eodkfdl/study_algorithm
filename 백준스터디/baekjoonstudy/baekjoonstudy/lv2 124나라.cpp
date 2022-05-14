#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;
//1.숫자를 3가지만 사용하는것을 보고 n진법을 연상할것-n진법 변환 문제와 동일
//2.3으로 나누어 떨어질때 3으로 나눈목 - 1 + 나머지가 0이 아닌 4로 바뀌는것-차이점

string solution(int n) {
    string answer = "";
    int remainder = 0;

    while (n > 0) {
        remainder = n % 3;
        n = n / 3;
       

        if (remainder == 0) {
            remainder = 4;
            n -= 1;
            answer += to_string(remainder);
        }
        else {
            answer += to_string(remainder);
        }


    }
    reverse(answer.begin(), answer.end());
    return answer;
}
int main() {
    int n=0;
    cin >> n;
    cout << solution(n);
}
