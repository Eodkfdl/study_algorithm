#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct comf {
    bool operator()(pair<int, int>a, pair<int, int>b) {
        return a.second > b.second;
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    //ó�� �����̵� ����Ʈ -> ������� ��ģ �ð��� ���� 1 ,2 �����ϴ�, ������ ��û���� ������� �ɸ� ��սð��� 2�ǰ�찡 ���� �� ������.
    //�۾��ð��� �� ��û�ð��� �����ΰ��� ���� ó�� �� ��� 
    //�۾��ð��� ª������ ���� ó�� �� ���

    //a b ������ ��û�� ������ b�� �۾��ð��� a�� �۾��ð����� ū ���
    //t1 = b�� �۾��ð� - a�� �۾��ð�
    //t2 = b�� ��û�ð� - a�� ��û�ð�
    //t1>t2�ΰ�� b�� ���� ó���ؾ��Ѵ�.
    //b�� �۾��ð� -a�� �۾��ð� > b�ǿ�û�ð� - a�ǿ�û�ð�
    //b�� �۾��ð� -b�� ��û�ð� > a�� �۾��ð� - a�ǿ�û�ð�
    //�۾��� �ɸ��� �ѽð�
    //��û�ð�,�۾��ð����� ������ 
    //���� ��û������ ��� -> ���� 
    //�������������� jobs�� ������ jobs[n][0]������ ������� �ԷµǾ��ִٰ� �����ϰ� �ڵ�
    int now = 0;
    //request- Ž�������� ���̱� ���� Ž���Ѱ����� ����
    int n = 0;

    int avg_time = 0;
    //ó������ ��û

    //��û ����� cmp�� �������ؼ� ����
    priority_queue<pair<int, int>, vector<pair<int, int>>, comf> pq;
    //
    sort(jobs.begin(), jobs.end());


    while (n < jobs.size() || !pq.empty()) {
        //����ð��� �߰����� �� �ִ� ��� �۾����� pq�� �־��ش�.
        if (n < jobs.size() && jobs[n][0] <= now) {

            pq.push({ jobs[n][0],jobs[n][1] });
            n++;
            //
            continue;
        }

        //pq���� ���� �տ� �ִ� �༮ ó�����ֱ�
        if (!pq.empty()) {
            auto temp = pq.top();
            now += temp.second;
            avg_time += now - temp.first;
            pq.pop();
        }
        else now = jobs[n][0];
    }


    answer = avg_time / jobs.size();
    return answer;
}