#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    //n���� ������ �����ϰ� �� ������ �Ÿ� �� �ּҰ��� ���Ѵ�.
    //������ ���� ����� �� ��θ� ����.?
    //�ּڰ��� ���� Ŀ���ϹǷ� ���� ������ �Ÿ��� ���� ������� ��������������?

    //���� �ε���,�������ǰŸ��� ����
    sort(rocks.begin(), rocks.end());
    //���������� �Ÿ� �������� ����

    int min = 0;
    int max = distance;

    int avg = 0;
    int temp = 0;
    int left = 0;
    while (min <= max) {
        avg = (min + max) / 2;
        temp = 0;
        left = 0;
        //�����̰Ÿ��� ��պ��� ���� �ֵ��� �̾ƹ�������  == ��պ��� �����ֵ��� ���ƾ���
            //��պ��� �Ÿ��� �����ֵ� ���� ���ֱ�.
        for (auto t : rocks) {
            if (t - left < avg)temp++;
            else left = t;
        }

        //���ƾ��ϴ� �������� ���� ���� ������ ����. == avg�� Ű������
        if (temp <= n) {
            answer = std::max(avg, answer);
            min = avg + 1;



        }
        else {
            max = avg - 1;

        }



    }
    return answer;
}