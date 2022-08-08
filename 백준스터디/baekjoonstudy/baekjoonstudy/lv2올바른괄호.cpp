#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    //각각의 괄호를 명령으로 받아서 push pop을 반복한다.
    stack<bool> st;
    for (auto t : s) {
        //처음나오는 괄호가 )이면 잘못됐으므로 false리턴
        if (t == ')' && st.empty())return false;
        switch (t) {
        case '(':
            st.push(true);
            break;
        case ')':
            st.pop();
            break;
        }

    }
    //st가 비어있지않다->짝이 이루어지지 않은것이 있다 false return;
    if (!st.empty())return false;

    return true;
}