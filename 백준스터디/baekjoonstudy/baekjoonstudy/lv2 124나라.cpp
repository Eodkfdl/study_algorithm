#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;
//1.���ڸ� 3������ ����ϴ°��� ���� n������ �����Ұ�-n���� ��ȯ ������ ����
//2.3���� ������ �������� 3���� ������ - 1 + �������� 0�� �ƴ� 4�� �ٲ�°�-������

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
