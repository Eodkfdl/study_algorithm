#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    //�������� ���������� ���� �����Ͱ� ¦���� �� �ִ� ���� ���� ū���� ã�´�
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