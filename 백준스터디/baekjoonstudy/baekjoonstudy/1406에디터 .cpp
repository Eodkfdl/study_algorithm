/*
L Ŀ���� �������� �� ĭ �ű�
D Ŀ���� ���������� ��ĭ �ű�
B Ŀ�� ���ʿ��ִ� ���ڸ�����
P x x��¹��ڸ� Ŀ�� ���ʿ� �߰���
Ŀ���� ������ �ǵڿ� ��ġ�ϸ� �ִ� 600,000���ڱ��� �Է°���
*/

#include<iostream>
#include<string>
using namespace std;
string commend;
string m;
int commend_num;
char c;
enum commend {
	L,
	D,
	B,
	P

};

enum::commend strtoenum(string str) {
	if (str == "L")return commend::L;
	if (str == "D")return commend::D;
	if (str == "B")return commend::B;
	if (str == "P")return commend::P;

}

int main() {
	cin >> m;
	cin >> commend_num;
	int n=m.size();
	int max = m.size();
	auto it = m.begin();
	auto it2 = m.begin();
	
	for (int i = 0; i < commend_num; i++) {
		cin >> commend;
		it = it2;
		switch (strtoenum(commend))
		{
		case L:
			
			if(n>0)n--;
			break;
		case D:
			if (n < max)n++;
				break;
		case B:
				if (n > 0) {
					it += n-1;
					m.erase(it);
					n--;
				}
			
			break;
		case P:
			cin >> c;
			it += n;
			m.insert(it, c);
			n++;
			break;
		default:
		
				break;
		}
		
	}
	for (auto t : m) {
		cout << t;
	}

}
