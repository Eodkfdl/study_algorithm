#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    //������ ��ȣ�� ������� �޾Ƽ� push pop�� �ݺ��Ѵ�.
    stack<bool> st;
    for (auto t : s) {
        //ó�������� ��ȣ�� )�̸� �߸������Ƿ� false����
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
    //st�� ��������ʴ�->¦�� �̷������ �������� �ִ� false return;
    if (!st.empty())return false;

    return true;
}