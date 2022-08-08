#include <string>
#include <vector>
#include <queue>

using namespace std;
//최소값보장 하는거니까 bfs여야 하지않을까?


//해법
//begin에서 순차적으로 갈수 있는 단어를 찾기
//해당단어목록에서 다른 단어로 갈 수있는 목록 추가.
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    //방문여부
    int c[50] = { 0, };
    //단어,해당단어까지 begin에서부터의 거리
    queue<pair<string, int>> q;
    int str_s = begin.size();
    int count = 0;
    //1. target이 있는지 확인한다.
    for (int i = 0; i < words.size(); i++) {
        //타깃이 있다면 
        if (words[i] == target) {
            count++;
            break;
        }
    }
    if (count == 0)return 0;

    //2. bfs방식으로 검색
    q.push({ begin,0 });

    while (!q.empty()) {
        auto w = q.front();
        q.pop();
        //타깃인경우
        if (w.first == target) {
            answer = w.second;
            break;
        }

        for (int i = 0; i < words.size(); i++) {
            int cnt = 0;
            //자기 자신인경우 넘어가기
            if (words[i] == w.first)continue;
            //방문한경우 넘어가기
            if (c[i] == 1)continue;
            //한글자만 바꿀수 있으므로 cnt==2 이상이여야만 큐에넣을수잇다.
            for (int j = 0; j < str_s; j++) {
                if (words[i][j] == w.first[j]) {
                    cnt++;
                }
            }

            if (cnt == str_s - 1) {
                //q에 넣어주고 체크했다고 저장하기
                q.push({ words[i],w.second + 1 });
                c[i] = 1;
            }
        }
    }

    return answer;
}