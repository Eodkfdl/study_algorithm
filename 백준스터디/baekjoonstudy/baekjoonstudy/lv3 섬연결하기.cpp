#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> sum;
bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
int find_parent(int idx) {
    //�ڱ��ڽ��� �θ�=�ֻ������� �ڽ��� ����
    if (sum[idx] == idx)return idx;

    return sum[idx] = find_parent(sum[idx]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    //�ּҽ���Ʈ�� ,ũ�罺Į �˰���
    //1. ��������������� �����Ѵ�.
    //2.�ּҺ������ �ٸ��� �����ϰ� ����Ŭ�� ������� Ȯ��.
    //3.����Ŭ�� �������ʴ´ٸ� ����.
    sort(costs.begin(), costs.end(), cmp);
    //island[idx]=n idx�� �θ�� n
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