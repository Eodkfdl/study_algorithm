//ù° �ٿ� �ڿ��� N(1 �� N �� 100, 000)�� �־�����.
//���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����.
//���� �ٿ��� M(1 �� M �� 100, 000)�� �־�����.
//���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�.
//��� ������ ������ - 2 ^ 31 ���� ũ�ų� ����2 ^ 31���� �۴�.== ��Ʈ�� ����

//Ǯ���Ҷ� ��������� : ���Ʈ����������� �����ߴ� �ð��ʰ� qsort ������ ���Ͽ� 
//sync_with_stdio()�� cin.tie(0);�� ���� �ð��ʰ������� �ذ��.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;

vector<int> A;
int M;
vector<int>B;

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tempn = 0;
	//�Է°��ޱ�
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> tempn;
		A.push_back(tempn);
	}
	//������ ����

	sort(A.begin(), A.end());


	cin >> M;
	//
	for (int i = 0; i < M; i++) {
		cin >> tempn;
		if (binary_search(A.begin(), A.end(), tempn))cout << 1 << "\n";
		else cout << 0 << "\n";

	}




}