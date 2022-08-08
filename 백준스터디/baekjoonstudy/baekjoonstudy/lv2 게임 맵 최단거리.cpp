#include<vector>
#include<queue>
#include<iostream>

using namespace std;
//�����¿� ó��
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

int bfs(vector<vector<int>>& maps) {
    //ť�� ó����� ���� �湮ó��
    //���Ե� ����� �α� ���(������ ���� ���)���� ť�� ���� �湮ó��
    //�ݺ�
    queue<pair<int, int>> q;

    int sizey = maps.size();
    int sizex = maps[0].size();
    int dis[100][100] = { 0, };
    q.push({ 0,0 });
    maps[0][0] = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        //p�� ���� �¿쿡 ���Ͽ� ����(mxn��������)���̸� �ش��ε����� maps�� ���� 1�̶�� �� �̹湮�Ѱ�
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
    //�ִܰŸ� bfs
    //�����Ҽ� ���� ��찡 ������

    answer = bfs(maps);

    return answer;
}

int main() {
    vector<vector<int>> maps;
    int n, m;
    cin >> n >> m;
    vector<int>v;
    //maps Ʋ�����
    for (int i = 0; i < n; i++) {
        maps.push_back(v);
        for (int j = 0; j < m; j++) {
            maps[i].push_back(0);
        }
    }
    //������ �ٴ����� �Է¹ޱ�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &maps[i][j]);
        }
    }
    cout << bfs(maps);
}