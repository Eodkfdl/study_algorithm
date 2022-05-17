#include <vector>
#include<set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int max = nums.size() / 2;
    set<int>po;
    for (int t : nums)po.insert(t);
    if (max > po.size())answer = po.size();
    else answer = max;
    return answer;
}