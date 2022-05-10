#include <string>
#include <vector>
#include <set>
#include<algorithm>
#include<iostream>

using namespace std;
//문자열이 지워지거나 문자열이 추가되는 경우가 많다. 따라서 문자열길이가 조건으로 들어갈때마다 
//길이를 체크를 해주지않으면 잘못된 접근이될수있다
//string.erase(시작인덱스번호,count)-> count를 안쓰고쓰면 해당 인덱스부터 끝까지 지워버린다.

void comma(string& new_id) {
    for (int i = 0; i < new_id.length(); i++) {
        if (new_id[i] == '.') {
            //.이연속되면 연속된 . 삭제
            int cnt = 0;
            //.가연속되면지우기
            for (int j = 0; new_id[i + j] == '.'; j++)cnt++;
            if (cnt > 0)  new_id.erase(i + 1, cnt - 1);
            //4단계 만약 해당i가 맨앞이거나 맨뒤면 없애기
            if (i == 0 || i == new_id.length() - 1) {
                new_id.erase(i,1);
                i--;
            }
        }
    }
}

bool correct(const char& c) {
    if (('a' <= c && c <= 'z') ||('0'<=c&&c<='9') || c == '.' || c == '-' || c == '_') {
        return true;
    }
    return false;
}
string solution(string new_id) {
    string answer = "";
   //1,2단계 대문자 -> 소문자 알파벳소문자 아니면 제거
    int size = new_id.size();
    for (int i = 0;i< new_id.length();i++) {
        if ('A'<=new_id[i] && new_id[i] <= 'Z')new_id[i] = new_id[i] +('a'- 'A');
        if (!correct(new_id[i])) {
            new_id.erase(new_id.begin() + i);
            i--;
        }
    }
    //3단계 .이 2번이상연속되면 하나의.으로 압축
    
    comma(new_id);
    //5단계 new_id의 사이즈가 0 이면 "a"대입하기
    size = new_id.length();
    if (size == 0) {
        new_id += "a";
    }
    //6단계 new_id의 길이가 16자이상이면 15자만 남긴다. 맨끝이.이라면 .을삭제한다.
    size = new_id.size();
    if (size > 15) {
        new_id.erase(15, size - 15);
    }
    comma(new_id);
    //7단계 new_id길이가 2자 이하라면 new_id의 마지막문자를 new_id의 길이가 3이되도록 마지막문자를반복한다.
    size = new_id.length();
    if (size<=2){
        
        for (; size < 3; size++) {
            new_id += new_id.back();
        }
    }
    answer = new_id;
    return answer;
}
int main() {
    string new_id;
    cin >> new_id;

    cout << solution(new_id) << endl;
}