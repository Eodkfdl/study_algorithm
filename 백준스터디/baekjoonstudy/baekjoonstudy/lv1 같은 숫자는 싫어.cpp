#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    //앞의숫자와 뒤의숫자를 비교하고 같지않으면 ex를 갱신 후 answer에 넣어주기.
    //unordered_set을 이용하는 방법도있지만 간단하게 구현가능해서 그냥 이렇게함
    int ex = -1;
    for (auto t : arr) {
        if (ex != t) {
            ex = t;
            answer.push_back(t);
        }
    }
    return answer;
}