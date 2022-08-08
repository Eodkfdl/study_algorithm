#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    //처음든생각 : 우선순위큐 2개쓰기  , deque 사용하기
    //우선순위큐 2개-> 메모리낭비,최대최소 바로 알 수 있음 O logn
    //deque -> 양쪽 접근가능 중간 접근시 O n 
    deque<int> deq;
    int size_n = 0;
    for (int i = 0; i < operations.size(); i++) {
        char oder = operations[i][0];
        int n = 0;

        switch (oder) {


        case 'I':

            n = stoi(operations[i].substr(1));
            deq.push_back(n);
            sort(deq.begin(), deq.end());
            break;
        case 'D':
            if (deq.size() < 1)break;
            if (operations[i][2] == '1')deq.pop_back();
            else deq.pop_front();
            break;
        }
    }

    if (deq.size() < 1) {
        answer.resize(2, 0);
    }
    else {
        answer.push_back(deq.back());
        answer.push_back(deq.front());

    }
    return answer;
}