#include <string>
#include <vector>
#include<iostream>

using namespace std;
//i��ũ��� �߸� ���ڿ� s1�� ���� s���� ���ӵ� s1s1...���ִ���Ȯ��
//�ִ���̴� ��ü���ڿ������� 1/2 �̴�. �ݺ��Ǿ��ϹǷ�

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