#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    //n개의 바위를 제거하고 각 바위의 거리 중 최소값을 구한다.
    //가능한 제거 경우의 수 모두를 본다.?
    //최솟값이 제일 커야하므로 바위 사이의 거리가 작은 순서대로 순차적으로제거?

    //돌의 인덱스,돌사의의거리를 저장
    sort(rocks.begin(), rocks.end());
    //바위사이의 거리 기준으로 정렬

    int min = 0;
    int max = distance;

    int avg = 0;
    int temp = 0;
    int left = 0;
    while (min <= max) {
        avg = (min + max) / 2;
        temp = 0;
        left = 0;
        //돌맹이거리가 평균보다 낮은 애들을 뽑아버려야함  == 평균보다 높은애들이 남아야함
            //평균보다 거리가 높은애들 갯수 세주기.
        for (auto t : rocks) {
            if (t - left < avg)temp++;
            else left = t;
        }

        //남아야하는 갯수보다 실제 남은 갯수가 많다. == avg를 키워야함
        if (temp <= n) {
            answer = std::max(avg, answer);
            min = avg + 1;



        }
        else {
            max = avg - 1;

        }



    }
    return answer;
}