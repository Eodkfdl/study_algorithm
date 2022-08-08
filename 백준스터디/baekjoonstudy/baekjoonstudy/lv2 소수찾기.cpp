#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
bool is_prime(int n) {
    if (n == 1||n==0)return false;
    for (int i = 2; i < n; i++)if (n % i == 0)return false;
    return true;
}
//next_permutation을 통해 순열을 구하여 경우의 수를 따지는게 핵심이다.
//next_permutation의 do{ A } A구간에서는 순열의 경우의수에 따라 바뀐 numbers에 접근이 가능하다

int solution(string numbers) {
    int answer = 0;
    set<int> t;
    string temp;
    int r = 0;
    sort(numbers.begin(), numbers.end());
    do
    {
        for (r = 1; r <=numbers.size(); r++) {
            for (int i = 0; i < r; i++) {
                temp.push_back(numbers[i]);
            }
            t.insert(stoi(temp));
            temp = "";
        }
        
        
    } while (next_permutation(numbers.begin(), numbers.end()));

    for (auto a : t) {
        if (is_prime(a))answer++;
    }

    return answer;
}
int main() {
    string s;
    cin >> s;
    cout << solution(s);
}