#include <string>
#include <vector>
#include <map>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int>rank;
    int f[5] = { 1,2,3,4,5 };
    int s[8] = { 2,1,2,3,2,4,2,5 };
    int t[10] = { 3,3,1,1,2,2,4,4,5,5 };
    int n = answers.size();
    int temp = 0;
    rank.push_back(0);
    rank.push_back(0);
    rank.push_back(0);
    for (int i = 0; i != answers.size(); i++) {
        if (f[i%5] == answers[i])rank[0] += 1;
        if (s[i%8] == answers[i])rank[1] += 1;
        if (t[i%10] == answers[i])rank[2] += 1;
    }
    
    auto max = max_element(rank.begin(), rank.end());
    for (int i = 0; i < 3; i++) {
        if (*max== rank[i])answer.push_back(i + 1);
    }
    return answer;
}

int main() {
    int n = 0;
    char input[10000];
    cin.getline(input, 10000);
    vector<int>answer;
    while (input[n] != '\0') {
        answer.push_back(input[n]-48);
        n++;
    }
    auto temp= solution(answer);
    for (auto t : temp) {
        cout << t;
    }
}