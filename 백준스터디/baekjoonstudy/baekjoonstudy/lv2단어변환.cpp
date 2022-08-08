#include <string>
#include <vector>
#include <queue>

using namespace std;
//�ּҰ����� �ϴ°Ŵϱ� bfs���� ����������?


//�ع�
//begin���� ���������� ���� �ִ� �ܾ ã��
//�ش�ܾ��Ͽ��� �ٸ� �ܾ�� �� ���ִ� ��� �߰�.
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    //�湮����
    int c[50] = { 0, };
    //�ܾ�,�ش�ܾ���� begin���������� �Ÿ�
    queue<pair<string, int>> q;
    int str_s = begin.size();
    int count = 0;
    //1. target�� �ִ��� Ȯ���Ѵ�.
    for (int i = 0; i < words.size(); i++) {
        //Ÿ���� �ִٸ� 
        if (words[i] == target) {
            count++;
            break;
        }
    }
    if (count == 0)return 0;

    //2. bfs������� �˻�
    q.push({ begin,0 });

    while (!q.empty()) {
        auto w = q.front();
        q.pop();
        //Ÿ���ΰ��
        if (w.first == target) {
            answer = w.second;
            break;
        }

        for (int i = 0; i < words.size(); i++) {
            int cnt = 0;
            //�ڱ� �ڽ��ΰ�� �Ѿ��
            if (words[i] == w.first)continue;
            //�湮�Ѱ�� �Ѿ��
            if (c[i] == 1)continue;
            //�ѱ��ڸ� �ٲܼ� �����Ƿ� cnt==2 �̻��̿��߸� ť���������մ�.
            for (int j = 0; j < str_s; j++) {
                if (words[i][j] == w.first[j]) {
                    cnt++;
                }
            }

            if (cnt == str_s - 1) {
                //q�� �־��ְ� üũ�ߴٰ� �����ϱ�
                q.push({ words[i],w.second + 1 });
                c[i] = 1;
            }
        }
    }

    return answer;
}