

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> quest) {
    int answer = 0;

    int cur_exp = 0;
    int quest_size = quest.size();
    sort(quest.begin(), quest.end());

    while (cur_exp >= quest[answer][0] && answer < quest_size) {
        cur_exp += quest[answer][1];
        answer++;
    }
    return answer;
}
int main() {
	solution();
}