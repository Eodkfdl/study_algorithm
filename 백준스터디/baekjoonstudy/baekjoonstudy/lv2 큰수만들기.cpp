#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int i = k + 1;
    int s = 0;
    //�Ǿ��ڸ��� ���� number�� index��  k+1��° ���� �����̰����ϴ�
    // �Ǿ��ڸ��� ���� ���� �Ǿ����� �Ǿ��ڸ��� �ε�������  k+1-�Ǿ��ڸ����� ��ŭ���������� ������° ���ڰ� �����ɼ� �ִ�
    // ����������� number�Ǳ���-k�� ������ answer�� �����ȴ�.
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