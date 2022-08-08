#include <string>
#include <vector>

using namespace std;
//서버요청처리랑 비슷할듯. 요청대기시간,처리시간
long long solution(int n, vector<int> times) {
    long long answer = 0;
    //심사관이 10만명-> for문을 돌면서 시간%현재시간..?  times의 최댓값 최솟값으로 이분탐색?
    //최소로하려면 비어있는 심사관이 있더라도 그 심사관의 심사시간> 안비어있는 심사관의 심사시간+대기시간 인것도 판단할 수있어야함
    //처음시작되자마자 심사관의 수만큼 빼주자

    //최소시간 : 한번에 모든 심사대로 들어갔을 때
    long long min = 1;
    //최대시간: 심사관중 제일시간 오래 걸리는 사람 
    long long max = (long long)(times[times.size() - 1]) * n;
    //이분탐색을 위한 평균값.
    long long avg = 0;
    long long c = 0;

    while (min <= max) {
        avg = (min + max) / 2;
        c = 0;
        for (auto t : times)c += (avg / (long long)t);

        if (c >= n) {
            answer = avg;
            max = avg - 1;
        }
        else min = avg + 1;
    }

    return answer;
}