#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    //�ε��� ��ȣ�� n�϶� n~������ for���� ����
    //������ ��� ������ ��� index - n = �����Ƚð�
    //�ȶ����� ���  ��-n= �����Ƚð�
    //���� answer.push_back(�����Ƚð�); 
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i; j < prices.size(); j++) {
            if (prices[i] > prices[j] || j == prices.size() - 1) {
                answer.push_back(j - i);
                break;
            }
        }

    }
    return answer;
}