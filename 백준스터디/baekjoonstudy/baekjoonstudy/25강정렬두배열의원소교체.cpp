//두개의 배열 A,B가있다 두 배열은 N개의 원소로 구성되어있고 모두자연수이다.
//최대 K번 A와 B의 원소를 서로 바꿀 수 있다.
// 최종 목표는 A의 모든원소의 합이 최대가 되는것.
//N K 그리고 배열 A B의 정보가 주어졌을때 배열 A의 모든원소의 합의 최대값을 출력하라

//1. A와 B 정렬
//2. B의수중 가장큰것부터 A의 수중 가장 작은것부터 서로 교환
//3. 만약 B의 숫자가 A의숫자보다 작은경우 교환 x 종료

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
	//반복자 iterator 접근 -> [] 읽기 *iter 
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