#include<iostream>
using namespace std;
//최대공약수떠올리기어려운문제

int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}
long long solution(int w, int h) {
    long long answer = 1;
    answer = 0;
    
    answer = ((long long)w * h - (w + h) + GCD(w, h));
    return answer;
}
int w,h;
int main() {
    
    cin >> w>> h;
    cout << solution(w, h);
}