/*
L 커서를 왼쪽으로 한 칸 옮김
D 커서를 오른쪽으로 한칸 옮김
B 커서 왼쪽에있는 문자를지움
P x x라는문자를 커서 왼쪽에 추가함
커서는 문장의 맨뒤에 위치하며 최대 600,000글자까지 입력가능
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
