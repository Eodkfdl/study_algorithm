#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//수열 S 가 주어졌을때 수열 S의 부분 수열의 합으로 나올 수 없는 가장 작은 자연수를 구하는 프로그램을 작성하시오
//예를들어 S = { 5, 1 ,2 }인 경우에 1,2,3(1+2), 5, 6(1+5) 7(=2+5) 8(=1+2+5)를 만들수 있다. 하지만 4는 만들수 없기 때문에 정답은 4이다.

//메모리 512mb 시간제한 2초 -> 메모리는 충분히 넓게 써도 상관없다
int sizeS;
vector<unsigned int> S;
vector<unsigned int> S_sum;

void sum(int i, vector<unsigned int> *s, vector<unsigned int> *s_sum) {

	unsigned int temp=0;
	unsigned int sum_temp=0;

	auto iter= s->begin();
	//1. s의 시작부터 i 개 만큼씩 더한수를 s_sum에저장한다
	
	//2. s의 시작+1부터 i개씩 더한수를 s_sum에저장한다.... 
	// i개씩 더한다 따라서 n+i번째 수는 마지막수를 가르킨다.
	

	
}
void sum2(int i, unsigned int* s, unsigned int* s_sum,unsigned int& temp) {
	//i = 처음 시작하는 갯수 이자 내려갈수있는 최대 
	
	unsigned int b = *s;
	unsigned int * d = s + 1;

	for (int a = 0; a < i; a++) {
		sum2(i-1,s+a,s_sum, *(s+a)+ temp)
	}
	
}

int main(){
	
	//수열의 크기 N이 주어진다.(1<=N<=20)
	cin >> sizeS;
	unsigned int temp;
	//수열 S가 주어진다. 이를 이루고 있는 수는 100,000보다 작거나 같은 자연수이다(0을포함한 양의정수 따라서 unsigned)
	for (int i = 0; i < sizeS; i++) {
		cin >> temp;
		S.push_back(temp);
	}
	//주어진 수열의 부분합을 중복없이 저장,오름차순으로 정렬한다.
	// 1,2,5, 3,6, 7,8
	// 1,2,5,7 /1+2 1+5 1+2 1+7 2+5 2+7 5+7/ 1+2+5 1+2+7 2+5+7/ 1+2+5+7
	// n개의 경우에 덧셈에 들어가는 자연수의 갯수가 1개 , 2개 , 3개 ....n개 
	// n개씩 맨앞에서부터 더해나간다.
	
	//재귀함수를 이용해서 
	sum(sizeS, &S, &S_sum);
	
	//더해진 수열에서 중복을 제거하고 오름차순으로 정렬.
	sort(S_sum.begin(), S_sum.end());
	S_sum.erase(unique(S_sum.begin(), S_sum.end()), S_sum.end());
	//정렬된 수열의 부분합에서 없는 가장작은 자연수를찾는다 0을제외하고~
	auto iter = S_sum.begin();
	for (int i = 1; i < *S_sum.end(); i++) {
		 iter=find(S_sum.begin(), S_sum.end(), i);
		 if (iter == S_sum.end())cout << i << "\n";
		 
		 if (i == *S_sum.end())cout << i + 1 << "\n";
	}
}