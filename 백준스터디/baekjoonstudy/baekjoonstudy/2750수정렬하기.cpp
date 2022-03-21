
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;

vector<int> A;


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

	for (auto b : A) {
		cout << b << "\n";
	}



}