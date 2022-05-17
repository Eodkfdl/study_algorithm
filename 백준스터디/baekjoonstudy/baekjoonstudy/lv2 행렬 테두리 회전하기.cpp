#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<int>rot_n;
    vector<pair<int, int>>rot_sq;
    //1,1부터시작하므로 0,0은 비워두기
    vector < vector <int> > mat(rows + 2, vector<int>(columns + 2, 0));
    for (int i = 1; i < rows + 1; i++) {
        for (int j = 1; j < columns + 1; j++) {
            mat[i][j] = ((i - 1) * columns + j);
        }
    }
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    int min_n = 9999;
    for (auto t : queries) {
        min_n = 9999;
        x1 = t[0];
        y1 = t[1];
        x2 = t[2];
        y2 = t[3];
        //로테이션 되야하는 숫자들 저장.
        for (int i = x1; i < x2; i++) {
            rot_n.push_back(mat[y1][i]);
            rot_sq.push_back(make_pair(y1, i));
        }
        for (int i = y1; i < y2; i++) {
            rot_n.push_back(mat[i][x2]);
            rot_sq.push_back(make_pair(i, x2));
        }
        for (int i = x2; i > x1; i--) {
            rot_n.push_back(mat[y2][i]);
            rot_sq.push_back(make_pair(y2, i));
        }
        for (int i = y2; i > y1; i--) {
            rot_n.push_back(mat[i][x1]);
            rot_sq.push_back(make_pair(i, x1));
        }
        //회전하는수중에 최솟값 찾기
        for (auto t : rot_n) {
            min_n = min(min_n, t);
        }
        //최솟값저장
        answer.push_back(min_n);
        //로테이션 시켜주기
        //시계방향으로 도는 순서를 저장 해놓았으므로 맨처음을 맨뒤로만 보내주면 1칸씩 밀림
        rot_sq.push_back(rot_sq[0]);
        rot_sq.erase(rot_sq.begin());
        auto it = rot_n.begin();
        for (auto t : rot_sq) {
            mat[t.first][t.second] = *it;
            it++;
        }
        //다음 쿼리를 위해 저장공간 초기화
        rot_n.clear();
        rot_sq.clear();
        for (auto t : mat) {
            for (auto a : t) {
                if (a > 9)cout << a << " ";
                else cout << "0" << a << " ";
            }
            cout << endl;
        }
    }

    return answer;
}
int rows = 0, columns = 0,temp;
vector<int>queries;
vector<vector<int>>q;
int main() {
    
    cin >> rows >> columns;
    for (int i = 0; i < 4; i++) {
        cin >> temp;
        queries.push_back(temp);
    }
    q.push_back(queries);
    queries.clear();
    for (int i = 0; i < 4; i++) {
        cin >> temp;
        queries.push_back(temp);
    }
    q.push_back(queries);

    vector<int>ta = solution(rows, columns,q);
    for (auto t : ta) {
        cout << t << ",";
    }
}