//NxM크기의 직사격형태의 미로, 0진입불가 1진입가능 
//1,1에서부터 시작해 N,M에 출구존재

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
//시간에 구애 받지 않고 최단거리를 알려면 dfs보다는 bfs가 맞다 왜 ? dfs는 최단거리라는 보장하기힘듬



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
	//x,y 받기
	
	p = v.front();
	if (p.x == m -1&& p.y == n-1){
	
		break;
	}
	v.pop();
	//4방 가능한지 방문안한곳 찾고  
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