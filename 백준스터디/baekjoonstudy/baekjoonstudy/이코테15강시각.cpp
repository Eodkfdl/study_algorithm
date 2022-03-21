
// 정수 N이 입력되면 00시 00초 00분 부터 n시 59분 59초 까지의 모든 시각 중에서 3이 하나라도 포함되는 모든경우의수를 구하는


#include<iostream>

using namespace std;


int n;
int count_n;
int a, b, c, d, e, f;

int main() {
	cin >> n;

	for (int i = 0; i < n+1; i++) {

		for (int j = 0; j < 60; j++) {

			for (int k = 0; k < 60; k++) {
				a = i / 10;
				b = i % 10;
				c = j / 10;
				d = j % 10;
				e = k / 10;
				f = k % 10;
				if (a == 3 || b == 3 || c == 3 || d == 3 || e == 3 || f == 3)count_n += 1;
			}
		}
	}

	cout << count_n;
}

//완전 탐색 문제 유형 가능한 경우의수를 모두 검사해보는 탐색방법(brute force)