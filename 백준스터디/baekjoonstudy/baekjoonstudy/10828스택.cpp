/*
정수를 저장하는 스택을 구현한 다음,
입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 다섯 가지이다.
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int m;
int n;
std::vector<int> que;
std::string c;
enum commend{
	push,empty,pop,size,top
	
};
int Empty() {
	if (que.size() == 0)return 1;
	else return 0;
}
void Push(int& x) {
	que.push_back(x);
}
void Pop() {
	if (Empty() == 0) {
		cout << *(que.end() - 1) << "\n";
		que.erase(que.end() - 1);
	}
	else cout << "-1" << "\n";
}
void Size() {
	cout<< que.size() << "\n";
}
void Top() {
	if (que.size() == 0)cout << -1 << "\n";
	else cout<<(*(que.end() - 1)) << "\n";
}

enum::commend strtoenum(string str) {
	if (str == "push")return push;
	if (str == "pop")return pop;
	if (str == "size")return commend::size;
	if (str == "top")return top;
	if (str == "empty")return commend::empty;
}

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> c;
		switch (strtoenum(c))
		{
		case push:
			cin >> m;
			Push(m);
			break;
		case pop:
			Pop();
			break;
			case commend::empty:
				cout<<Empty() << "\n";
			break;
			case commend::size:
				Size();
			break;
		case top:
			Top();
			break;
		default:
			break;
		}
	}

}