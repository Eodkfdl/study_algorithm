#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
//�������� 2�� ������ �迭 objectBallPoList�� �־����ϴ�.
//0,0���� �����ϴ� ������� hitVector -> u1,u2�� ���� ������ 2�� �����ֽ��ϴ�.
//0,0���� �����ϴ� ���� ó�� ������ ���� �ε����� ��ȯ�Ͻÿ�

constexpr double BallDiameter = 2;
bool is_col(vector<double> b1, vector<double> b2) {
    //�������� 1�̹Ƿ� �Ÿ��� 2�̸��̿������� ������ squrt�� ���� ������尡 ũ�� �����Ѱ����� ��
    return ((b1[0] - b2[0]) * (b1[0] - b2[0]) + (b1[1] - b2[1]) * (b1[1] - b2[1])) < 4;
}

bool cmp(vector<double> b1, vector<double> b2) {
    return b1[0] * b1[0] + b1[1] * b1[1] < b2[0] * b2[0] + b2[1] * b2[1];
}
int solution(vector<vector<double>> objectBallPosList, vector<double> hitVector) {
    int answer = -1;
    //�籸���� x,y ��ǥ�� �������� ������ 1¥�� ��
    //��Ʈ���� 1¥�� ��  
    //0,0���� �����ϹǷ�  ���� ���� u1,u2 x/u1=y/u2 


    double norm = sqrt((hitVector[0] * hitVector[0]) + (hitVector[1] * hitVector[1]));

    double y_norm = hitVector[1] / norm;
    double x = 0, y = 0;
    //������ �ְ�(������) 0,0���� �����ϴ� ���� �������� 0,0���� �Ÿ��� �������� ���� ��Ű��ȴ�.
       //���� �ε����� �����ϴ��� ��ǥ�� ���ε����� �ٽ�ã����.
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