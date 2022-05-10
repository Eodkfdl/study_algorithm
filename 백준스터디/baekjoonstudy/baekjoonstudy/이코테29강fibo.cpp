#include<iostream>
using namespace std;

constexpr int N = 30;

int ap;
char* ptr;

int store;

int dp[N];
void fibo_topdown(int n)
{
    if (ptr == NULL)ptr = (char*)&n;//첫시작 포인터의값.
    else printf("address :%p (%d byte)\n", &n, ptr - (char*)&n);//호출된 함수의 주솟값과 스택프레임에서 잡아먹는 메모리크기를 출력

    if (n != 2)fibo_topdown(n - 1);
    if (n > 1) dp[n] = dp[n - 1] + dp[n - 2];

}
void fibo_botomup(int n) {
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i < n + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}
int main() {
    dp[0] = 0;
    dp[1] = 1;
    fibo_topdown(N-1);
    cout <<dp[N-1] << endl;
    //피보나치의 6번째항
    fibo_botomup(6);
    cout << dp[6] << endl;
}