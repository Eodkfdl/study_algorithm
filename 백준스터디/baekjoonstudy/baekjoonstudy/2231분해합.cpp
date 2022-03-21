#include<iostream>
using namespace std;

//자연수 N(1 ≤ N ≤ 1,000,000)이 주어질때 해당 자연수 N = M+ m의가장큰자리수+m의가장작은자릿수..//
//가장 작은 
int N;

int digit;

int main() {
	cin >> N;
	//1. N의 자릿수를 알아내기
	int temp = N;
	int temp2 = 0;
	int temp3 = 0;
	bool b_digit[7];
	digit = 1;//n의자릿수
	while (temp != 0) {
		temp = temp / 10;//n을 10으로 몫이 0이 될때까지 나누어 준다.
		digit++;
	}
	for (int i = 0; i < 7; i++) {
		b_digit[i] = false;
	}
	for (int i = 0; i < digit; i++) {
		b_digit[i] = true;
	}
	//i,j,k....digit까지 더하고 ijk... // 재귀로될듯?
	temp2 = N;
	for (int i = 9; i > -1; i--) {
		for (int j = 9; j > -1; j--) {
			for (int k = 9; k > -1; k--) {
				for (int a = 9; a > -1; a--) {
					for (int b = 9; b > -1; b--) {
						for (int c = 9; c > -1; c--) {
							for (int d = 9; d > -1; d--) {
								temp3 = i * b_digit[0] + j * b_digit[1] * 10 + k * b_digit[2] * 100 + a * b_digit[3] * 1000 + b * b_digit[4] * 10000 + c * b_digit[5] * 100000 + d * b_digit[6] * 1000000;
								temp = i * b_digit[0] + j * b_digit[1] + k * b_digit[2] + a * b_digit[3] + b * b_digit[4] + c * b_digit[5] + d * b_digit[6] + temp3;
								if (temp == N && temp3 < temp2)temp2 = temp3;
							}
						}
					}

				}
			}
		}
		

	
		//2. N의 자릿수 만큼 for 문의 개수를 돌며 i,j,k..... i+j+k+ijk==N인지 탐색
	}
	if (temp2 == N)
		temp2 = 0;
	cout << temp2 << endl;
}