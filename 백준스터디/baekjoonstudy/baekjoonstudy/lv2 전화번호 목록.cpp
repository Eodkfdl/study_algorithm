#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    //맵은 기본적으로 오름차순 정렬 정렬이 필요한가?
    //맵은 삽입,삭제,검색에 모두 최악의 경우에도 O(logn)의 시간을 보장하는 레드블랙트리로 구현되어있다.
    unordered_map<string, bool> phone_n;

    //1. 맵에 번호를 등록한다.
    for (auto t : phone_book)phone_n.insert(make_pair(t, true));
    //2.phone_book안의 번호를 순서대로 한글자씩 temp에 추가 하며 map안에서 검색을한다 map[키값]은 밸류값 검색
    for (int i = 0; i < phone_book.size(); i++) {
        string temp = "";
        for (int j = 0; j < phone_book[i].size(); j++) {
            temp += phone_book[i][j];
            //검색기준이 되는 번호 이외의 다른번호가 찾아졌다면 false를 리턴  
            if (phone_n[temp] && temp != phone_book[i])return false;

        }
    }

    //모든 검색을 마친후에도 false를 리턴하지 않았다면 
    return answer;
}