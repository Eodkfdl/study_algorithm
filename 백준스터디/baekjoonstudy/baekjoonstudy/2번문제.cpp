#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(vector<vector<int>> field, int farmSize) {
    int answer = 0;
    int min_count = 999;
    int cur_count = 0;
    bool exist_mushroom = false;
    //비어있음 0 독버섯 1 돌 2
    //해당영역에 독버섯이 있으면 재 검색
    //해당영역에 돌의 갯수를 비교 연산후 돌을 치워야하는 갯수가 적은것 반환
    //모든지역에 독버섯이 포함된다면 return -1;
    //string으로 farmsize범위를 저장후에 처리하는 방식도 가능

   //i , j for문 시작점을 설정하는 for문 
   //k , e for문 시작점서부터 farmsize 내부를 돌며 해당범위에
   //조건에 따라 처리
    for (int i = 0; i <= field.size() - farmSize; i++) {
        for (int j = 0; j <= field[0].size() - farmSize; j++) {
            cur_count = 0;
            for (int k = i; k < i+ farmSize; k++) {
                for (int e = j; e <j+ farmSize; e++) {
                    if (field[k][e] == 2) {
                        exist_mushroom = true;
                        break;
                    }
                    if (field[k][e] == 1)cur_count++;
                }
                if (exist_mushroom)break;
            }

            if (exist_mushroom) {
                exist_mushroom = false;
                continue;
            }
            min_count = min(min_count, cur_count);

        }
    }

    return min_count;
}
int main() {
    vector<vector<int>> maps;
    int n=0, m=0 , a=0;
    cin >> n >> m >> a;
    vector<int>v;
    //maps 틀만들기
    for (int i = 0; i < n; i++) {
        maps.push_back(v);
        for (int j = 0; j < m; j++) {
            maps[i].push_back(0);
        }
    }
    //데이터 줄단위로 입력받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &maps[i][j]);
        }
    }

	cout<<solution(maps,a);
}