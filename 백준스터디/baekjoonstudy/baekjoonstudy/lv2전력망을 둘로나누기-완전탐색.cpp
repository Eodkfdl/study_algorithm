#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dfs(vector<vector<bool>>& check, vector<bool>& visited, int  curr) {
    //���¸��� ����°����� ���� 
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
    //�������� ����Ǿ��ְ� �ϳ��� ������ �ڸ��� �ִ��� ���밪�� ������츦 ���ϴ� ����

    //���¸��� �������ִ� ����ž�� ������ ����
    
    //0�� ���� 1�� ����� 
    vector<vector<bool>> check(n, vector<bool>(n, 1));
    vector<bool>visited;


    for (int i = 0; i < n - 1; i++) {
        wires[i][0] -= 1;
        wires[i][1] -= 1;

        check[wires[i][0]][wires[i][1]] = 0;
        check[wires[i][1]][wires[i][0]] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        //wires�� i��° index�� ����(�������)���� ��� ���� ����Ǿ��ִ� ���� ���Ѵ� 
        vector<int> count;
        //���� �� �湮ó��
        check[wires[i][0]][wires[i][1]] = 1;
        check[wires[i][1]][wires[i][0]] = 1;
        visited = vector<bool>(n + 1, false);
        //dfs��ã��
        for (int j = 0; j < n; j++) {
            int t = dfs(check, visited, j);
            if (t < 1)continue;
            count.push_back(t);
        }

        answer = min(answer, abs(count[0] - count[1]));

        //�������� �ٽÿ������ֱ�
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