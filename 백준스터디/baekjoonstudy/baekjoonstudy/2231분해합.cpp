#include<iostream>
using namespace std;

//�ڿ��� N(1 �� N �� 1,000,000)�� �־����� �ش� �ڿ��� N = M+ m�ǰ���ū�ڸ���+m�ǰ��������ڸ���..//
//���� ���� 
int N;

int digit;

int main() {
	cin >> N;
	//1. N�� �ڸ����� �˾Ƴ���
	int temp = N;
	int temp2 = 0;
	int temp3 = 0;
	bool b_digit[7];
	digit = 1;//n���ڸ���
	while (temp != 0) {
		temp = temp / 10;//n�� 10���� ���� 0�� �ɶ����� ������ �ش�.
		digit++;
	}
	for (int i = 0; i < 7; i++) {
		b_digit[i] = false;
	}
	for (int i = 0; i < digit; i++) {
		b_digit[i] = true;
	}
	//i,j,k....digit���� ���ϰ� ijk... // ��ͷεɵ�?
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
		

	
		//2. N�� �ڸ��� ��ŭ for ���� ������ ���� i,j,k..... i+j+k+ijk==N���� Ž��
	}
	if (temp2 == N)
		temp2 = 0;
	cout << temp2 << endl;
}