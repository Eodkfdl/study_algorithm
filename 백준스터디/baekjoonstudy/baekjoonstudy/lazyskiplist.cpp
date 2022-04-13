#include<iostream>
#include<vector>
#include <set>
#include <chrono>
#include<mutex>
#include <algorithm>

using namespace std;
using namespace chrono;

constexpr int NUM_TEST = 4000000;
constexpr int KEY_RANGE = 1000;
constexpr int MAX_THREADS = 8;

thread_local int thread_id; // �����帶�� �ٸ��� ���� ���� ���� (?) �ٸ� �����尡 ������Ʈ�ص� ������ ����. C++ ǥ��
thread_local int num_lock;
thread_local int Level;


#pragma once
//�ִ� ��� �����带 ������ ���� pc�� ���� �ٲ������ 
constexpr int NUM_THREADS = 8;

constexpr int MAX_LEVEL = 9;
//���ø��� ���� sknode�� skiplist �� �����ϱ�
template<typename Type>
class SK_NODE {
public:
	int key;
	Type data;
	//���⿡ ����ü !
	SK_NODE* volatile next[MAX_LEVEL + 1];
	int top_level; // ��帶�� ���̰� �ٸ���.
	volatile bool is_removed;
	volatile bool is_link_finished;
	recursive_mutex n_lock;
	SK_NODE() {
		key = 0;
		for (auto& n : next) {
			n = nullptr;
		}
		top_level = 0;
		is_removed = false;

	}
	SK_NODE(int x, int top, Type d) {
		key = x;
		data = d;
		for (auto& n : next) {
			n = nullptr;
		}
		top_level = top;
		is_removed = false;
		is_link_finished = false;
	}

};


//temp
template<typename Type>
class LSKLIST {

public:
	SK_NODE<Type> head, tail;

	LSKLIST() {
		head.key = 0x80000000;
		tail.key = 0x7FFFFFFF;
		for (auto& n : head.next) {
			n = &tail;
			//tail�� �ּҸ� ����Ѵ�. 
			//head.next[0] = tail.next[0] head.next[1] = tail.next[1] �̷������� ���α׷����ϸ� �ȵȴ�. tail�� �ּҰ� �������� tail.next�� �ּҰ� ���� �ȵȴ�. head next�� �� ���̵ȴ�. 
			//��? tail next�� ���̴ϱ�. head.next[0] = &tail; head.next[1] = &tail �̷��� �ؾ��Ѵ�.
		}
		head.top_level = tail.top_level = MAX_LEVEL; // ��� ����Ǿ� �־����. 
		head.is_link_finished = tail.is_link_finished = true;
	}
	~LSKLIST() {
		clear();
	}
	void clear() {
		SK_NODE<Type>* ptr = nullptr;
		while (head.next[0] != &tail) { // head->next�� tail�� �ƴϸ�(����Ǿ����� ������) �����
			ptr = head.next[0];
			head.next[0] = head.next[0]->next[0]; // �����Ŵ
			delete ptr;
		}
		// �������ϰ� �����ִ� ���� ����
		for (auto& n : head.next) {
			n = &tail;
		}
	}

	int Find(int x, SK_NODE<Type>* preds[], SK_NODE<Type>* currs[]) {
		int l_found = -1;
		SK_NODE<Type>* pred = &head;
		for (int cl = MAX_LEVEL; cl >= 0; --cl) {
			SK_NODE<Type>* curr = pred->next[cl];
			while (x > curr->key) {
				pred = curr;
				curr = pred->next[cl];
			}
			if (l_found == -1 && x == curr->key) {
				l_found = cl;
			}
			preds[cl] = pred;
			currs[cl] = curr;
		}
		return l_found;
	}


	bool insert(int key, Type data)
	{
		int topLevel = 0;
		//�������� �����ֱ�
		while ((rand() % 2) == 0) {
			topLevel++;
			Level = topLevel;
			if (MAX_LEVEL == topLevel) break;
		}

		SK_NODE<Type>* preds[MAX_LEVEL + 1];
		SK_NODE<Type>* currs[MAX_LEVEL + 1];

		while (true) {
			int f_level = Find(key, preds, currs);
			if (-1 != f_level) {
				SK_NODE<Type>* nodeFound = currs[0];
				if (false == nodeFound->is_removed) {
					while (false == nodeFound->is_link_finished) {}
					return false;
				}
				continue;
			}
			int highestLocked = -1;
			SK_NODE<Type>* pred, * curr;
			bool is_valid = true;
			for (int level = 0; is_valid && (level <= Level); level++) {
				pred = preds[level];
				curr = currs[level];
				pred->n_lock.lock();
				highestLocked = level;
				is_valid = !(pred->is_removed) && !(curr->is_removed) && (pred->next[level] == curr);
			}
			if (!is_valid) {

				for (int level = 0; level <= highestLocked; level++) {
					preds[level]->n_lock.unlock();
				}
				continue;
			}
			SK_NODE<Type>* newNode = new SK_NODE<Type>(key, Level, data);
			for (int level = 0; level <= Level; level++) {
				newNode->next[level] = currs[level];
			}
			for (int level = 0; level <= Level; level++) {
				preds[level]->next[level] = newNode;
			}
			newNode->is_link_finished = true;

			for (int level = 0; level <= highestLocked; level++) {
				preds[level]->n_lock.unlock();
			}
			return true;
		}
	}


