/*
ù���ٿ� ���� ���� N�� ��û�� ���� ���� M�� �־�����.(1<N<= 1,000,000 1<=M<=2,000,000,000)
��°�ٿ��� ���� ���� ���� ���̰� �־����ϴ� �������� ������ �׻� M�̻��̹Ƿ� �մ��� �ʿ��� �縸ŭ
���� �簥�� �ִ� ���̴� 10�ﺸ�� �ۤ��ų� ���� ���� ���� �Ǵ� 0�Դϴ�.
���� H�� �ָ� H�̻��� ���̸� ���� ���� ��������ŭ �߸���.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M; 

int temp, sum;
vector<int>R;//ricecake



int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		R.push_back(temp);
	}
	//�ѹ�����
	sort(R.begin(), R.end());
	
	int start = R.front();
	int end = *(R.end()-1);

	while (start<=end){
		int mid = (start + end) / 2;
		sum = 0;
		for (int i = 0; i < N; i++) {
			if(R[i]>mid)sum += R[i] - mid;
		}
		if (sum < M) {
			end = mid - 1;
		}
		else if (sum >= M) {
			start = mid + 1;
			temp = mid;
			
		}


	}
	cout << temp << endl;
}