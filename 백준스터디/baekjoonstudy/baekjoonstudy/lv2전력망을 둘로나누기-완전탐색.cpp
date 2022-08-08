#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dfs(vector<vector<bool>>& check, vector<bool>& visited, int  curr) {
    //전력망이 끊기는곳에서 리턴 
    if (visited[curr])return 0;
    visited[curr] = true;

    int ret = 1;
    for (int i = 1; i < check.size(); i++) {
        if (check[curr][i])continue;
        ret += dfs(check, visited, i);
    }
    return ret;

}

int solution(int n, vector<vector<int>> wires) {
    int answer = 999;
    //모든노드들은 연결되어있고 하나의 연결을 자를때 최대한 절대값이 작은경우를 구하는 문제

    //전력망이 가지고있는 송전탑의 갯수를 저장
    
    //0은 연결 1은 끊긴곳 
    vector<vector<bool>> check(n, vector<bool>(n, 1));
    vector<bool>visited;


    for (int i = 0; i < n - 1; i++) {
        wires[i][0] -= 1;
        wires[i][1] -= 1;

        check[wires[i][0]][wires[i][1]] = 0;
        check[wires[i][1]][wires[i][0]] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        //wires의 i번째 index를 제외(연결끊기)했을 경우 각각 연결되어있는 수를 구한다 
        vector<int> count;
        //끊을 곳 방문처리
        check[wires[i][0]][wires[i][1]] = 1;
        check[wires[i][1]][wires[i][0]] = 1;
        visited = vector<bool>(n + 1, false);
        //dfs로찾기
        for (int j = 0; j < n; j++) {
            int t = dfs(check, visited, j);
            if (t < 1)continue;
            count.push_back(t);
        }

        answer = min(answer, abs(count[0] - count[1]));

        //끊었던곳 다시연결해주기
        for (auto t : wires) {
            check[t[0]][t[1]] = 0;
            check[t[1]][t[0]] = 0;
        }
    }
    return answer;
}



int main() {
    int n = 0, a = 0,b=0;
   
    cin >> n;
    vector<vector<int>> v(n-1);

    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        v[i].push_back(a);
        v[i].push_back(b);
    }
   cout<< solution(n, v);
}