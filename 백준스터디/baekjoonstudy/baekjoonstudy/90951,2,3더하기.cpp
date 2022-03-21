#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



//���� n�� �־������� 1,2,3�� ������ ��Ÿ���� ����� ������ ���Ͽ��� ���� 1���̻� ����ؾ��Ѵ�
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
	//�׽�Ʈ���̽��� ���� ���̽��� �Է¹޴´�
	cout << nCm(4, 2) << endl;
	cout << nCm(6, 3) << endl;
	cout << nCm(8, 2) << endl;

	cin >> n_testcase;
	for (int i = 0; i < n_testcase; i++) {
		cin >> temp;
		testcase.push_back(temp);
	}
	
	// 2== 1+1 3== 1+2 == 1+1+1���� ǥ���ɼ� �ִ�. ��ǻ� ����n�� n���� 1�� �̷���� ������
	// 1�� 2�θ� ǥ���ɰ�� n-1���� �ɶ����� 2�� ������ �þ��
	// ���� ���� 1�� 3���θ� ǥ�� �ɰ�� n-2���ɶ����� 3�� �������þ��.
	// ���� ��츦 �����  
	// 
	//1. 1,2,3���ִ°�� == 1 ���������ְ� 2�� 3���� ����� ���������
	//2. 1+2�� �����ΰ�� 2�� �Ѱ��ΰ�� n-1C1 �ΰ��ΰ�� n-2C2 �� 2�ǰ����� m���ΰ�� n-mCm�� �ǰ�찡����
	//3. 1+3�� �����ΰ�� ����������� n-2mCm
	//4. 2+3�� �����ǰ��  1���� 3�ΰ��  2�ǰ��� n-2/2 , ������ ������ n-2/2C1 2���� 3�ΰ�� 2�� ���� n-4/2 , n-4/2C2 
	// .... 3�� m���϶� n-2m/2 C m
	//5. 1+2+3�� �����ǰ�� 2+3�����ǰ��� * 1�ǰ��� n, 2�� ����+3�ǰ��� m  mCn
	//  2+3������ ������ ������ �ڸ��� 1�� ���� �ִ°���� ���� �����ָ� �������ǰ� ���´�.
	// ex)7�� 1+2+3 ���� ǥ���ϸ�  2 3 1 1 / 2+3�� ���� 2 3  ,3 2 / m�� 2+3�������� �ڸ���� �ϸ�
	//  m 1 1 ,1 m 1 1 ,1 1 m  => 2*3 = 6 
	
	// ���� 12345�� ����� ���� ��� ����� ���� ���� �� �� ��������.
	
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
		
		//1: 1, 2, 3���� ������ �������°�� 1111 3333 ��찡�ִ�.
		case_n += 1;
		if (t % 2 == 0)case_n += 1;
		if (t % 3 == 0)case_n += 1;

		//2:
		for (int i = 1; i < maxcount_2 + 1; i++) {
			temp = t - i;// 1�ǰ���

			case_n += nCm(temp+i, i);//

		}
		//3:
		for (int i = 1; i < maxcount_3 + 1; i++) {
			temp = t - 2 * i;
			case_n += nCm(temp+i, i);
		}

		//4: ¦���ΰ�� 3�� �ּ� 2�� Ȧ���ΰ�� 3�� 1������ ���۰�����.
		// 2�� ������ ������ 1�̳����� 3�� ������ 1�� ���� 0�� ������ 2������ ���۵ȴ�.
		temp = t % 2;
		if (temp == 0)temp = 2;
		for (int i = temp; i < maxcount_3; i++) {//�ִ� 3�ǰ������� �۰� 3�� ������ ����, 
			temp = (t - i * 3) / 2;//temp�� 2�� ���� , 2�� ������ ���� t - 3�� ������ 2�γ��� ��
			case_n += nCm(temp, i);
		}

		//5: 1+2+3�� ��� 2�������� �̿��Ͽ� 1�ǰ��� / 2,3�� �����Ǽ��� ������ �����Ѵ�.
		
		for (int i = 1; i < t; i++) {
			maxcount_1 = t - i;//1�� ������ i ,maxco1unt_1�� 2�� 3�� �������� ����� �� ���� �����صд�.

			temp = maxcount_1 / 2;
			if (temp == 0)temp = 2;
			maxcount_3 = maxcount_1 / 3;//3�ǰ���
			for (int j = temp; j < maxcount_3; j++) {
				temp = (maxcount_1 - i * 3)/2;//2�ǰ���
				
			   case_n= nCm(temp+j+i,i)*nCm(temp, j);
			}
		}
		cout << case_n << "\n";
		

	}




}