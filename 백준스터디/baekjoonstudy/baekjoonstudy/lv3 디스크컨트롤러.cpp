#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct comf {
    bool operator()(pair<int, int>a, pair<int, int>b) {
        return a.second > b.second;
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    //처음 생각이든 포인트 -> 모든일을 마친 시간은 예시 1 ,2 동일하다, 하지만 ㅇ청부터 종료까지 걸린 평균시간은 2의경우가 조금 더 빠르다.
    //작업시간이 길어도 요청시간이 먼저인것을 먼저 처리 한 경우 
    //작업시간이 짧은것을 먼저 처리 한 경우

    //a b 순으로 요청이 들어오고 b의 작업시간이 a의 작업시간보다 큰 경우
    //t1 = b의 작업시간 - a의 작업시간
    //t2 = b의 요청시간 - a의 요청시간
    //t1>t2인경우 b를 먼저 처리해야한다.
    //b의 작업시간 -a의 작업시간 > b의요청시간 - a의요청시간
    //b의 작업시간 -b의 요청시간 > a의 작업시간 - a의요청시간
    //작업에 걸리는 총시간
    //요청시간,작업시간으로 구성된 
    //현재 요청가능한 목록 -> 정렬 
    //나와있진않지만 jobs의 순서는 jobs[n][0]에의해 순서대로 입력되어있다고 생각하고 코딩
    int now = 0;
    //request- 탐색범위를 줄이기 위해 탐색한곳까지 저장
    int n = 0;

    int avg_time = 0;
    //처리중인 요청

    //요청 대기목록 cmp로 순서정해서 저장
    priority_queue<pair<int, int>, vector<pair<int, int>>, comf> pq;
    //
    sort(jobs.begin(), jobs.end());


    while (n < jobs.size() || !pq.empty()) {
        //현재시간에 추가해줄 수 있는 모든 작업들을 pq에 넣어준다.
        if (n < jobs.size() && jobs[n][0] <= now) {

            pq.push({ jobs[n][0],jobs[n][1] });
            n++;
            //
            continue;
        }

        //pq에서 가장 앞에 있는 녀석 처리해주기
        if (!pq.empty()) {
            auto temp = pq.top();
            now += temp.second;
            avg_time += now - temp.first;
            pq.pop();
        }
        else now = jobs[n][0];
    }


    answer = avg_time / jobs.size();
    return answer;
}