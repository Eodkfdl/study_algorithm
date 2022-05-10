/*
메뚜기는 식량창고를 털려고 한다. 각식량창고는일직선으로 연결되어있고 한식량창고를 털경우
인접한 두식량창고는 개미전사에게 들킬 수 있어 털 수 없다.
예를 들어 각각 1 3 5 7 개의 식량이 들은 식량 창고가 있을때 1 5, 3 7 조합으로 털 수 있다. 
357을 같이 털 수 없다.
첫째 줄에 식량창고의 개수 N이 주어진다(3<=N<=100)
둘째줄에 공백을 기준으로 각 식량 창고에 저장 된 식량의 갯수 k개 주어진다 (0<=K<=1000)
얻을 수 있는 식량의 최댓값을 출력하라.
*/

//idea: 순차적으로 모든 상자를 더하는 것이 아니라(브루탈 아님) 
//1. 큰문제를 해결 하기위해 작은문제로 나누어 해결할수있는가 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Store;
int dp[100];
int n=1, temp;

int main() {
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> temp;
		Store.push_back(temp);
	}
	dp[0] = Store.front();
	dp[1] = max(Store[0], Store[1]);
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + Store[i]);
	}
	cout << dp[n - 1] << endl;

}