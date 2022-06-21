#include <string>
#include <vector>

using namespace std;
int dfs(string& n, string& name, int answer, int point, int a) {
    int temp = 0;
    //1. 현재의 n이 name과 동일한지 확인 동일하다면 return answer;

    if (n == name)return answer;
    // point가 
    //2. n[point] == name[point]가 같은지 확인 같다면 4번으로
    if ((n[point] != name[point])) {
        //3. n[poiunt]에 변경이 필요하고 a!= name[point]라면
        if (a != name[point]) {
            //큰쪽 - 작은쪽의 계산값이 13보다 크다면  
            if (a < name[point]) {
                temp = name[point] - a;
            }
            else {
                temp = a - name[point];
            }
            if (temp > 13)temp = 26 - temp;
            answer += temp;
        }
    }
    //4. point+1 , point -1 두개로 나누어 함수호출
    dfs(n, name, answer + 1, point + 1, a);
    dfs(n, name, answer + 1, point - 1, a);
}
int solution(string name) {
    int answer = 0;
    // 65-90 JAZ = 70 65 90
    // 위= +1 아래 -1 65이하면 90 90이상이면 65
    // 좌우- 칸이동 
    // 입력받은 문자열 사이즈만큼 배열 
    // A,A.... 사이즈만큼 
    string n;
    int name_size = name.size();
    n.resize(name_size, 'A');
    answer = dfs(n, name, 0, 0, 65);

    return answer;
}