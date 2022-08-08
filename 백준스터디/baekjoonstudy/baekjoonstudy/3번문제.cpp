#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
//반지름이 2인 공들의 배열 objectBallPoList이 주어집니다.
//0,0에서 시작하는 방향백터 hitVector -> u1,u2를 가진 반지름 2인 공이있습니다.
//0,0에서 시작하는 공과 처음 만나는 공의 인덱스를 반환하시오

constexpr double BallDiameter = 2;
bool is_col(vector<double> b1, vector<double> b2) {
    //반지름이 1이므로 거리가 2미만이여야지만 만난것 squrt는 연산 오버헤드가 크니 제곱한것으로 비교
    return ((b1[0] - b2[0]) * (b1[0] - b2[0]) + (b1[1] - b2[1]) * (b1[1] - b2[1])) < 4;
}

bool cmp(vector<double> b1, vector<double> b2) {
    return b1[0] * b1[0] + b1[1] * b1[1] < b2[0] * b2[0] + b2[1] * b2[1];
}
int solution(vector<vector<double>> objectBallPosList, vector<double> hitVector) {
    int answer = -1;
    //당구공의 x,y 좌표점 기준으로 반지름 1짜리 구
    //히트볼도 1짜리 구  
    //0,0에서 시작하므로  방향 백터 u1,u2 x/u1=y/u2 


    double norm = sqrt((hitVector[0] * hitVector[0]) + (hitVector[1] * hitVector[1]));

    double y_norm = hitVector[1] / norm;
    double x = 0, y = 0;
    //직선상에 있고(만나고) 0,0에서 시작하는 공과 만나려면 0,0과의 거리를 기준으로 정렬 시키면된다.
       //원래 인덱스를 저장하던지 좌표로 그인덱스를 다시찾던지.
    sort(objectBallPosList.begin(), objectBallPosList.end(), cmp);
    for (int i = 0; i < objectBallPosList.size(); i++) {
        vector<double> vec;
        vec.push_back(objectBallPosList[i][0]);
        if (objectBallPosList[i][0] != 0)vec.push_back(objectBallPosList[i][0] * y_norm);
        else vec.push_back(0);

        if (is_col(objectBallPosList[i], vec)) {
            x = objectBallPosList[i][0];
            y = objectBallPosList[i][1];
            break;
        }
    }
    for (int i = 0; i < objectBallPosList.size(); i++) {
        if (x == objectBallPosList[i][0] && y == objectBallPosList[i][1])return i;
    }
    return answer;
}
int main() {
	
}