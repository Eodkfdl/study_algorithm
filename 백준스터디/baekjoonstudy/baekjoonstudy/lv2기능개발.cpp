#include <string>
#include <vector>
#include <queue>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int>progresses_que;
    int d = 0;
    int n = 0;
    int ret = 0;
    //1. ť�����λ���
    for (int i = 0; i < progresses.size(); i++) {
        progresses_que.push(progresses[i]);
    }
    
    while (!progresses_que.empty()) {
        //�Ǿ��� ���� ���൵
        int temp1 = 100 - progresses_que.front();
        //�������൵�� 0���ϰ� �ɶ����� day���� �÷���
        for (; temp1 - d * speeds[n] > 0; d++) {

        }
        //������� day*speed�� ����Ͽ� ���� ���൵�� 0���ϰ� �Ǹ� ���Ͻ�Ű�� ���ϰ��� �߰�
        while (100 - progresses_que.front() <= d * speeds[n] && n < progresses.size()) {

            progresses_que.pop();
            n++;
            ret++;
           if (progresses_que.empty())break;
        }
        answer.push_back(ret);
        
        ret = 0;

    }


    return answer;
}
int main() {
    int n = 0;
    int t1 = 0, t2 = 0;
    vector<int>progresses, speeds;
    cin >> n;
    while (n != 0) {
        //���α׷���,���ǵ��Է�;
        cin >> t1 >> t2;
        progresses.push_back(t1);
        speeds.push_back(t2);
        n -= 1;
    }
    auto temp = solution(progresses, speeds);
    for (auto t : temp) {
        cout << t << ", ";
    }
}