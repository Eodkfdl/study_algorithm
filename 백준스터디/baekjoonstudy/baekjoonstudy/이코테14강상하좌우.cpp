//NxNũ���� ���簢�� ����, ���� ������ ��ǥ�� 1,1�̸� ��������� �Ʒ���ǥ�� N,N 
// 

#include<iostream>


using namespace std;

int max_x, max_y;
int x, y;
char plan[100];


int main() {

	cin >> max_x ;
	//1,1 �� �����̹Ƿ� �������Ǹ� ���� 0,0�� ������ �ǵ��� �����̵�
	max_x -= 1;
	max_y = max_x;
	cin.ignore();//���ۺ��� ���δٸ� �ڷ��� ����� ����,���ڿ��� cin�� ���� �ޱ⶧���� ���۸� �ѹ� ������ʿ䰡����
	cin.getline(plan,100);

	for (int i = 0; i < 100; i++) {
		if (plan[i] == '\0')break;

		switch (plan[i])
		{
		case 'L':
			if (x > 0)x -= 1;
			break;
		case 'R':
			if (x < max_x) x += 1;
			break;
		case 'U':
			if (y > 0)y -= 1;
			break;
		case 'D':
			if (y < max_y)y += 1;
			break;
		default:
			break;
		}

	}
	cout << x+1 <<" " << y+1;
}