#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);

    for (int i = 0; i < routes.size(); i++) {
    
        int l = (routes[i][0] < routes[i + 1][0]) ? routes[i][0] : routes[i + 1][0];
        int r = (routes[i][1] < routes[i + 1][1]) ? routes[i][1] : routes[i + 1][1];
    }
    return answer;
}
int main() {
    vector<vector<int>> t;
    int n=0;
    int a=0, b=0;
    cin >> n;
    t.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a>> b;
        t[i].push_back(a);
        t[i].push_back(b);
        
    }
    cout<<solution(t);
}