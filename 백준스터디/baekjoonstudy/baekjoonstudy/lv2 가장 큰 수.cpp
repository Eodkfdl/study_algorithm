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

    //1�� �ع�
     //1.�־��� int�� string���� �ٲپ� �� ���Ѵ�.
     //2.string ���� �ٲ� ������ �ٽ� int�� �ٲ� �� max(max_n,�ٲ��)
     //3.���� �ٲ���� �� ũ�ٸ� string�� answer�� ����.
     //������ ��� ��츦 ���� �� answer�� ����.

//2���ع�-������ ũ�� �񱳸� ���� �����ϰ� �ϴ� ���
// 
    //1.���� vector�� ����ū �� �� ã�´� �ش� ���� �ڸ����� ����
    //2.������ ��� �� �鵵 �ش� ������ �ڸ����� �°� 0�� �ٿ��ָ� ������ �ε���,����ũ��� ����
    //3.����ũ��� �����Ѵ�.
    //4.���ĵȼ��� ���� ������� �ε����� �ҷ��ͼ� to_string���� answer�� �ٿ���
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

    //3 ���ع�
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