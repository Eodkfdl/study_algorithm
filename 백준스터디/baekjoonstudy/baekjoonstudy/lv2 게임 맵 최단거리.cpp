#include<vector>
#include<queue>
#include<iostream>

using namespace std;
//상하좌우 처리
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

int bfs(vector<vector<int>>& maps) {
    //큐에 처음노드 삽입 방문처리
    //삽입된 노드중 인근 노드(가보지 않은 노드)전부 큐에 삽입 방문처리
    //반복
    queue<pair<int, int>> q;

    int sizey = maps.size();
    int sizex = maps[0].size();
    int dis[100][100] = { 0, };
    q.push({ 0,0 });
    maps[0][0] = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        //p의 상하 좌우에 대하여 범위(mxn내부인지)내이며 해당인덱스의 maps의 값이 1이라면 갈 미방문한곳
        for (int i = 0; i < 4; i++) {
            int py = p.first + dy[i];
            int px = p.second + dx[i];
            if (py > -1 && py<sizey && px>-1 && px < sizex) {
                if (maps[py][px] == 1) {
                    maps[py][px] = 0;
                    q.push({ py,px });
                    dis[py][px] = dis[p.first][p.second] + 1;
                }
            }
        }


    }

    if (dis[sizey - 1][sizex - 1] == 0)return -1;
    return dis[sizey - 1][sizex - 1] + 1;

}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    //최단거리 bfs
    //도달할수 없는 경우가 존재함

    answer = bfs(maps);

    return answer;
}

int main() {
    vector<vector<int>> maps;
    int n, m;
    cin >> n >> m;
    vector<int>v;
    //maps 틀만들기
    for (int i = 0; i < n; i++) {
        maps.push_back(v);
        for (int j = 0; j < m; j++) {
            maps[i].push_back(0);
        }
    }
    //데이터 줄단위로 입력받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &maps[i][j]);
        }
    }
    cout << bfs(maps);
}