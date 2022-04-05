
/*
N개의 원소를 포함하고 있는 수열이 오름차순으로 정렬되어있을때 이수열에서 x가 등장하는 횟수를 계산하시오
단 이문제는 시간복잡도 O(logN)으로 알고리즘을 섥계하지않으면 시간초과 판정을 받습니다.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, x,temp;

vector<int>B;
int cnt_range(vector<int>& a, int leftv, int rightv) {
	vector<int>::iterator rightIndex = upper_bound(a.begin(), a.end(), rightv);
	vector<int>::iterator leftIndex = upper_bound(a.begin(), a.end(), leftv);
	return rightIndex - leftIndex;
}
int main() {
	cin >> N >> x;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		B.push_back(temp);
	}
	cout << cnt_range(B, x, x);
	

}