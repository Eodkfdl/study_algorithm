#include <string>
#include <vector>
#include <map>
using namespace std;
//wcount�� ���������� �����ϸ鼭 a-> uuuuu�� �ɶ����� �ش� �ܾ ��� ° �ܾ����� �������ִ� ���

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
    //�־��� �ܾ ���ö����� Ž���ϱ�?..
    //��Ģ���� �־�̴� ��Ģ�� ã��
    //AAAA=4 AAAAA=5 AAAAE=6 AAAE=10
    //AAAAU=9�̶�� �߷а�����

    for (int i = 0; i < alph.size(); i++)dfs(alph.substr(i, 1));
    return words[word];
}