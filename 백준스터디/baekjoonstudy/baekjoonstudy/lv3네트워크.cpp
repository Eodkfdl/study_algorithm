#include <string>
#include <vector>

using namespace std;
//������ ����� ����Ա�� ���� ����
bool dfs(int n, vector<vector<int>>& c) {
    if (!c[n][n])return false;//�湮�Ѱ��̶�� return
    c[n][n] = 0;//�湮�����������̶�� �湮ó��
    //������ġ�ǳ�忡�� �����鿡���Ͽ� dfs
    for (int i = 0; i < c.size(); i++)if (c[n][i])dfs(i, c);



    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    //�̾����ִ� ��Ʈ��ũ�� ���� ��ȯ���־���Ѵ�.
    //dfs
    //�� �������� ����ؼ� �̾����� ��� �湮 ó�� �� ��Ʈ��ũ���� ����
    for (int i = 0; i < n; i++) {
        //computers[i][j]=0 �湮�Ѱ� or ��������ʴ°�
        //computers[i][j]=1 �湮�Ѱ� or ����Ȱ�
        if (dfs(i, computers))answer++;

    }

    return answer;
}