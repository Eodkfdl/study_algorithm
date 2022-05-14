#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
//1. �ߺ�,������ã�� ��  hash���ø���
//
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> hash;
    for (auto t : participant) {
        if (hash.end() == hash.find(t))hash.insert(make_pair(t, 1));
        else hash[t]++;
    }
    for (auto t : completion) {
        hash[t] -= 1;
    }
    for (auto t : hash) {
        if (t.second > 0)answer += t.first;
    }
    return answer;
}