
//상하좌우 1,2,3,4;
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int max_x, max_y;
//한사이클의 판단-이동 시작점->중간점->끝점 같은가? 같으면 한사이클
   //이동경로,이동거리 저장;
//주어진 vector<string>은사실상 vector<vector<char>>
//즉 2차원배열로 표현 가능함.

//상하좌우 1,2,3,4;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool visit[500][500][5];//그리드는 최대[500][500]의 행렬이고 해당 포인트로 들어오는 방향은 4방향 이므로 [4]
int c_dir(int dir, char c) {
    //현재의 dir, grid의 방향에따라 알맞은 방향을 준다.
    //그리드가 Left일경우
    if (c == 'L') {
        if (dir == 0)return 2;
        if (dir == 1)return 3;
        if (dir == 2)return 1;
        if (dir == 3)return 0;
    }
    else {
        //grid가 right인경우
        if (dir == 0)return 3;
        if (dir == 1)return 2;
        if (dir == 2)return 0;
        if (dir == 3)return 1;
    }
}
//빛이 시작하는 point(x,y)와 해당 빛의 시작방향에 따라 구분이 됨

int searching(int y, int x, int dir, int len, vector<string>& grid) {
    //방문한곳이라면 사이클이 완성되었으므로 길이 반환
    if (visit[y][x][dir] == true)return len;
    //방문처리
    visit[y][x][dir] = true;
    //방문하지않은곳이라면 해당 위치의 grid값을보고 다음 dir을 구하고 이동위치를 구해주고 len+1 
    if (grid[y][x] != 'S')dir = c_dir(dir, grid[y][x]);
    y = y + dy[dir];
    x = x + dx[dir];
    //y==max_gridy || y==min_gridx인경우
    if (y < 0)y = max_y - 1;
    if (y == max_y)y = 0;
    //y==max_gridy || y==min_gridx인경우
    if (x < 0)x = max_x - 1;
    if (x == max_x)x = 0;
    len += 1;
    return searching(y, x, dir, len, grid);

}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    max_y = grid.size();
    max_x = grid[0].size();
    int dir_n = 4;
    int len = 0;//탐색을 통해 리턴받은 사이클의 길이

    for (int i = 0; i < max_y; i++) {
        for (int j = 0; j < max_x; j++) {
            for (int k = 0; k < dir_n; k++) {
                len = searching(i, j, k, 0, grid);
                if (len > 0)answer.push_back(len);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;

}
string s;
int n;
vector<string>grid;
int main() {
    
    cin >> n;
    for (; n > 0; n--) {
        cin >> s;
        grid.push_back(s);
    }
    vector<int>answer;
    answer = solution(grid);
    for (auto t : answer) {
        cout << t;
    }
}