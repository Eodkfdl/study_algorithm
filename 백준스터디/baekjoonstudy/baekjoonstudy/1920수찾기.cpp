//첫째 줄에 자연수 N(1 ≤ N ≤ 100, 000)이 주어진다.
//다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다.
//다음 줄에는 M(1 ≤ M ≤ 100, 000)이 주어진다.
//다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다.
//모든 정수의 범위는 - 2 ^ 31 보다 크거나 같고2 ^ 31보다 작다.== 인트의 범위

//풀이할때 힘들었던점 : 브루트포스방식으로 접근했다 시간초과 qsort 정렬을 통하여 
//sync_with_stdio()와 cin.tie(0);를 쓰니 시간초과문제가 해결됨.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;

vector<int> A;
int M;
vector<int>B;

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tempn = 0;
	//입력값받기
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> tempn;
		A.push_back(tempn);
	}
	//받은값 정렬

	sort(A.begin(), A.end());


	cin >> M;
	//
	for (int i = 0; i < M; i++) {
		cin >> tempn;
		if (binary_search(A.begin(), A.end(), tempn))cout << 1 << "\n";
		else cout << 0 << "\n";

	}




}