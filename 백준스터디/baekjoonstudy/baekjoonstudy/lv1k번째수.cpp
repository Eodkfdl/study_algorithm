#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//2�������Ϳ����� ���ٹ���� �ƴ°��� �ٽ�
//vector�� random access�� ������ squence �ڷᱸ����.
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for (auto t : commands) {
        for (int i = t[0] - 1; i < t[1]; i++)temp.push_back(array[i]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[t[2] - 1]);
        temp.clear();
    }

    return answer;
}