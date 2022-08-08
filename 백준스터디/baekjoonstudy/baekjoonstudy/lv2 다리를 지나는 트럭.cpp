#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool dec(int a, int b) {
    return a > b;
}
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    //��������,���Խð� ����
    queue<pair<int, int>> tr;
    //��������
    int t_n = 0;
    //�ٸ��� �ö� �ִ� ������ �ѹ���
    int s_w = 0;
    //�ٸ� ���� -> ���� �ִ� ���,�Ѵ� �������� �ּҽð�.
    //weight -> �ִ���������

    //ù��°���� 

    //i�� �ð�
    for (int i = 0; t_n < truck_weights.size(); i++) {
        //�ٸ����� �ִ� ��� �̸��̰� �ִ� �߷��̸��̸� �ٸ������ø��� 
        if (tr.size() < bridge_length && s_w + truck_weights[t_n] <= weight) {
            tr.push({ truck_weights[t_n],i });
            s_w += truck_weights[t_n];
            t_n++;
        }
        //���� queue���� ����ð�(i) - ���Խð� >= �ٸ����� �� �༮ ��������
        auto f = tr.front();
        if (i - f.second + 1 == bridge_length) {
            tr.pop();
            s_w -= f.first;
        }

        if (t_n == truck_weights.size())answer = i + bridge_length;
    }
    return answer + 1;
}
int main() {
    int n = 0, m = 0, a = 0;
    cin >> n >> m >> a;
    int temp = 0;
    vector<int> tr;
    for (; a > 0; a--) {
        cin >> temp;
        tr.push_back(temp);
    }
    cout << solution(n, m, tr) << endl;
}