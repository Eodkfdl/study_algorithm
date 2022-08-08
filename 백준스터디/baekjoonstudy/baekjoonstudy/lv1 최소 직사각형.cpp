#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int temp = 0;
    int w = 0, h = 0;
    //한쪽으로 큰 길이를 몰아 놓는게 포인트
    //따라서 가로 세로 중에 한쪽으로 크기가 큰 길이를 넣은 후 최대,최소를 구한다.
    for (auto t : sizes) {
        if (t[0] < t[1]) {
            w = max(w, t[1]);
            h = max(h, t[0]);
        }
        else {
            w = max(w, t[0]);
            h = max(h, t[1]);
        }
    }
    answer = w * h;


    return answer;
}