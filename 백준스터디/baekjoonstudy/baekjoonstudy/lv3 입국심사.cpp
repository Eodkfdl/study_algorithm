#include <string>
#include <vector>

using namespace std;
//������ûó���� ����ҵ�. ��û���ð�,ó���ð�
long long solution(int n, vector<int> times) {
    long long answer = 0;
    //�ɻ���� 10����-> for���� ���鼭 �ð�%����ð�..?  times�� �ִ� �ּڰ����� �̺�Ž��?
    //�ּҷ��Ϸ��� ����ִ� �ɻ���� �ִ��� �� �ɻ���� �ɻ�ð�> �Ⱥ���ִ� �ɻ���� �ɻ�ð�+���ð� �ΰ͵� �Ǵ��� ���־����
    //ó�����۵��ڸ��� �ɻ���� ����ŭ ������

    //�ּҽð� : �ѹ��� ��� �ɻ��� ���� ��
    long long min = 1;
    //�ִ�ð�: �ɻ���� ���Ͻð� ���� �ɸ��� ��� 
    long long max = (long long)(times[times.size() - 1]) * n;
    //�̺�Ž���� ���� ��հ�.
    long long avg = 0;
    long long c = 0;

    while (min <= max) {
        avg = (min + max) / 2;
        c = 0;
        for (auto t : times)c += (avg / (long long)t);

        if (c >= n) {
            answer = avg;
            max = avg - 1;
        }
        else min = avg + 1;
    }

    return answer;
}