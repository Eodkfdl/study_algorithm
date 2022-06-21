#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution1(string s)
{
    int answer = 0;
    auto t = s.begin();
    size_t i = 0;
   
    while (t != s.end()) {
        i = t - s.begin();
        t++;
        if (s[i] == s[i + 1]) {
            s.erase(s.begin()+i,s.begin()+i+2);
            t = s.begin();
        }

    }
    if (s.empty())answer = 1;

    return answer;
}
int solution(string s)
{
    int answer = 0;
    stack<char> st;
    //스택에 전부 넣어두고 
    char t1, t2;
    auto it = s.begin();
    while (it != s.end()) {
        if (st.empty()) {
            st.push(*it);
            it++;
            continue;
        }
        t1 = st.top();
        if (t1 != *it) {
            st.push(*it);
        }
        else st.pop();
        it++;
    }
    if (st.size() == 0)answer = 1;



    return answer;
}
int main() {
    string s;
    
    cin>>s;
    cout << solution(s);
}