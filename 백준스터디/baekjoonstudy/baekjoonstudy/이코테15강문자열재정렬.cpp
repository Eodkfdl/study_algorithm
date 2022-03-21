//알파벳 대문자와 숫자 0~9로만 구성된 문자열이 입력으로 주어집니다.
//이때 모든 알파벳을 오름차순으로 정렬하여 이어서 출력한뒤
//그뒤에 모든숫자를 더한값을 이어서 출력합니다.


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

char S[10000];
vector<char> c;
int sum;
int cnt;
int main() {
	cin >> S;
	for (auto s : S) {
		if (s > 47 && s < 58) {
			sum += s - 48;
			continue;
		}
		if ((s > 64 && s < 91) || (s > 96 && s < 123)) {
			c.push_back(s);
		}
	}
	sort(c.begin(), c.end());;
	for (auto o : c) {
		S[cnt] = o;
		cnt++;
	}
	S[cnt ] = '\0';
	if (sum != 0) {//SUM이 0인경우 0을 출력하지 않아야 한다.
		cout << S << sum;
	}
	else {
		cout << S;
	}
}