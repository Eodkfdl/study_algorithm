#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int>e;

int sol(vector<int> c,int k) {
	int answer = 0;
	vector<int>a(k, 0);
	int size = c.size();
	vector<int>dp(size);
	for (int i = 0; i < size - k; i++) {
		for (int j = 0; j < k; j++) {
			dp[i] += c[j+i];
		}

	}
	for (int i = 0; i < size - k; i++) {
		answer = max(answer, dp[i]);
	}
	return  answer;
}
int c;
int temp;

int main() { 
	cin >> c;
	
	for (int i = 0; i < c; i++) {
		cin >> temp;
		e.push_back(temp);
	}
	cin >> c;

	cout<<sol(e, c);

}