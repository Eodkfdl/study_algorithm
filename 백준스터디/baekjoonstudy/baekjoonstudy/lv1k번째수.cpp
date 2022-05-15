#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//2차원백터에대한 접근방식을 아는것이 핵심
//vector는 random access가 가능한 squence 자료구조다.
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