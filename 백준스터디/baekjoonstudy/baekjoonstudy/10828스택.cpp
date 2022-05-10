/*
������ �����ϴ� ������ ������ ����,
�Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����� �� �ټ� �����̴�.
push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
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