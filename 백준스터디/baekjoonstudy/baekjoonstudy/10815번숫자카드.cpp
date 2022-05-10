/*
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다.
정수 M개가 주어졌을때 , 이수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을작성하시오
첫재쭐에는 상근이가 가지고 있는 숫자 카드 갯수 N 두번째에는 숫자카드
세번째에는 정수 갯수 M개 네번째에는 정수들이 주어진다.
시간제한 2초 메모리제한 256MB
*/

//인서트를 n번 탐색을 m번해야한다 , 시간제한 2초 256mb의 넉넉한 메모리 
//따라서  insert와 search 시간복잡도가 낮은 자료구조를 사용
//set은 binary search tree이기때문에 O(logn)의 탐색과 인서트 시간복잡도를 갖는다.
#include<iostream>
#include<set>
#include<string>
using namespace std;
int m,n;
int temp;
set<int> N;
string output;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		N.insert(temp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (N.count(temp) > 0)output += "1 ";
		else output += "0 ";

	}
	cout << output << endl;

}
