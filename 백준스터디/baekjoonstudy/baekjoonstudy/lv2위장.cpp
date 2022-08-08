#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    //key =카테고리 value=종류 
    //카테고리의 갯수 = 자릿수 종류= 해당자리마다 들어갈수있는경우의수
    //즉 자리마다 경우의수*경우의수...자리의수 =

    //string 의상의종류, int 의상의 이름 갯수 
    map<string, int> c;

    for (auto cl : clothes) {//key= 의상의이름  
        //map[key] = 벨류값
        c[cl[1]] += 1;
    }

    //모든 자리를 돌며 착용하지않은경우를 추가해줘서 곱해준다.
    for (auto t : c) {
        answer = answer * (t.second + 1);
    }
    //아예안입는경우 -1 
    return answer - 1;
}