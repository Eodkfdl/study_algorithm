#include <string>
#include <vector>
#include <map>
using namespace std;
//wcount는 전역변수로 선언하면서 a-> uuuuu가 될때까지 해당 단어가 몇번 째 단어인지 저장해주는 방식

int wcount = 1;
string alph = "AEIOU";
map<string, int> words;

void dfs(string w) {
    if (w.size() > 5)return;
    words[w] = wcount++;
    for (int i = 0; i < alph.size(); i++)dfs(w + alph.substr(i, 1));
}

int solution(string word) {
    int answer = 0;
    //주어진 단어가 나올때까지 탐색하기?..
    //규칙성이 있어보이니 규칙을 찾자
    //AAAA=4 AAAAA=5 AAAAE=6 AAAE=10
    //AAAAU=9이라고 추론가능함

    for (int i = 0; i < alph.size(); i++)dfs(alph.substr(i, 1));
    return words[word];
}