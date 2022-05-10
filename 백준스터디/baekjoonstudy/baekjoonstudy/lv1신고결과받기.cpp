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
    
    //1.  신고한유저와 당한아이디를 공백기준으로 pair쌍으로 바꾸기 
    for (int i = 0; i < size; i++) {
        int it = report[i].find(" ");
        //신고당한id,신고한id 순서로 저장

        R.insert(make_pair( report[i].substr(it, report[i].size()),report[i].substr(0, it)));

    }
    //2. 신고당한 id 기준으로 정렬

    auto iter = R.begin();
    auto t3 = R.begin();
    int n = 0;
    bool f = false;
    auto t1 = *iter;
    auto t2 = *iter;
    for (;f==false ;) {
        //3. 신고당한 id가 달라지는 끝점체크
        
        t1 = *iter;
        iter++;
        if (iter != R.end())t2 = *iter;
        else f = true;
        n++;
        if (t1.first != t2.first||f==true) {//달라지는곳 확인
                
                if (n >=k) {//해당구간까지 신고자가 k 명이상이라면
                      for (; t3 != iter; t3++) {//모든신고자의 answer값을 +1해준다.
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
    cout << "신고최소누적: ";
    cin >> n;
    auto v = solution(id_list, report, n);
    for (auto s : v) {
        cout << s<<" ,";
    }
    
}