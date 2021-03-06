//각자리 숫자(0부터9)로만 이루어진 문자열 s가 주어졌을때,
//왼쪽부터 오른쪽으로 하나씩 모든 숙자를 확인하여 숫자사이에 
//x혹은 + 연산자를 넣어 결과적으로 만들어질 수 있는 가장 큰 수를 구하는
//프로그램을 작성하세요 , 단 +보다 x를 먼저 계산하는 방식과 달리, 
//모든연산은 왼쪽서부터 이루어진다고 가정합니다.
// ex 02984라는 문자열로 만들 수 있는 가장 큰 수는 0+2x9x8x4=입니다.
//또한 만들어 질 수 있는 가장 큰수는 항상 20억 이하의 정수가 되도록 입력이
//주어집니다 - 인트

#include<iostream>
#include<string>
using namespace std;

string s;
int n;
int result;
int main() {
	cin >> s;
	n = s.size();
	result = s[0] - '0';
	for (int i = 0; i < n; i++) {
		n = s[i] - '0';
		if (n <= 1 || result <= 1)result += n;
		else result *= n;
	}
	cout << result << '\n';

}