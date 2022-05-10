/*
���� ī��� ���� �ϳ��� ������ �ִ� ī���̴�. ����̴� ���� ī�� N���� ������ �ִ�.
���� M���� �־������� , �̼��� �����ִ� ���� ī�带 ����̰� ������ �ִ��� �ƴ����� ���ϴ� ���α׷����ۼ��Ͻÿ�
ù���ῡ�� ����̰� ������ �ִ� ���� ī�� ���� N �ι�°���� ����ī��
����°���� ���� ���� M�� �׹�°���� �������� �־�����.
�ð����� 2�� �޸����� 256MB
*/

//�μ�Ʈ�� n�� Ž���� m���ؾ��Ѵ� , �ð����� 2�� 256mb�� �˳��� �޸� 
//����  insert�� search �ð����⵵�� ���� �ڷᱸ���� ���
//set�� binary search tree�̱⶧���� O(logn)�� Ž���� �μ�Ʈ �ð����⵵�� ���´�.
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
