#include <string>
#include <vector>
#include <algorithm>
#include <deque>// 삽입 1 탐색 O(n)
#include <iostream>
using namespace std;
bool dfs(string cur, const vector<vector<string>>& t, const int& m_r, vector<int>& check, int depth, vector<string>& an, int idx) {

    if (depth == m_r) {
        an.push_back(t[idx][1]);
        check[idx] = 0;
        return true;
    }

    for (int i = 0; i < t.size(); i++) {
        if (cur == t[i][0] && check[i]) {
            check[i] = 0;
                if(dfs(t[i][1], t, m_r, check, depth + 1, an, i)
                    ){
                    //stackfarame에 함수를 저장해서 뒤에서부터 불러오기때문에 역순으로 저장된다.
                    //따라서 저장된것을 반대로 출력해주거나 재정렬 필요
                an.push_back(t[i][0]);
                
                return true;
            }
                check[i] = 1;
        }

    }
     
    return false;


}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    int max_route = tickets.size();
    vector<int> check;
    check.resize(max_route, 1);
    //루트의 갯수

    int r_n = 0;
    //목록을 
    sort(tickets.begin(), tickets.end());
  

    dfs("ICN", tickets, max_route, check, 0, answer, 0);
    //전체 목록중에 현재 위치에 가능한 목록
    reverse(answer.begin(), answer.end());
    return answer;
}

int main() {
    int n;
    string temp, temp2;
    cin >> n;
    vector<vector<string>> t;
    t.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> temp >> temp2;
        t[i].push_back(temp);
        t[i].push_back(temp2);
    }
    auto a = solution(t);
    for (auto v : a) {
        cout << v << ",";
    }
}