#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    //핵심-> 모든노드와 승패가 결정이 났다-> 순위가 확정될수있다.

    //플루이드워셜은 O n^3임
    //플루이드워셜

    vector<vector<int>>graph(n + 1, vector<int>(n + 1, 0));


    for (auto t : results)graph[t[0]][t[1]] = 1;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (graph[i][k] == 1 && graph[k][j] == 1)
                    graph[i][j] = 1;



    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++)
            if (graph[i][j] == 1 || graph[j][i] == 1)count++;

        if (count == n - 1)answer++;
    }

    return answer;
}
int n, i, a, b;
vector<vector<int>>r;
int main() {
    cin >> n >> i;
  
    for (int j = 0; j < i; j++) {
        cin >> a >> b;
        r.push_back({ a,b });
    }
    cout << solution(n,r);
}