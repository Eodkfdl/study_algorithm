#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    //현재 피로도 k
    
    //완전탐색 ->dfs,
    int p = 0;
    int c = 0;
    vector<int> r;
    //진입하는 모든 경우 = 순열
    //최소 필요 피로도는 현재 피로도에 증감에 영향을 주지 않고 단순 비교만 하는 값이다.

    sort(dungeons.begin(), dungeons.end());
    do {
        p = k;
        c = 0;

        for (auto d : dungeons) {
            if (p >= d[0]) {
                p -= d[1];
                c++;
            }
            else break;
        }
        r.push_back(c);

    } while (next_permutation(dungeons.begin(), dungeons.end()));

    sort(r.begin(), r.end());
    answer = r[r.size() - 1];
    return answer;
}