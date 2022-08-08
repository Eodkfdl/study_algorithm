#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> sum;
bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
int find_parent(int idx) {
    //자기자신이 부모=최상위노드면 자신을 리턴
    if (sum[idx] == idx)return idx;

    return sum[idx] = find_parent(sum[idx]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    //최소신장트리 ,크루스칼 알고리즘
    //1. 비용이작은순으로 정렬한다.
    //2.최소비용으로 다리를 연결하고 사이클이 생기는지 확인.
    //3.사이클이 생기지않는다면 연결.
    sort(costs.begin(), costs.end(), cmp);
    //island[idx]=n idx의 부모는 n
    for (int i = 0; i < n + 1; i++)sum.push_back(i);

    for (int i = 0; i < costs.size(); i++) {
        int start = find_parent(costs[i][0]);
        int end = find_parent(costs[i][1]);

        if (start != end) {
            answer += costs[i][2];
            sum[end] = start;
        }

    }
    return answer;
}