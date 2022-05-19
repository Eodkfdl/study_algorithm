#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(int a, int b) {
    string temp, temp2;
    temp = to_string(a);
    temp2 = to_string(b);
    return temp + temp2 > temp2 + temp;
}
string solution(vector<int> numbers) {
    string answer = "";
    map<int, int, greater<int>> temp;
    int max_n = 0, digit = 0, digit_n = 1, index = 0;

    //1번 해법
     //1.주어진 int를 string으로 바꾸어 다 더한다.
     //2.string 으로 바뀐 수들을 다시 int로 바꾼 후 max(max_n,바뀐수)
     //3.만약 바뀐수가 더 크다면 string을 answer에 저장.
     //순열로 모든 경우를 비교한 후 answer를 리턴.

//2번해법-숫자의 크기 비교를 가장 간단하게 하는 방식
// 
    //1.받은 vector중 가장큰 수 를 찾는다 해당 수의 자릿수를 저장
    //2.나머지 모든 수 들도 해당 숫자의 자릿수와 맞게 0을 붙여주며 백터의 인덱스,숫자크기로 저장
    //3.숫자크기로 정렬한다.
    //4.정렬된숫자 수의 순서대로 인덱스를 불러와서 to_string으로 answer에 붙여줌
//1
    //for (auto t : numbers)(max_n = max(max_n, t));
    //while (max_n >= 10) {
    //    max_n = max_n / 10;
    //    digit++;
    //}
    //for (int i = 0; i < digit; i++)digit_n = digit_n * 10;
    ////2
    //for (auto t : numbers) {
    //    int a = t;
    //    if (t <= digit_n) {
    //        while (a < digit_n) {
    //            a = t * 10;
    //        }
    //        temp.insert(make_pair(a, index));
    //    }
    //    else temp.insert(make_pair(t, index));
    //    index++;
    //}
    ////3 
    //
    //for (auto t : temp) {
    //    answer += to_string(numbers[t.second]);
    //}

    //3 번해법
    sort(numbers.begin(), numbers.end(), cmp);
    for (auto t : numbers) {
        answer += to_string(t);
    }
    int zero_n = 0;
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] == '0')zero_n++;
    };
    if (zero_n == answer.size())answer = "0";
    return answer;
}
vector<int>numbers;
int main() {
    int n = 0,temp=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        numbers.push_back(temp);
    }
    cout << solution(numbers);

}