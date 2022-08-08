#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    //예외 경우:
    //플레이가 0 인경우? 장르가 하나뿐인경우?
   //장르, 플레이수 합
    map<string, int> genre_play;
    //장르,최다플레이인덱스,그다음플레인덱스
    map<string, pair<int, int>> genre_rank;
    //장르의 목록을 저장
    set<string>genre;
    //플레이수가 첫번째, 두번째로 많은 장르를 찾고
    //장르별로 최다플레이인덱스와 그다음플레이 인덱스를 초기화해준다.
    for (int i = 0; i < genres.size(); i++) {
        genre_play[genres[i]] += plays[i];
        genre.insert(genres[i]);
        genre_rank[genres[i]].first = 0;
        genre_rank[genres[i]].second = 0;
    }

    //수록될 장르를 선정
    vector<string> rg;
    rg.resize(2);
    rg[0] = genres[0];
    rg[1] = genres[1];
    for (auto t : genre) {
        //1등을 채워넣고 
        if (genre_play[t] > genre_play[rg[0]]) {
            rg[1] = rg[0];
            rg[0] = t;
            continue;
        }
        //2등도 채워넣기
        if (genre_play[t] > genre_play[rg[1]]) {
            rg[1] = t;

        }
    }
    //선정된 장르에서 가장 플레이된 곡의 인덱스를 찾는다.

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