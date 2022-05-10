#include <string>
#include <vector>
#include <set>
#include<algorithm>
#include<iostream>

using namespace std;
//���ڿ��� �������ų� ���ڿ��� �߰��Ǵ� ��찡 ����. ���� ���ڿ����̰� �������� �������� 
//���̸� üũ�� ������������ �߸��� �����̵ɼ��ִ�
//string.erase(�����ε�����ȣ,count)-> count�� �Ⱦ����� �ش� �ε������� ������ ����������.

void comma(string& new_id) {
    for (int i = 0; i < new_id.length(); i++) {
        if (new_id[i] == '.') {
            //.�̿��ӵǸ� ���ӵ� . ����
            int cnt = 0;
            //.�����ӵǸ������
            for (int j = 0; new_id[i + j] == '.'; j++)cnt++;
            if (cnt > 0)  new_id.erase(i + 1, cnt - 1);
            //4�ܰ� ���� �ش�i�� �Ǿ��̰ų� �ǵڸ� ���ֱ�
            if (i == 0 || i == new_id.length() - 1) {
                new_id.erase(i,1);
                i--;
            }
        }
    }
}

bool correct(const char& c) {
    if (('a' <= c && c <= 'z') ||('0'<=c&&c<='9') || c == '.' || c == '-' || c == '_') {
        return true;
    }
    return false;
}
string solution(string new_id) {
    string answer = "";
   //1,2�ܰ� �빮�� -> �ҹ��� ���ĺ��ҹ��� �ƴϸ� ����
    int size = new_id.size();
    for (int i = 0;i< new_id.length();i++) {
        if ('A'<=new_id[i] && new_id[i] <= 'Z')new_id[i] = new_id[i] +('a'- 'A');
        if (!correct(new_id[i])) {
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }
    //3�ܰ� .�� 2���̻󿬼ӵǸ� �ϳ���.���� ����
    
    comma(new_id);
    //5�ܰ� new_id�� ����� 0 �̸� "a"�����ϱ�
    size = new_id.length();
    if (size == 0) {
        new_id += "a";
    }
    //6�ܰ� new_id�� ���̰� 16���̻��̸� 15�ڸ� �����. �ǳ���.�̶�� .�������Ѵ�.
    size = new_id.size();
    if (size > 15) {
        new_id.erase(15, size - 15);
    }
    comma(new_id);
    //7�ܰ� new_id���̰� 2�� ���϶�� new_id�� ���������ڸ� new_id�� ���̰� 3�̵ǵ��� ���������ڸ��ݺ��Ѵ�.
    size = new_id.length();
    if (size<=2){
        
        for (; size < 3; size++) {
            new_id += new_id.back();
        }
    }
    answer = new_id;
    return answer;
}
int main() {
    string new_id;
    cin >> new_id;

    cout << solution(new_id) << endl;
}