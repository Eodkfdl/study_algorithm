
/*
N���� ���Ҹ� �����ϰ� �ִ� ������ ������������ ���ĵǾ������� �̼������� x�� �����ϴ� Ƚ���� ����Ͻÿ�
�� �̹����� �ð����⵵ O(logN)���� �˰����� �������������� �ð��ʰ� ������ �޽��ϴ�.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, x,temp;

vector<int>B;
int cnt_range(vector<int>& a, int leftv, int rightv) {
	vector<int>::iterator rightIndex = upper_bound(a.begin(), a.end(), rightv);
	vector<int>::iterator leftIndex = upper_bound(a.begin(), a.end(), leftv);
	return rightIndex - leftIndex;
}
int main() {
	cin >> N >> x;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		B.push_back(temp);
	}
	cout << cnt_range(B, x, x);
	

}