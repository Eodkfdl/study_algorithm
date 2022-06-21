#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int>pq;
    queue<pair<int, int>>q;
    //1. pq,q에 각각 우선순위, 우선순위,인덱스 삽입
    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push({ priorities[i],i });
    }
    //2.p의 우선순위와 pq의 우선순위가 같으면 두개 모두pop 아니라면 다시 q에 넣어주기
    while (!q.empty()) {

        auto t = q.front();
        q.pop();

        if (t.first == pq.top()) {
            pq.pop();
            answer++;
            //2-1.순서를 알고 싶은 인덱스라면 루프를 빠져나간다.
            if (t.second == location)break;
        }
        else { q.push(t); }
    }
    return answer;
}


//2
int solution2(vector<int> priorities, int location) {
    int answer = 0;
    map<pair<int, int>> m1, m2;

    //1.m1 중요도,인덱스 m2 순서,인덱스 순으로 넣어주기.
    for (int i = 0; i < priorites.size(); i++) {
        m1.insert(priorities[i], i);
        m2.insert(i, i);
    }

    //2.m1을순차적으로 탐색하면서 
    for (auto i = m1.begin(); i != m1.end(); i++) {
        answer++;
        //현재의 인덱스의 순서를 answer로바꿈

        //m2 순서, 인덱스로 저장되어있으므로
        //find(m2.begin(),m2.end(),인덱스)로 찾아서 순서찾아주기
    }




    return m2[location];
}