//�ΰ��� �迭 A,B���ִ� �� �迭�� N���� ���ҷ� �����Ǿ��ְ� ����ڿ����̴�.
//�ִ� K�� A�� B�� ���Ҹ� ���� �ٲ� �� �ִ�.
// ���� ��ǥ�� A�� �������� ���� �ִ밡 �Ǵ°�.
//N K �׸��� �迭 A B�� ������ �־������� �迭 A�� �������� ���� �ִ밪�� ����϶�

//1. A�� B ����
//2. B�Ǽ��� ����ū�ͺ��� A�� ���� ���� �����ͺ��� ���� ��ȯ
//3. ���� B�� ���ڰ� A�Ǽ��ں��� ������� ��ȯ x ����

// 1<= N <=100,000 0=<K<=N

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int N;
int K;
int temp;
vector<int> A;
vector<int> B;

int main() {
	cin >> N>> K;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		B.push_back(temp);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	//�ݺ��� iterator ���� -> [] �б� *iter 
	auto iter1 = A.begin();
	auto iter2 = B.end();
	iter2--;
	for (int i =0 ; i<K ;i++ ) {
		if (*iter1 < *iter2)*iter1 = *iter2;
		iter1++;
		iter2--;
	}
	for (auto t : A)cout << t;
	cout << endl;
	for (auto t : B)cout << t;
	cout << endl;
	temp = 0;
	for (auto t : A) {
		temp += t;
	}
	cout << temp;
}