	bool erase(int x)
	{
		SK_NODE<Type>* preds[MAX_LEVEL + 1];
		SK_NODE<Type>* currs[MAX_LEVEL + 1];

		bool isMarked = false;
		while (true)
		{
			int f_level = Find(x, preds, currs);

			if (isMarked || ((f_level == -1) && (currs[0]->is_removed == true) &&
				(currs[0]->is_link_finished == false) && (f_level != currs[0]->top_level)))
			{
				if (isMarked == false)
				{
					currs[0]->n_lock.lock();
					if (currs[0]->is_removed == true) //�ٸ���尡 �����ؼ� invalid������ ���� �����Ƿ� ��˻�
					{
						currs[0]->n_lock.unlock();
						return false;
					}

					currs[0]->is_removed = true;
					isMarked = true;
				}

				bool is_valid = true;
				int cl;

				for (cl = 0; cl <= MAX_LEVEL; cl++)
				{
					preds[cl]->n_lock.lock();
					is_valid = (preds[cl]->is_removed == false) && (currs[cl]->is_removed == false) && (preds[cl]->next[cl] == currs[cl]); // ��尡 valid���� �˻�
					if (is_valid == false) break;
				}

				if (is_valid == false)
				{
					for (int i = 0; i <= cl; i++)
						preds[i]->n_lock.unlock();
					continue;
				}

				for (int i = currs[0]->top_level; i >= 0; i--)
				{
					preds[i]->next[i] = currs[i]->next[i];

				}

				for (int i = 0; i <= MAX_LEVEL; i++)
					preds[i]->n_lock.unlock();
				return true;
			}

			return false;
		}
	}

	bool count(int key)
	{
		SK_NODE<Type>* preds[MAX_LEVEL + 1];
		SK_NODE<Type>* currs[MAX_LEVEL + 1];

		int f_level = Find(key, preds, currs);
		return (f_level != -1 && !currs[f_level]->is_removed && currs[f_level]->is_link_finished);
	}
	void display20() {
		cout << endl;
		SK_NODE<Type>* ptr = head.next[0];
		int num = 20;
		while (ptr != &tail) {
			cout << "key:" << ptr->key << "data" << ptr->data << ", TOP : " << ptr->top_level << ",";
			//cout << ptr->key << ",";
			ptr = ptr->next[0];
			num--;
			if (num == 0) break;
		}
		cout << endl;
	}
	bool Contains(int key)
	{
		SK_NODE<Type>* preds[MAX_LEVEL + 1];
		SK_NODE<Type>* currs[MAX_LEVEL + 1];

		int f_level = Find(key, preds, currs);
		return (f_level != -1 && currs[f_level]->is_removed && currs[f_level]->is_link_finished);
	}
	bool empty() {
		int n = 0;
		for (SK_NODE<Type>* h = head.next[0]; h->key != tail.key; h = h->next[0]) {
			n++;
		}

		return n < 1;
	}
};


//CSKLIST clist;
LSKLIST<int> clist;

void ThreadFunc(int num_thread, int t_id)
{
	int key;
	thread_id = t_id;
	int data = t_id;
	for (int i = 0; i < NUM_TEST / num_thread; i++) {
		switch (rand() % 3) {
		case 0:
			key = rand() % KEY_RANGE;
			clist.insert(key, data);
			break;
		case 1:
			key = rand() % KEY_RANGE;
			clist.erase(key);
			break;
		case 2:
			key = rand() % KEY_RANGE;
			clist.Contains(key);
			break;
		default:
			cout << "Error n";
			exit(1);
		}
		//clist.Sort();
	}
}

int main()
{
	for (int num = 1; num <= MAX_THREADS; num = num * 2) {
		clist.clear();
		// num ������ �����带 �����ؼ� ��ġ��ũ �Լ� ����
		vector<thread> threads;
		auto start_time = high_resolution_clock::now();
		for (int i = 0; i < num; i++) {
			threads.emplace_back(ThreadFunc, num, i);
		}
		for (auto& t : threads)
			t.join();

		auto dur = high_resolution_clock::now() - start_time;
		clist.display20();
		cout << num << " Threads, ";
		cout << "Exec Time = " << duration_cast<milliseconds>(dur).count() << "ms, ";
		// -------------------------------------------

	}
}