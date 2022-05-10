#include <string>
#include <vector>
#include <set>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    int size = report.size();
    set<pair<string, string>>R;
    
    //1.  �Ű��������� ���Ѿ��̵� ����������� pair������ �ٲٱ� 
    for (int i = 0; i < size; i++) {
        int it = report[i].find(" ");
        //�Ű����id,�Ű���id ������ ����

        R.insert(make_pair( report[i].substr(it, report[i].size()),report[i].substr(0, it)));

    }
    //2. �Ű���� id �������� ����

    auto iter = R.begin();
    auto t3 = R.begin();
    int n = 0;
    bool f = false;
    auto t1 = *iter;
    auto t2 = *iter;
    for (;f==false ;) {
        //3. �Ű���� id�� �޶����� ����üũ
        
        t1 = *iter;
        iter++;
        if (iter != R.end())t2 = *iter;
        else f = true;
        n++;
        if (t1.first != t2.first||f==true) {//�޶����°� Ȯ��
                
                if (n >=k) {//�ش籸������ �Ű��ڰ� k ���̻��̶��
                      for (; t3 != iter; t3++) {//���Ű����� answer���� +1���ش�.
                        int temp = find(id_list.begin(), id_list.end(), (*t3).second) - id_list.begin();
                        answer[temp] += 1;
                      }
                    
                }
                n = 0;
                t3 = iter;
        }

    }

    

    return answer;
}
int n;
string str;
vector<string>id_list,report;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        id_list.push_back(str);
    }
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin,str);
        report.push_back(str);
    }
    cout << "�Ű��ּҴ���: ";
    cin >> n;
    auto v = solution(id_list, report, n);
    for (auto s : v) {
        cout << s<<" ,";
    }
    
}