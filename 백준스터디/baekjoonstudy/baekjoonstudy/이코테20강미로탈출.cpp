//NxMũ���� ����������� �̷�, 0���ԺҰ� 1���԰��� 
//1,1�������� ������ N,M�� �ⱸ����

#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int n, m;
int maze[201][201];


struct point {
	int y,x, depth;
};
queue<point> v;
//�ð��� ���� ���� �ʰ� �ִܰŸ��� �˷��� dfs���ٴ� bfs�� �´� �� ? dfs�� �ִܰŸ���� �����ϱ�����



int main() {
std::cin >> n >> m;

for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
		scanf_s("%1d", &maze[i][j]);
	}
}
point p;
p.x = 0;
p.y = 0;
p.depth = 1;
v.push(p);
maze[0][0]= 0;

while (!v.empty()){
	//x,y �ޱ�
	
	p = v.front();
	if (p.x == m -1&& p.y == n-1){
	
		break;
	}
	v.pop();
	//4�� �������� �湮���Ѱ� ã��  
	if (maze[p.y + 1][p.x] != 0&&(p.x>0||p.x<=n||p.y+1>0||p.y+1<=m)) {
		v.push({ p.y + 1,p.x,p.depth+1 });
		maze[p.y + 1][p.x] = 0;
	}
	if (maze[p.y -1][p.x] != 0 && (p.x > 0 || p.x <= n || p.y-1>0 || p.y-1 <= m)) {
		v.push({ p.y-1 ,p.x ,p.depth + 1 });
		maze[p.y -1][p.x] = 0;
	}
	if (maze[p.y ][p.x+1] != 0 && (p.x +1> 0 || p.x+1 <= n || p.y>0 || p.y <= m)) {
		v.push({ p.y ,p.x+1 ,p.depth + 1 });
		maze[p.y ][p.x+1] = 0;
	}
	if (maze[p.y ][p.x-1] != 0 && (p.x -1> 0 || p.x -1<= n || p.y>0 || p.y <= m)) {
		v.push({ p.y ,p.x-1,p.depth + 1 });
		maze[p.y ][p.x-1] = 0;
	}
	
}



	std::cout << p.depth  << std::endl;




}