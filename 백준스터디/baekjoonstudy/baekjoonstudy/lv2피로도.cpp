#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    //���� �Ƿε� k
    
    //����Ž�� ->dfs,
    int p = 0;
    int c = 0;
    vector<int> r;
    //�����ϴ� ��� ��� = ����
    //�ּ� �ʿ� �Ƿε��� ���� �Ƿε��� ������ ������ ���� �ʰ� �ܼ� �񱳸� �ϴ� ���̴�.

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