#include<iostream>
#include<stack>
#include<vector>

using namespace std;
vector<vector<int> > adj = { {}, {2,3},{1,3,4},{1},{2} };//그래프의 인접 리스트 표현
vector<int> dis(adj.size() + 1, 0); //각 정점의 최단 거리
vector<bool>is_visit(adj.size() + 1, false);
int dfs_stack(int start) {
	stack<int> s;
	s.push(start);
	dis[start] = 0;
	int here = 0;

	while (!s.empty()) {
		here = s.top();
				s.pop();
				for (int i = 1; i < adj[here].size() + 1; i++) {
					if (dis[i] == -1) {
						s.push(i);
						dis[i] = dis[here] + 1;
					}
				}
				
	}
	return dis[4];
}
int dfs_recursive(int cur, int dist) {
	
	for (auto t : adj[cur]) {
		if (is_visit[t] == false) {//방문한적이없는곳이라면
			cout << "cur : " << t << " ";
			dis[t] = dis[cur]+1;
			is_visit[t] = true;
			dfs_recursive(t, dis[t]);
		}
	}
	return dis[4];
}
int main() {
	is_visit[1] = true;
	cout << dfs_recursive(1, 0);
}