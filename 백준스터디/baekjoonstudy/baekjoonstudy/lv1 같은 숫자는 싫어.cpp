#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    //���Ǽ��ڿ� ���Ǽ��ڸ� ���ϰ� ���������� ex�� ���� �� answer�� �־��ֱ�.
    //unordered_set�� �̿��ϴ� ����������� �����ϰ� ���������ؼ� �׳� �̷�����
    int ex = -1;
    for (auto t : arr) {
        if (ex != t) {
            ex = t;
            answer.push_back(t);
        }
    }
    return answer;
}