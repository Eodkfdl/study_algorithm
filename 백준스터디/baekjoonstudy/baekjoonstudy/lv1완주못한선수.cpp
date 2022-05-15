#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
//1. 중복,빠진거찾기 등  hash떠올리기
//2. map은 정렬된 자료구조이기때문에 삽입과 삭제에 있어 정렬을 유지하기위한 추가작업이필요하다.
//문제와같이 정렬이 필요하지 않은 경우에는 unodered_map을 사용하는것이 오버헤드를 없앨 수 있다.
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