#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {

    //단순히 모든경우를 돌며 조건에 맞는경우를 추가해준다.
    vector<int> answer;
    int sum = brown + yellow;
    for (int height = 3; ; height++) {
        if (!(sum % height)) {
            int weight = sum / height;
            if (((height - 2) * (weight - 2)) == yellow) {
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}