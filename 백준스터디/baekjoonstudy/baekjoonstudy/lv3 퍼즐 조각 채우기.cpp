#include <string>
#include <vector>
#include <iostream>
using namespace std;
//dfs탐색을 할 v, 탐색으르 통해 인덱스를 저장해둘 s , 기준이 0이될지 1이 될지 구별할 diff 
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int p_cnt;
int b_cnt;
bool dfs(vector<vector<int>>& v, vector<pair<int, int>>& s, int diff, int x, int y) {
    if (x<0 || x>v.size() - 1 || y<0 || y>v.size() - 1)return false;
    if (diff == v[y][x])return false;
    v[y][x] = diff;
    s.push_back({ y,x });
    for (int i = 0; i < 4; i++) {
        dfs(v, s, diff, x + dx[i], y + dy[i]);

        
    }

    return true;
}
void adj(vector<vector<pair<int,int>>> & v) {
    int minx = 999;
    int miny = 999;
    pair<int, int> idx_x = {};
    pair<int, int> idx_y = {};
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (miny > v[i][j].first) {
                miny = v[i][j].first;
                idx_y = { i,j };
            }
            if (minx > v[i][j].second) {
                minx = v[i][j].second;
                idx_x = { i,j };
            }
        }
        while (v[idx_x.first][idx_x.second].second != 0) {
            for (auto& t : v[idx_x.first])t.second -= 1;
        }
        while (v[idx_y.first][idx_y.second].first != 0) {
            for (auto& t : v[idx_y.first])t.first -= 1;
        }
        minx = 999;
        miny = 999;
        idx_x = {};
        idx_y = {};
    }
}

int put_puzzle(vector<pair<int, int>> &b, vector<pair<int, int>> &p) {
    int max_x = -1;
    int max_y = -1;
    int max_n = -1;
    if (b[0].first == -1 || p[0].first == -1)return 0;
    if (b.size() != p.size())return 0;
    for (const auto& t : b) {
        if (max_x < t.second)max_x = t.second;
        if (max_y < t.first)max_y = t.first;
    }
    max_x < max_y ? max_n = max_y : max_n = max_x;

    vector<vector<int>> blank(max_n+1,vector<int>(max_n+1,1));

    max_n = -1;
    max_x = -1;
    max_y = -1;
    for (const auto& t : p) {
        if (max_x < t.second)max_x = t.second;
        if (max_y < t.first)max_y = t.first;
    }
    max_x < max_y ? max_n = max_y : max_n = max_x;

    vector<vector<int>> puzzle(max_n+1, vector<int>(max_n+1,0));
    if (puzzle.size() != blank.size())return 0;
  
    for (const auto& t : b) {
        blank[t.first][t.second] = 0;
    }
    for (const auto& t : p) {
        puzzle[t.first][t.second] = 1;
    }
    if (blank.size() != puzzle.size())return 0;
    for (int i = 0; i < 4; i++) {
        bool correct = true;
        vector<vector<int>> temp(puzzle.size(), vector<int>(puzzle.size(), 0));
        max_n = puzzle.size();
        for (int j = 0; j < max_n; j++) {
            for (int k = 0; k < max_n; k++) {
                temp[k][max_n - j - 1] = puzzle[j][k];
            }
        }
        for (int j = 0; j < max_n; j++) {
            for (int k = 0; k < max_n; k++) {
                puzzle[j][k] = temp[j][k];
            }
        }
        for (int j = 0; j < max_n; j++) {
            for (int k = 0; k < max_n; k++) {
                if (puzzle[j][k] + blank[j][k] == 2|| puzzle[j][k] + blank[j][k] == 0)correct = false;
            }
        }
      
        if (correct) {
            cout << "퍼즐" << endl;
            for (int j = 0; j < puzzle.size(); j++) {
                for (int k = 0; k < puzzle.size(); k++) {
                    cout << puzzle[j][k] << " ";
                }
                cout << endl;
            }
            cout << "빈공간" << endl;
            for (int j = 0; j < blank.size(); j++) {
                for (int k = 0; k < blank.size(); k++) {
                    cout << blank[j][k] << " ";
                }
                cout << endl;
            }
            for (auto& t : b) {
                t.first = -1;
                t.second = -1;
            }
            for (auto& t : p) {
                t.first = -1;
                t.second = -1;
            }
            return p.size();
        }
    }
    return 0;


   
 

}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<vector<pair<int, int>>> puzzle;
    vector<vector<pair<int, int>>> blank;

    //1.dfs로 이어져있는 연속되어 있는 퍼즐의 인덱스를 저장
    //2.dfs로 gameboard로 빈칸의 index를 저장;
    //3.퍼즐인덱스를 rotation하며 gameboard의 인덱스와 일치하는것이 있는지 확인
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table.size(); j++) {
            vector<pair<int, int>>s;
            if (dfs(table, s, 0, j, i))puzzle.push_back(s);
        }
    }

    for (int i = 0; i < game_board.size(); i++) {
        for (int j = 0; j < game_board.size(); j++) {
            vector<pair<int, int>>s;
           if( dfs(game_board, s, 1, j, i))blank.push_back(s);
        }
    }
    adj(puzzle);
    adj(blank);

    for (auto& t : blank) {
        for (auto& k : puzzle) {
            answer += put_puzzle(t, k);
           
        }
    }
   
    

    return answer;
}

int main() {
    vector < vector<int> >g = {{1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 0, 0}};
    vector<vector<int>>t = { {1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 0}, {0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0}, {1, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0} };
    vector < vector<int> >g1 = {{0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0}, {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1}, {0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0}, {1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1}, {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0}};
    vector<vector<int>>t1 = { {1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1}, {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0}, {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0}, {1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, {1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1}, {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1}, {1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1}, {1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1}, {1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1} };

    cout<<solution(g1, t1);
}