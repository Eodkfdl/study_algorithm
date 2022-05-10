#include<iostream>
using namespace std;

constexpr int N = 30;

int ap;
char* ptr;

int store;

int dp[N];
void fibo_topdown(int n)
{
    if (ptr == NULL)ptr = (char*)&n;//ù���� �������ǰ�.
    else printf("address :%p (%d byte)\n", &n, ptr - (char*)&n);//ȣ��� �Լ��� �ּڰ��� ���������ӿ��� ��ƸԴ� �޸�ũ�⸦ ���

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
    //�Ǻ���ġ�� 6��°��
    fibo_botomup(6);
    cout << dp[6] << endl;
}