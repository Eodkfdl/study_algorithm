#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//���� S �� �־������� ���� S�� �κ� ������ ������ ���� �� ���� ���� ���� �ڿ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�
//������� S = { 5, 1 ,2 }�� ��쿡 1,2,3(1+2), 5, 6(1+5) 7(=2+5) 8(=1+2+5)�� ����� �ִ�. ������ 4�� ����� ���� ������ ������ 4�̴�.

//�޸� 512mb �ð����� 2�� -> �޸𸮴� ����� �а� �ᵵ �������
int sizeS;
vector<unsigned int> S;
vector<unsigned int> S_sum;

void sum(int i, vector<unsigned int> *s, vector<unsigned int> *s_sum) {

	unsigned int temp=0;
	unsigned int sum_temp=0;

	auto iter= s->begin();
	//1. s�� ���ۺ��� i �� ��ŭ�� ���Ѽ��� s_sum�������Ѵ�
	
	//2. s�� ����+1���� i���� ���Ѽ��� s_sum�������Ѵ�.... 
	// i���� ���Ѵ� ���� n+i��° ���� ���������� ����Ų��.
	

	
}
void sum2(int i, unsigned int* s, unsigned int* s_sum,unsigned int& temp) {
	//i = ó�� �����ϴ� ���� ���� ���������ִ� �ִ� 
	
	unsigned int b = *s;
	unsigned int * d = s + 1;

	for (int a = 0; a < i; a++) {
		sum2(i-1,s+a,s_sum, *(s+a)+ temp)
	}
	
}

int main(){
	
	//������ ũ�� N�� �־�����.(1<=N<=20)
	cin >> sizeS;
	unsigned int temp;
	//���� S�� �־�����. �̸� �̷�� �ִ� ���� 100,000���� �۰ų� ���� �ڿ����̴�(0�������� �������� ���� unsigned)
	for (int i = 0; i < sizeS; i++) {
		cin >> temp;
		S.push_back(temp);
	}
	//�־��� ������ �κ����� �ߺ����� ����,������������ �����Ѵ�.
	// 1,2,5, 3,6, 7,8
	// 1,2,5,7 /1+2 1+5 1+2 1+7 2+5 2+7 5+7/ 1+2+5 1+2+7 2+5+7/ 1+2+5+7
	// n���� ��쿡 ������ ���� �ڿ����� ������ 1�� , 2�� , 3�� ....n�� 
	// n���� �Ǿտ������� ���س�����.
	
	//����Լ��� �̿��ؼ� 
	sum(sizeS, &S, &S_sum);
	
	//������ �������� �ߺ��� �����ϰ� ������������ ����.
	sort(S_sum.begin(), S_sum.end());
	S_sum.erase(unique(S_sum.begin(), S_sum.end()), S_sum.end());
	//���ĵ� ������ �κ��տ��� ���� �������� �ڿ�����ã�´� 0�������ϰ�~
	auto iter = S_sum.begin();
	for (int i = 1; i < *S_sum.end(); i++) {
		 iter=find(S_sum.begin(), S_sum.end(), i);
		 if (iter == S_sum.end())cout << i << "\n";
		 
		 if (i == *S_sum.end())cout << i + 1 << "\n";
	}
}