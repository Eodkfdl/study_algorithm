#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    //전체 사각형은 50,50범위 내에있지만 겹침 문제를 해결하기위해 맵의 크기는 100x100
    vector<vector<int>>map(110, vector<int>(110, -1));

    //겹침문제를 해결하기위해 사각형들의 좌표,캐릭터 아이탬의 좌표를 2배로 해주어야한다.
    //좌하단:x1,y1 좌상단x2 y2 원점을 0,0으로하는 1사분면내의 좌표이므로
    //x1<x2, y1<y2
  //  characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    //사각형의 안쪽은 0으로 채우고 외곽은 1로 채운다.
    for (auto& t :  rectangle) {
      //  for (int k = 0; k < 4; k++)t[k] *= 2;
        for (int i = t[1]; i <= t[3]; i++) {
            for (int j = t[0]; j <= t[2]; j++) {
                //사각형의 외각선이 겹치는 점에서 외부(1)로 처리해야 외각선을 타고 움직 일 수 있다. 
                map[i][j] = 1;

            }
        }
     
    }
    for (auto t : rectangle) {
       // for (int k = 0; k < 4; k++)t[k] *= 2;

        for (int i = t[1] + 1; i < t[3]; i++) {
            for (int j = t[0] + 1; j < t[2]; j++) {
                map[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map.size(); j++) {
            if (map[i][j] == -1)cout << "*";
            else if (i == characterX && j == characterY)cout << "!";
            else if (i == itemX && j == itemY)cout << "!";
            else cout << map[i][j];
        }
        cout << endl;
    }
    queue<pair<int, int>> q;

    q.push({ characterY,characterX });
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        if (temp.first == itemY && temp.second == itemX) {
            answer = map[temp.first][temp.second] / 2;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = temp.first + dy[i];
            int nx = temp.second + dx[i];
            if (map[ny][nx] == 1) {
                q.push({ ny,nx });
                map[ny][nx] = map[temp.first][temp.second] + 1;
            }
        }

    }

    return answer;
}

int cx, cy, ix, iy, n,x1;
int main() {
    
    cin >> cx>>cy>>ix>>iy>>n;
   vector<vector<int>>t(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> x1;
            t[i].push_back(x1);
        }
    }
    cout<<solution(t,cx,cy,ix,iy);
}