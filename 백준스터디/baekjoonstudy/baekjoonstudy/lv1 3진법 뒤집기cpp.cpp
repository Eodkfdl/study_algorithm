#include<string>
#include<vector>
#include<iostream>
using namespace std;

string convertion(int num, int notation) {
    string res = "";
    int mok = num;
    int nmg = 0;
    res.reserve();
    while (mok >0) {
        nmg = mok % notation;
        mok /= notation;

        // 10�������� ũ�� �������� 10 �̻��� ���
        if (notation > 10 && nmg >= 10) {
            res = (char)(nmg + 55) + res;
        }
        else {
            res = to_string(nmg) + res;
        }

    }
    return res;
}
int reconvertion(string s,int notation) {
    int ret = 0;
    int size = s.size()-1;
    for (int i = 0; i <= size; i++) {
       ret+= int((s[i]-48)*pow(notation, size-i));
    }
    return ret;
}
int main() {
    cout << reconvertion(convertion(4, 2),2);
}