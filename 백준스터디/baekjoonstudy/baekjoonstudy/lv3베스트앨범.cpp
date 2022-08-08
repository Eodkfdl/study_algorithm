#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    //���� ���:
    //�÷��̰� 0 �ΰ��? �帣�� �ϳ����ΰ��?
   //�帣, �÷��̼� ��
    map<string, int> genre_play;
    //�帣,�ִ��÷����ε���,�״����÷��ε���
    map<string, pair<int, int>> genre_rank;
    //�帣�� ����� ����
    set<string>genre;
    //�÷��̼��� ù��°, �ι�°�� ���� �帣�� ã��
    //�帣���� �ִ��÷����ε����� �״����÷��� �ε����� �ʱ�ȭ���ش�.
    for (int i = 0; i < genres.size(); i++) {
        genre_play[genres[i]] += plays[i];
        genre.insert(genres[i]);
        genre_rank[genres[i]].first = 0;
        genre_rank[genres[i]].second = 0;
    }

    //���ϵ� �帣�� ����
    vector<string> rg;
    rg.resize(2);
    rg[0] = genres[0];
    rg[1] = genres[1];
    for (auto t : genre) {
        //1���� ä���ְ� 
        if (genre_play[t] > genre_play[rg[0]]) {
            rg[1] = rg[0];
            rg[0] = t;
            continue;
        }
        //2� ä���ֱ�
        if (genre_play[t] > genre_play[rg[1]]) {
            rg[1] = t;

        }
    }
    //������ �帣���� ���� �÷��̵� ���� �ε����� ã�´�.

    for (int j = 0; j < 2; j++) {
        int f_idx = 0;
        int s_idx = 0;
        for (int i = 0; i < genres.size(); i++) {
            if (genres[i] == rg[j] && plays[f_idx] < plays[i]) {
                s_idx = f_idx;
                f_idx = i;

            }
            if (genres[i] == rg[j] && plays[s_idx] < plays[i] && f_idx != i) {
                s_idx = i;
            }
        }
        answer.push_back(f_idx);
        answer.push_back(s_idx);
    }




    return answer;
}