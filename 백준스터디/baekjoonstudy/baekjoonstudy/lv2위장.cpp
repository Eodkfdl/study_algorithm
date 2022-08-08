#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    //key =ī�װ� value=���� 
    //ī�װ��� ���� = �ڸ��� ����= �ش��ڸ����� �����ִ°���Ǽ�
    //�� �ڸ����� ����Ǽ�*����Ǽ�...�ڸ��Ǽ� =

    //string �ǻ�������, int �ǻ��� �̸� ���� 
    map<string, int> c;

    for (auto cl : clothes) {//key= �ǻ����̸�  
        //map[key] = ������
        c[cl[1]] += 1;
    }

    //��� �ڸ��� ���� ��������������츦 �߰����༭ �����ش�.
    for (auto t : c) {
        answer = answer * (t.second + 1);
    }
    //�ƿ����Դ°�� -1 
    return answer - 1;
}