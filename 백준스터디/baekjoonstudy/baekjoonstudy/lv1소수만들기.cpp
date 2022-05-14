#include <vector>
#include <iostream>
using namespace std;
bool is_prime(int n) {
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0)cnt++;
    }
    if (cnt > 0)return false;
    return true;
}
int solution(vector<int> nums) {
    int answer = 0;
    //а╤гу nC3 
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (is_prime(nums[i] + nums[j] + nums[k]))answer += 1;
            }
        }
    }

    return answer;
}

int main() {
    int size = 0;
    vector<int>nums;
    cin >> size;
    int temp;
    for (int i = 0; i < size; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    cout << solution(nums);
}