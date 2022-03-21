#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



//정수 n이 주어졌을때 1,2,3의 합으로 나타내는 방법의 개수를 구하여라 수는 1개이상 사용해야한다
int n_testcase=0;
vector<int>testcase;
int temp;

int nCm(int n, int m) {
	int ret=1;
	int temp=1;
	int j = 0;
	// 4 2 
	// nCm = n*n-1....n-m/m*m-1...1
	for (int i = m; i > 0; i--) {

		ret = ret * (n - j); // 4 * 3
		temp = temp * i;// 2 1
		j++;
	}
	ret = ret / temp;
	
	return ret;
}

int main() {
	//테스트케이스의 수와 케이스를 입력받는다
	cout << nCm(4, 2) << endl;
	cout << nCm(6, 3) << endl;
	cout << nCm(8, 2) << endl;

	cin >> n_testcase;
	for (int i = 0; i < n_testcase; i++) {
		cin >> temp;
		testcase.push_back(temp);
	}
	
	// 2== 1+1 3== 1+2 == 1+1+1으로 표현될수 있다. 사실상 정수n은 n개의 1로 이루어져 있으며
	// 1과 2로만 표현될경우 n-1개가 될때마다 2의 갯수가 늘어난다
	// 위와 같이 1과 3으로만 표현 될경우 n-2가될때마다 3의 갯수가늘어난다.
	// 따라서 경우를 나누어서  
	// 
	//1. 1,2,3만있는경우 == 1 은무조건있고 2와 3으로 나누어서 떨어질경우
	//2. 1+2의 조합인경우 2가 한개인경우 n-1C1 두개인경우 n-2C2 즉 2의갯수가 m개인경우 n-mCm개 의경우가생김
	//3. 1+3의 조합인경우 같은방식으로 n-2mCm
	//4. 2+3의 조합의경우  1개만 3인경우  2의갯수 n-2/2 , 조합의 갯수는 n-2/2C1 2개만 3인경우 2의 갯수 n-4/2 , n-4/2C2 
	// .... 3이 m개일때 n-2m/2 C m
	//5. 1+2+3의 조합의경우 2+3조합의갯수 * 1의갯수 n, 2의 갯수+3의갯수 m  mCn
	//  2+3조합을 만든후 각각의 자리에 1이 들어갈수 있는경우의 수를 곱해주면 모든경우수의가 나온다.
	// ex)7을 1+2+3 으로 표현하면  2 3 1 1 / 2+3의 조합 2 3  ,3 2 / m이 2+3의조합의 자리라고 하면
	//  m 1 1 ,1 m 1 1 ,1 1 m  => 2*3 = 6 
	
	// 각각 12345의 방법을 통해 모든 경우의 수를 구한 후 다 더해주자.
	
	int case_n;
	int maxcount_1;
	int maxcount_2;
	int maxcount_3;
	int temp;
	
	for (auto t : testcase) {
		case_n = 0;
	
		maxcount_1 = t;
		maxcount_2 = t / 2;
		maxcount_3 = t / 3;
		
		//1: 1, 2, 3으로 나누어 떨어지는경우 1111 3333 경우가있다.
		case_n += 1;
		if (t % 2 == 0)case_n += 1;
		if (t % 3 == 0)case_n += 1;

		//2:
		for (int i = 1; i < maxcount_2 + 1; i++) {
			temp = t - i;// 1의갯수

			case_n += nCm(temp+i, i);//

		}
		//3:
		for (int i = 1; i < maxcount_3 + 1; i++) {
			temp = t - 2 * i;
			case_n += nCm(temp+i, i);
		}

		//4: 짝수인경우 3이 최소 2개 홀수인경우 3이 1개부터 시작가능함.
		// 2로 나누어 나머지 1이나오면 3의 갯수는 1개 부터 0이 나오면 2개부터 시작된다.
		temp = t % 2;
		if (temp == 0)temp = 2;
		for (int i = temp; i < maxcount_3; i++) {//최대 3의갯수보다 작게 3의 갯수가 증가, 
			temp = (t - i * 3) / 2;//temp는 2의 갯수 , 2의 갯수는 정수 t - 3의 갯수를 2로나눈 몫
			case_n += nCm(temp, i);
		}

		//5: 1+2+3의 경우 2중포문을 이용하여 1의갯수 / 2,3의 조합의수를 나누어 생각한다.
		
		for (int i = 1; i < t; i++) {
			maxcount_1 = t - i;//1의 갯수는 i ,maxco1unt_1에 2와 3의 조합으로 만들어 질 수를 저장해둔다.

			temp = maxcount_1 / 2;
			if (temp == 0)temp = 2;
			maxcount_3 = maxcount_1 / 3;//3의갯수
			for (int j = temp; j < maxcount_3; j++) {
				temp = (maxcount_1 - i * 3)/2;//2의갯수
				
			   case_n= nCm(temp+j+i,i)*nCm(temp, j);
			}
		}
		cout << case_n << "\n";
		

	}




}