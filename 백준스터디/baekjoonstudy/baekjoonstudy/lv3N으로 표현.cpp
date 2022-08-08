#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <unordered_set>
using namespace std;


int solution(int N, int number) {
    int answer = -1; // �ּڰ��� 8���� ũ�� -1�� return
    unordered_set<int> s[8]; // ������ �ʿ� X, �ߺ����Ŵ� �ʿ� - unordered_set ���

    int sum = 0;
    for (int i = 0; i < 8; ++i) { // �� �׸񿡴ٰ� N, NN, NNN... �־���
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

    // set�� ä������ number�� set�� �� �ִ��� ���θ� Ȯ���ϸ� �ȴ�!
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
    //string���� ǥ���� ������ ����� �����ϰ� �ִ��� ����
    map<string, int> nbox;
    //n�� N�� ���������� ���ü� �ִ� ������ ����
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