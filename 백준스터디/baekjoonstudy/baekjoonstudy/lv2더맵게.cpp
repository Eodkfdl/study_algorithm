#include <string>
#include <vector>
#include <queue>

using namespace std;
//priority_que를 사용하면 쉽게 풀리는 문제이다 우선순위큐를 선언할때 기본적으로 내림차순이다.
//이를 오름차순으로 변경한다.
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> sco;
    for (auto t : scoville)sco.push(t);
    int t = 0, t2 = 0, cnt = 0;
    while (sco.top() < K && sco.size() > 1) {
        t = sco.top();
        sco.pop();
        t2 = sco.top();
        sco.pop();
        sco.push(t + (t2 * 2));
        answer++;
    }
    if (sco.top() < K)answer = -1;
    return answer;
}