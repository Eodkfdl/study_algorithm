/*
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

*/



#include<iostream>
#include<string>

using namespace std;

int m;
int n;
std::string c;

class node {
public:
	int n;
	node* next;
	node(int &x,node* p) {
		n = x;
		next = p;
	}
	node() {
		n = 0;
		next = NULL;
	}

};
class deque {
private:
	node front,end ;

public:
	deque(){
		front.next = &end;
	}
	int Empty() {//비어있으면 1리턴
		if (front.next == &end)return 1;
		else return 0;
	}
	void Push_front(int& x) {
		if (Empty())front.next = new node(x, &end);
		else {
			node * a = new node(x, front.next);
			front.next = a;
		}
	}
	void Push_back(int& x) {
		if (Empty())front.next = new node(x, &end);
		else {
			node *p = front.next;
			while (p->next!=&end) {
				p = p->next;
			}
			node* a = new node(x, &end);
			p->next = a;
		}
	}

	void Pop_front() {
		if (Empty() == 0) {
			node* p = &front;
			p = p->next;
			cout << p->n<<"\n";
			front.next = p->next;
			delete(p);

		}
		else cout << "-1" << "\n";
	}
	void Pop_back() {
		if (Empty() == 0) {
			node* p = &front;
			node* p2 = &front;
			p = p->next;
			while (p->next != &end) {
				p = p->next;
				p2 = p2->next;
			}
			cout << p->n << "\n";
			p2->next = &end;
			delete(p);

		}
		else cout << "-1" << "\n";
	}
	
	int Size() {
		if (Empty())return 0;
		int deque_size = 0;
		node * p = &front;
		while (p->next != &end) {
			p = p->next;
			deque_size++;
			
		}
		return deque_size;
	}
	void Front() {
		if (Empty())cout << -1 << "\n";
		else cout <<front.next->n<< "\n";
	}
	void Back() {
		node* p = &front;
		if(Empty()) cout << "-1" << "\n";
		else {
			while (p->next!=&end)
			{
				p = p->next;
			}
			cout << p->n << endl;
		}
	}
};

enum commend {
	push_front, push_back,
	empty, 
	pop_front, pop_back, 
	size,
	front , back

};

enum::commend strtoenum(string str) {
	if (str == "push_front")return commend::push_front;
	if (str == "push_back")return commend::push_back;
	if (str == "size")return commend::size;
	if (str == "pop_front")return commend::pop_front;
	if (str == "pop_back")return commend::pop_back;
	if (str == "front")return front;
	if (str == "back")return back;
	if (str == "empty")return commend::empty;
}

deque theque;

int main() {
	
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> c;
		switch (strtoenum(c))
		{
		case push_front:
			cin >> m;
			theque.Push_front(m);
			break;
		case push_back:
			cin >> m;
			theque.Push_back(m);
			break;
		case back:
			theque.Back();
			break;
		case commend::empty:
			cout << theque.Empty() << "\n";
			break;
		case commend::size:
			cout << theque.Size() << "\n";
			break;
		case front:
			theque.Front();
			break;
		case pop_front:
			theque.Pop_front();
			break;
		case pop_back:
			theque.Pop_back();
		default:
			break;
		}
	}

}