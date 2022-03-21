// 공포도가 x인 모험가는 반드시 x명으로 구성한 모험가 그룹에 참여해야
//여행 떠날수있다.
//최대 몇그룹의 모험가그룹이 여행을 떠날수있는가?

// 정렬후, 순서대로 가능한 수를 제외시켜나가면서 점진적으로
//몇번시행하는지 알아보는 형태 전형적인 그리디알고리즘

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int temp;
vector<int> Fear;
int cnt;
int main() {
	cin >> n;
	for (; n > 0;n--) {
		
		cin >> temp;
		Fear.push_back(temp);
	}
	// 정렬하여 맨앞의 수부터 최댓값의 수만큼 날릴 수 있는지 확인후 날릴수있으면 날리고 다시
	sort(Fear.begin(), Fear.end());
	for (; Fear.empty() != true;) {
		int g = Fear.front();//가장앞에있는놈의 공포만큼 털어주기
		if (g > Fear.size())break;//남은수가 공포보다 작으면 그룹맺기 끝
		for (; g != 0; g--) {
			Fear.pop_back();
		}
		cnt++;
	}
	cout << cnt;

}