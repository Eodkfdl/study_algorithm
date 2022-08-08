#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int temp = 0;
    int w = 0, h = 0;
    //�������� ū ���̸� ���� ���°� ����Ʈ
    //���� ���� ���� �߿� �������� ũ�Ⱑ ū ���̸� ���� �� �ִ�,�ּҸ� ���Ѵ�.
    for (auto t : sizes) {
        if (t[0] < t[1]) {
            w = max(w, t[1]);
            h = max(h, t[0]);
        }
        else {
            w = max(w, t[0]);
            h = max(h, t[1]);
        }
    }
    answer = w * h;


    return answer;
}