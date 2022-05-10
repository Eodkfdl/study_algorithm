#include <string>
#include <vector>
#include<iostream>
using namespace std;

int sol(int n, int m, int k) {
	int answer = 1;
	vector<int>p(n+1, 0);
	int pos = 1;
	p[1] = 1;

	while (1) {
		if (p[pos] >= m)break;

		if (p[pos] % 2 == 0) {
			if (pos + k >= n) {
				pos = (pos + k) % n;
			}
			else pos += k;
			p[pos] += 1;
		}
		else {
			if (pos - k <= 0) {
				pos = n - (k - pos);
			}
			else pos -= k;

			p[pos] += 1;
		}
		answer++;
	}
	return answer;
}
int n, m, k;
int main() {

	cin >> n>>m>>k;
	cout << sol(n, m, k);
}