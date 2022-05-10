/*
첫재줄에 떡의 갯수 N과 요청한 떡의 길이 M이 주어진다.(1<N<= 1,000,000 1<=M<=2,000,000,000)
둘째줄에는 각각 떡의 개별 높이가 주어집니다 떡높이의 총합은 항상 M이상이므로 손님은 필요한 양만큼
떡을 사갈수 있다 높이는 10억보다 작ㄴ거나 같은 양의 정수 또는 0입니다.
높이 H를 주면 H이상의 길이를 가진 떡은 나머지만큼 잘린다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M; 

int temp, sum;
vector<int>R;//ricecake



int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		R.push_back(temp);
	}
	//한번정렬
	sort(R.begin(), R.end());
	
	int start = R.front();
	int end = *(R.end()-1);

	while (start<=end){
		int mid = (start + end) / 2;
		sum = 0;
		for (int i = 0; i < N; i++) {
			if(R[i]>mid)sum += R[i] - mid;
		}
		if (sum < M) {
			end = mid - 1;
		}
		else if (sum >= M) {
			start = mid + 1;
			temp = mid;
			
		}


	}
	cout << temp << endl;
}