#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {

    //x>=y 
    //brown = 2x+2y-3
    //yellow = (x-1)(y-1) = xy-x-y
    //2yellow+brown=2xy-3;
   //노랑과 갈색은 상수취급을해주면
    //(2ye+br-3)/2 = xy;
    //(br-3)/2=x+y;
    //y=(br-3)/2-x
    //-2x^2+(br-3)x=(2ye+br-3);
    vector<int> answer;
    int sum = brown + yellow;
    for (int height = 3; ; height++) {
        if (!(sum % height)) {
            int weight = sum / height;
            if (((height - 2) * (weight - 2)) == yellow) {
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}