#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int>pq;
    queue<pair<int, int>>q;
    //1. pq,q�� ���� �켱����, �켱����,�ε��� ����
    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push({ priorities[i],i });
    }
    //2.p�� �켱������ pq�� �켱������ ������ �ΰ� ���pop �ƴ϶�� �ٽ� q�� �־��ֱ�
    while (!q.empty()) {

        auto t = q.front();
        q.pop();

        if (t.first == pq.top()) {
            pq.pop();
            answer++;
            //2-1.������ �˰� ���� �ε������ ������ ����������.
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

    //1.m1 �߿䵵,�ε��� m2 ����,�ε��� ������ �־��ֱ�.
    for (int i = 0; i < priorites.size(); i++) {
        m1.insert(priorities[i], i);
        m2.insert(i, i);
    }

    //2.m1������������ Ž���ϸ鼭 
    for (auto i = m1.begin(); i != m1.end(); i++) {
        answer++;
        //������ �ε����� ������ answer�ιٲ�

        //m2 ����, �ε����� ����Ǿ������Ƿ�
        //find(m2.begin(),m2.end(),�ε���)�� ã�Ƽ� ����ã���ֱ�
    }




    return m2[location];
}