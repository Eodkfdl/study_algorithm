//��Ѽ� n�� 1�̵ɶ����� ������ �ΰ����� �ϳ��� �ݺ������� �������Ͽ� �����Ϸ����Ѵ�
//�� �ι�° ������ n�� k�� ������ ���������� ������ �� �ֽ��ϴ�.

//1. n���� 1�����ϴ�.
//2. n�� k�� �����ϴ�.
#include<iostream>
using namespace std;


int n, k, temp, cnt;

int main() {
	cin >> n >> k; 
	// n�� k �γ����� ������ 
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