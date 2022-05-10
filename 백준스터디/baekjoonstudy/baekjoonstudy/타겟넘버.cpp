#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

int a;
vector<int> progresses;
vector<int> speeds;
vector<int> enswer;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int>progresses_que;
    int d = 0;
    int n = 0;
    int ret = 0;
    //1. 큐에전부삽입
    for (int i = 0; i < progresses.size(); i++) {
        progresses_que.push(progresses[i]);
    }
    //2.큐에서 처음
    while (!progresses_que.empty()) {
        int temp1 = 100 - progresses_que.front();
        for (;  temp1 - d * speeds[n] > 0; d++) {
           
        }

        while (100 - progresses_que.front() <= d * speeds[n]&&n<progresses.size()) {

            progresses_que.pop();
            n++;
            ret++;
        }
        answer.push_back(ret);
        ret = 0;


    }


    return answer;
}
  int main(){
      int temp=0;
    cin >> a;
    for (int i = 0; i < a;i++) {
        cin >> temp;
        progresses.push_back(temp);
    }
    for (int i = 0; i < a; i++) {
        cin >> temp;
        speeds.push_back(temp);
    }
    enswer = solution(progresses, speeds);
    cout << enswer.front() << endl;
    
    
    }