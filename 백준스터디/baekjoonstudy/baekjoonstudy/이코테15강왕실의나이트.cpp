// 8x8 좌표평면위의 나이트는 L자혀애로만 이동할수 있습니다.
//나이트는 특정위치에서 다음과 같이 이동할수있습니다.
//1,2 수평으로두칸 이동뒤 수직으로 한칸이동하기 
//2. 수직으로 두칸이동한뒤 수평으로 한칸이동하기
// 나이트의 위치가 주어졌을떄 해당 말이 이동 할수 있는 경우의 수를 표현합니다.
//행은 abcdefgh 열은 12345678로 

#include<iostream>

using namespace std;


char p[2];
int x, y;
int cnt;
int main() {
	cin >> p;
	//a=97
	//0=80
	x = p[1] - 49;
	y = p[0] - 97;
	
	for (int i = -2; i < 3; i++) {
		for (int j = -2; j < 3; j++) {
			
			if (i != 0 && j != 0) {

				if (abs(i) != abs(j)) {
					if (x+i > -1 && x+i < 9) {
						if (y+j > -1 && y+j < 9) {
							cnt++;

						}
					}
				}

			}

		}


	}
	cout << cnt;
}