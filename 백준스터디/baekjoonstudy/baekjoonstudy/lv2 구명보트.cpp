#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    //오름차순 정렬을한후 제일 작은것과 짝지을 수 있는 것중 제일 큰것을 찾는다
    sort(people.begin(), people.end());
    int s = 0;
    int end = people.size() - 1;

    while (s <= end) {
        if ((people[s] + people[end]) <= limit) {
            s++;
            end--;
        }
        else end--;
        answer++;
    }

    return answer;
}