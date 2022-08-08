#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    //��ü �簢���� 50,50���� ���������� ��ħ ������ �ذ��ϱ����� ���� ũ��� 100x100
    vector<vector<int>>map(110, vector<int>(110, -1));

    //��ħ������ �ذ��ϱ����� �簢������ ��ǥ,ĳ���� �������� ��ǥ�� 2��� ���־���Ѵ�.
    //���ϴ�:x1,y1 �»��x2 y2 ������ 0,0�����ϴ� 1��и鳻�� ��ǥ�̹Ƿ�
    //x1<x2, y1<y2
  //  characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    //�簢���� ������ 0���� ä��� �ܰ��� 1�� ä���.
    for (auto& t :  rectangle) {
      //  for (int k = 0; k < 4; k++)t[k] *= 2;
        for (int i = t[1]; i <= t[3]; i++) {
            for (int j = t[0]; j <= t[2]; j++) {
                //�簢���� �ܰ����� ��ġ�� ������ �ܺ�(1)�� ó���ؾ� �ܰ����� Ÿ�� ���� �� �� �ִ�. 
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