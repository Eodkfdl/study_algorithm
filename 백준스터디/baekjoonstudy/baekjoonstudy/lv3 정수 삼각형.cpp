#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    unordered_map<string, int> dp[500];
    dp[0]["0"] = triangle[0][0];
    for (int i = 0; i < triangle.size() - 1; i++) {
        for (auto a : dp[i]) {
            dp[i + 1][a.first + a.first[a.first.size() - 1]] = a.second + triangle[i + 1][(a.first[a.first.size() - 1] - 48)];
            dp[i + 1][a.first + to_string((a.first[a.first.size() - 1] - 47))] = a.second + triangle[i + 1][(a.first[a.first.size() - 1] - 48) + 1];
        }
    }
    for (auto t : dp[triangle.size() - 1])answer = max(t.second, answer);

    return answer;
}