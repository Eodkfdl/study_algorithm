//���ĺ� �빮�ڿ� ���� 0~9�θ� ������ ���ڿ��� �Է����� �־����ϴ�.
//�̶� ��� ���ĺ��� ������������ �����Ͽ� �̾ ����ѵ�
//�׵ڿ� �����ڸ� ���Ѱ��� �̾ ����մϴ�.


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
	if (sum != 0) {//SUM�� 0�ΰ�� 0�� ������� �ʾƾ� �Ѵ�.
		cout << S << sum;
	}
	else {
		cout << S;
	}
}