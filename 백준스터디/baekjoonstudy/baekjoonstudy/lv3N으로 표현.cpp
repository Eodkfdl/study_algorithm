#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <unordered_set>
using namespace std;


int solution(int N, int number) {
    int answer = -1; // 최솟값이 8보다 크면 -1을 return
    unordered_set<int> s[8]; // 정렬할 필요 X, 중복제거는 필요 - unordered_set 사용

    int sum = 0;
    for (int i = 0; i < 8; ++i) { // 각 항목에다가 N, NN, NNN... 넣어줌
        sum = 10 * sum + N;
        s[i].insert(sum);
    }

    for (int i = 1; i < 8; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int a : s[j]) {
                for (int b : s[i - j - 1]) {
                    s[i].insert(a + b);
                    s[i].insert(a - b);
                    s[i].insert(a * b);
                    if (b != 0)
                        s[i].insert(a / b);
                }
            }
        }
    }

    // set을 채웠으니 number가 set에 들어가 있는지 여부만 확인하면 된다!
    for (int i = 0; i < 8; ++i) {
        if (s[i].find(number) != s[i].end()) {
            answer = i + 1;
            break;
        }
    }


    return answer;
}

int solution2(int N, int number) {
    int answer = -1;
    //string으로 표현된 수식이 어떤값을 저장하고 있는지 저장
    map<string, int> nbox;
    //n은 N의 갯수에따라 나올수 있는 수식을 저장
    //n[1]= 5
    //n[2]= 5+5,5-5,5*5,5/5,5,55;
    //n[3]= 5+5+5,5+5-5,(5+5)*5,(5+5)/5,5-5+5......

    vector<vector<string>> n(9);


    char t[4] = { '+' , '-' , '*' ,'/' };
    string temp = "";
    int tn = 0;

    for (int i = 1; i < 9; i++) {

        for (int j = 0; j < i; j++)temp += to_string(N);
        nbox[temp] = stoi(temp);
        n[i].push_back(temp);
        if (number == stoi(temp))return i;
        temp = "";
    }

    for (int i = 2; i < 9; i++) {
        for (int j = 1; j < i; j++) {
            for (auto a : n[j]) {
                for (auto b : n[i - j]) {
                    for (auto c : t) {

                        switch (c) {
                        case '+':
                            tn = (nbox[a]) + (nbox[b]);
                            break;
                        case '-':
                            tn = nbox[a] - nbox[b];
                            break;
                        case '*':
                            tn = (nbox[a]) * (nbox[b]);
                            break;
                        case '/':
                            if (nbox[b] == 0)break;
                            tn = (nbox[a]) / (nbox[b]);
                            break;

                        }
                        if (tn == number)return i;

                        temp = " " + a + c + b;
                        n[i].push_back(temp);
                        nbox[temp] = tn;
                    }
                }
            }
        }
    }



    return answer;
}
int main() {
    int i, j;
    cin >> i>> j;
    cout << solution(i, j);
}