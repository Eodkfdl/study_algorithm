#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int> > adj = { {}, {1,2,3,4},{1,3,4},{1},{1,2} };//�׷����� ���� ����Ʈ ǥ��
vector<int> dis(adj.size()+1, -1); //�� ������ �ִ� �Ÿ�


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
            //here�� �������� there�� ���Ͽ�
            int there = adj[here][i - 1];
            //�湮������ ���� ������ �Ÿ��� -1�̹Ƿ� �湮���� ���� �� �̶��
            if (dis[there] == -1) {
                //�ش��带 �����̾�Ƽť�� ���
                pq.push(there);
                //�湮ó���� �Բ� �������� �Ÿ��� �������ش�.
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