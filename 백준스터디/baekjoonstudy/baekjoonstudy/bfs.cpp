#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int> > adj = { {}, {1,2,3,4},{1,3,4},{1},{1,2} };//그래프의 인접 리스트 표현
vector<int> dis(adj.size()+1, -1); //각 정점의 최단 거리


int bfs(int start) {
    queue<int> q;
  
  
    dis[start] = 0;

    q.push(start);
    while (!q.empty()) {
        int here = q.front();
        q.pop();
    
        for (int i = 1; i < adj[here].size()+1; ++i) {
            int there = adj[here][i-1];
            if (dis[there] == -1) {
                q.push(there);
                dis[there] = dis[here] + 1;
             
            }
        }
    }
    return dis[4];
}
int Dijkstra(int start) {
    priority_queue<int>pq;
    dis[start] = 0;
    pq.push(start);
    int here = 0; 
    while (!pq.empty()) {
        
        here=pq.top();
        pq.pop();
        for (int i=1; i < adj[here].size() + 1; ++i) {
            //here의 인접노드들 there에 대하여
            int there = adj[here][i - 1];
            //방문한적이 없는 노드들은 거리가 -1이므로 방문하지 않은 곳 이라면
            if (dis[there] == -1) {
                //해당노드를 프라이어티큐에 담고
                pq.push(there);
                //방문처리와 함께 이전노드와 거리를 저장해준다.
                dis[there] = dis[here] + 1;
            }
        }
    }

    return dis[4];
}
int a_star(int start) {

}
int main() {
    int n = 0;
    cin >> n;

    int bf =bfs(1);
    int di = Dijkstra(1);
     cout << bf<<" "<<di << " ";
}