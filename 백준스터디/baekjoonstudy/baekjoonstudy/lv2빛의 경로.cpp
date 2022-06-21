
//�����¿� 1,2,3,4;
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int max_x, max_y;
//�ѻ���Ŭ�� �Ǵ�-�̵� ������->�߰���->���� ������? ������ �ѻ���Ŭ
   //�̵����,�̵��Ÿ� ����;
//�־��� vector<string>����ǻ� vector<vector<char>>
//�� 2�����迭�� ǥ�� ������.

//�����¿� 1,2,3,4;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool visit[500][500][5];//�׸���� �ִ�[500][500]�� ����̰� �ش� ����Ʈ�� ������ ������ 4���� �̹Ƿ� [4]
int c_dir(int dir, char c) {
    //������ dir, grid�� ���⿡���� �˸��� ������ �ش�.
    //�׸��尡 Left�ϰ��
    if (c == 'L') {
        if (dir == 0)return 2;
        if (dir == 1)return 3;
        if (dir == 2)return 1;
        if (dir == 3)return 0;
    }
    else {
        //grid�� right�ΰ��
        if (dir == 0)return 3;
        if (dir == 1)return 2;
        if (dir == 2)return 0;
        if (dir == 3)return 1;
    }
}
//���� �����ϴ� point(x,y)�� �ش� ���� ���۹��⿡ ���� ������ ��

int searching(int y, int x, int dir, int len, vector<string>& grid) {
    //�湮�Ѱ��̶�� ����Ŭ�� �ϼ��Ǿ����Ƿ� ���� ��ȯ
    if (visit[y][x][dir] == true)return len;
    //�湮ó��
    visit[y][x][dir] = true;
    //�湮�����������̶�� �ش� ��ġ�� grid�������� ���� dir�� ���ϰ� �̵���ġ�� �����ְ� len+1 
    if (grid[y][x] != 'S')dir = c_dir(dir, grid[y][x]);
    y = y + dy[dir];
    x = x + dx[dir];
    //y==max_gridy || y==min_gridx�ΰ��
    if (y < 0)y = max_y - 1;
    if (y == max_y)y = 0;
    //y==max_gridy || y==min_gridx�ΰ��
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
    int len = 0;//Ž���� ���� ���Ϲ��� ����Ŭ�� ����

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