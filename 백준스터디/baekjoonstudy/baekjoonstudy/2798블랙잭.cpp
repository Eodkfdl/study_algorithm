#include<iostream>
using namespace std;
//n장의카드 각각 양의정수가 적혀있다 수는 랜덤이지만 3개의합이 m 이하의 수가 나오게 주어짐. n의 개수는 3~100사이
// 10<= M <= 300,000 이주어진다
//첫입력으론 n의 갯수 m의값이주어지고
//두번째입력으로 n의 값들을 넣어준다.

//정렬이필요한가? 정렬없이 하는방법과 정렬하고 하는방법의 속도차이?

//정렬없이 해보기
//1. n의 갯수와 m을 입력받는다.
//2. n의 갯수 만큼 n의 리스트를 만든다.
//3. n+i, n+j, n+k를 더한후 m과 비교 m보다 작다면 a에 저장(i<j<k n+k<=num_n) 3중포문 ijk순으로
//4. n+i, n+j, n+k를 더한후 m과 비교 m보다 작다면 저장된 a보다 크면 a에저장
//5. 저장된 a의 값을 내보냄

int n_num;//n의 갯수
int m;//m의값
int a;// 저장되어 출력되어질 값
int temp;//비교연산을 위한 변수
int n[100];//n의 집합

int main() {
	//1. n의 갯수와 m을 입력받는다.
	cin >> n_num >> m;
	//2. n의 갯수 만큼 n의 리스트를 만든다
	for (int i = 0; i < n_num; i++) {
		cin >> a;
		n[i] = a;
	}

	//3. n+i, n+j, n+k를 더한후 m과 비교 m보다 작다면 a에 저장(i<j<k n+k<=num_n) 3중포문 ijk순으로

	for (int i = 0; i < n_num; i++) {
		for (int j = i+1; j < n_num; j++) {
			for (int k = j+1; k < n_num; k++) {
				temp = n[i] + n[j] + n[k];
				//4. n+i, n+j, n+k를 더한후 m과 비교 m보다 작다면 저장된 a보다 크면 a에저장
				if (temp <= m && a < temp)
					a = temp;
			}
		}
	}

//5. 저장된 a의 값을 내보냄
	cout << a;
}