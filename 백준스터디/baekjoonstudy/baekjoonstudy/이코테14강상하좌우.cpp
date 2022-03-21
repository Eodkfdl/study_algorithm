//NxN크기의 정사각형 공간, 가장 왼쪽위 좌표는 1,1이며 가장오른쪽 아래좌표는 N,N 
// 

#include<iostream>


using namespace std;

int max_x, max_y;
int x, y;
char plan[100];


int main() {

	cin >> max_x ;
	//1,1 이 원점이므로 계산상편의를 위해 0,0이 원점이 되도록 평행이동
	max_x -= 1;
	max_y = max_x;
	cin.ignore();//버퍼비우기 서로다른 자료형 현재는 정수,문자열을 cin을 통해 받기때문에 버퍼를 한번 비워줄필요가있음
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