#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    //���� �⺻������ �������� ���� ������ �ʿ��Ѱ�?
    //���� ����,����,�˻��� ��� �־��� ��쿡�� O(logn)�� �ð��� �����ϴ� �����Ʈ���� �����Ǿ��ִ�.
    unordered_map<string, bool> phone_n;

    //1. �ʿ� ��ȣ�� ����Ѵ�.
    for (auto t : phone_book)phone_n.insert(make_pair(t, true));
    //2.phone_book���� ��ȣ�� ������� �ѱ��ھ� temp�� �߰� �ϸ� map�ȿ��� �˻����Ѵ� map[Ű��]�� ����� �˻�
    for (int i = 0; i < phone_book.size(); i++) {
        string temp = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            temp += phone_book[i][j];
            //�˻������� �Ǵ� ��ȣ �̿��� �ٸ���ȣ�� ã�����ٸ� false�� ����  
            if (phone_n[temp] && temp != phone_book[i])return false;

        }
    }

    //��� �˻��� ��ģ�Ŀ��� false�� �������� �ʾҴٸ� 
    return answer;
}