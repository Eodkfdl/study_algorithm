#include <string>
#include <vector>

using namespace std;
//이코테 음료수 얼려먹기랑 동일 문제
bool dfs(int n, vector<vector<int>>& c) {
    if (!c[n][n])return false;//방문한곳이라면 return
    c[n][n] = 0;//방문하지않은곳이라면 방문처리
    //현재위치의노드에서 모든노드들에대하여 dfs
    for (int i = 0; i < c.size(); i++)if (c[n][i])dfs(i, c);



    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    //이어져있는 네트워크의 수를 반환해주어야한다.
    //dfs
    //한 지점에서 출발해서 이어진곳 모두 방문 처리 후 네트워크갯수 증가
    for (int i = 0; i < n; i++) {
        //computers[i][j]=0 방문한곳 or 연결되지않는곳
        //computers[i][j]=1 방문한곳 or 연결된곳
        if (dfs(i, computers))answer++;

    }

    return answer;
}