#include <string>
#include <vector>
#include<iostream>

using namespace std;
//i의크기로 잘린 문자열 s1을 원본 s에서 연속된 s1s1...이있는지확인
//최대길이는 전체문자열길이의 1/2 이다. 반복되야하므로

int solution(string s) {
    int answer = 0;
    for (int i = s.length()/2;i>1;i--){
        string s1 = s.substr(0,i);
        for (int j = 1; j * i <s.length();j++) {

        }
    }
    return answer;
}
//abcdebcde
int main() {
    string s;
    cin >> s;

    cout << solution(s) << endl;
}  