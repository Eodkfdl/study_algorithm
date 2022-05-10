//어떠한수 n이 1이될때까지 다음의 두과정중 하나를 반복적으로 선ㅌ택하여 수행하려고한다
//단 두번째 연산은 n이 k로 나누어 떨어질때만 선택할 수 있습니다.

//1. n에서 1을뺍니다.
//2. n을 k로 나눕니다.
#include<iostream>
using namespace std;


int n, k, temp, cnt;

int main() {
	cin >> n >> k; 
	// n을 k 로나누고 나머지 
	while (1) {
		temp = (n / k) * k;
		cnt += n - temp;
		if (n < k)break;
		cnt++;
		n = n / k;
	}
	cnt += (n - 1);
	cout << cnt;

}