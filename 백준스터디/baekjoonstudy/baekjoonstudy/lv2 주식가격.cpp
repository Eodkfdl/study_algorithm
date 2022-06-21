#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    //인덱스 번호가 n일때 n~끝까지 for문을 돌며
    //떨어진 경우 떨어진 경우 index - n = 유지된시간
    //안떨어진 경우  끝-n= 유지된시간
    //각각 answer.push_back(유지된시간); 
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i; j < prices.size(); j++) {
            if (prices[i] > prices[j] || j == prices.size() - 1) {
                answer.push_back(j - i);
                break;
            }
        }

    }
    return answer;
}