
// ���� N�� �ԷµǸ� 00�� 00�� 00�� ���� n�� 59�� 59�� ������ ��� �ð� �߿��� 3�� �ϳ��� ���ԵǴ� ������Ǽ��� ���ϴ�


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

//���� Ž�� ���� ���� ������ ����Ǽ��� ��� �˻��غ��� Ž�����(brute force)