// NxMũ���� ����Ʋ�� �ִ�. ������ �շ� �ִ� �κ��� 0 ĭ���̰� ���K�� �κ��� 1�� ǥ�õȴ�
// 0���� �پ��ִ� ��� ���� ����Ǿ� �ִ°����� �����Ѵ�.  Ŀ��Ƽ�� ������Ʈ ã��
//�Է����� n�� M�� �־����� 1<= n,m<= 1,000 �ι�°�� ���� n+1��° �ٱ����� ����Ʋ�� ���°� �־�����.
//������ �ո� �κ��� 0 �׷��� �����κ��� 1 �̴�. �ѹ��� ����� �ִ� ���̽�ũ�� ������ ����϶�

//��dfs�� Ǫ�°�? 
#include<iostream>
#include<vector>
using namespace std;
int n, m;
int cnt;//���̽�ũ������
bool t;
bool ice[10000][10000];//������

bool dfs(int x,int y) {
	if (x<0 || x>n || y<0 || y>m)return false;// x,y�� ���� ���̶�� false����

	if (ice[x][y] != 1) {//�湮�����������̶�� 
		ice[x][y] = 1;//�湮ó��
	
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
		
		return true;
	}
	
	

	return false;
}

int main() {

	cin >> n >> m;
	for (int i = 0; i<n; i ++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &ice[i][j]);
		}
	}



	for (int i = 0; i < n; i++) {//�ִ������� ��� ��带 dfs�� �־� Ž����Ų��.
		for (int j = 0; j < m; j++) {
			if (dfs(i, j))cnt++;//�湮 
		}
	}


	cout << cnt << endl;

}