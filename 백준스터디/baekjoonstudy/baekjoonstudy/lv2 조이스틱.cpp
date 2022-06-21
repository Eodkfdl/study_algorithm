#include <string>
#include <vector>

using namespace std;
int dfs(string& n, string& name, int answer, int point, int a) {
    int temp = 0;
    //1. ������ n�� name�� �������� Ȯ�� �����ϴٸ� return answer;

    if (n == name)return answer;
    // point�� 
    //2. n[point] == name[point]�� ������ Ȯ�� ���ٸ� 4������
    if ((n[point] != name[point])) {
        //3. n[poiunt]�� ������ �ʿ��ϰ� a!= name[point]���
        if (a != name[point]) {
            //ū�� - �������� ��갪�� 13���� ũ�ٸ�  
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
    //4. point+1 , point -1 �ΰ��� ������ �Լ�ȣ��
    dfs(n, name, answer + 1, point + 1, a);
    dfs(n, name, answer + 1, point - 1, a);
}
int solution(string name) {
    int answer = 0;
    // 65-90 JAZ = 70 65 90
    // ��= +1 �Ʒ� -1 65���ϸ� 90 90�̻��̸� 65
    // �¿�- ĭ�̵� 
    // �Է¹��� ���ڿ� �����ŭ �迭 
    // A,A.... �����ŭ 
    string n;
    int name_size = name.size();
    n.resize(name_size, 'A');
    answer = dfs(n, name, 0, 0, 65);

    return answer;
}