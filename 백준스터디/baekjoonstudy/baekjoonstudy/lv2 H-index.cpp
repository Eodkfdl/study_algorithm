#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    //���� ū���� 0�̶�� H-index �� 0�̴�
    if (!citations[0])return 0;
    for (int i = 0; i < citations.size(); i++) {
        //h-index���� ���̶��
        if (citations[i] > i) answer++;
        //�ִ밪�� ����ٸ�
        else    break;
    }
    return answer;
}