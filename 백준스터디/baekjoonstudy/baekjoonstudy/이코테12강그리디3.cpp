// �������� x�� ���谡�� �ݵ�� x������ ������ ���谡 �׷쿡 �����ؾ�
//���� �������ִ�.
//�ִ� ��׷��� ���谡�׷��� ������ �������ִ°�?

// ������, ������� ������ ���� ���ܽ��ѳ����鼭 ����������
//��������ϴ��� �˾ƺ��� ���� �������� �׸���˰���

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int temp;
vector<int> Fear;
int cnt;
int main() {
	cin >> n;
	for (; n > 0;n--) {
		
		cin >> temp;
		Fear.push_back(temp);
	}
	// �����Ͽ� �Ǿ��� ������ �ִ��� ����ŭ ���� �� �ִ��� Ȯ���� ������������ ������ �ٽ�
	sort(Fear.begin(), Fear.end());
	for (; Fear.empty() != true;) {
		int g = Fear.front();//����տ��ִ³��� ������ŭ �о��ֱ�
		if (g > Fear.size())break;//�������� �������� ������ �׷�α� ��
		for (; g != 0; g--) {
			Fear.pop_back();
		}
		cnt++;
	}
	cout << cnt;

}