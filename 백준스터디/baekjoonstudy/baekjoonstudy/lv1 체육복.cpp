#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> stu(n+2 , 0);//앞뒤로 검색해야하므로 0번과 마지막번째 비워두기

    for (int i : lost) {
        stu[i]--;
    }
    for (int i : reserve) {
        stu[i]++;
    }

    for (int i = 1; i <= n; i++) {
        if (stu[i] < 0) {
            if (stu[i - 1] == 1) {
                stu[i]++;
                stu[i - 1]--;
            }
            else if (stu[i + 1] == 1) {
                stu[i]++;
                stu[i + 1]--;
            }
        }
    }

    for (int t: stu) {
        if (t >= 0) answer++;
    }

    return answer;
}