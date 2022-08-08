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
    //차량무게,진입시간 저장
    queue<pair<int, int>> tr;
    //차량순서
    int t_n = 0;
    //다리에 올라가 있는 차량의 총무게
    int s_w = 0;
    //다리 길이 -> 차량 최대 대수,한대 지나갈때 최소시간.
    //weight -> 최대차량무게

    //첫번째차량 

    //i는 시간
    for (int i = 0; t_n < truck_weights.size(); i++) {
        //다리위에 최대 대수 미만이고 최대 중량미만이면 다리위에올린다 
        if (tr.size() < bridge_length && s_w + truck_weights[t_n] <= weight) {
            tr.push({ truck_weights[t_n],i });
            s_w += truck_weights[t_n];
            t_n++;
        }
        //차량 queue에서 현재시간(i) - 진입시간 >= 다리길이 인 녀석 팝해주자
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