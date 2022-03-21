// NxM크기의 얼음틀이 있다. 구멍이 뚫려 있는 부분은 0 칸막이가 존쟇는 부분으 1로 표시된다
// 0끼리 붙어있는 경우 서로 연결되어 있는것으로 간주한다.  커넥티드 컴포넌트 찾기
//입력조건 n과 M이 주어지고 1<= n,m<= 1,000 두번째줄 부터 n+1번째 줄까지는 얼음틀의 형태가 주어진다.
//구멍이 뚫린 부분은 0 그렇지 않은부분은 1 이다. 한번에 만들수 있는 아이스크림 갯수를 출력하라

//왜dfs로 푸는가? 
#include<iostream>
#include<vector>
using namespace std;
int n, m;
int cnt;//아이스크림갯수
bool t;
bool ice[10000][10000];//맵정보

bool dfs(int x,int y) {
	if (x<0 || x>n || y<0 || y>m)return false;// x,y가 범위 밖이라면 false리턴

	if (ice[x][y] != 1) {//방문하지않은곳이라면 
		ice[x][y] = 1;//방문처리
	
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



	for (int i = 0; i < n; i++) {//최대사이즈내의 모든 노드를 dfs에 넣어 탐색시킨다.
		for (int j = 0; j < m; j++) {
			if (dfs(i, j))cnt++;//방문 
		}
	}


	cout << cnt << endl;

}