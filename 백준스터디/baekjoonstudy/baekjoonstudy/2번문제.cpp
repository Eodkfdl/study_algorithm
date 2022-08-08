#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(vector<vector<int>> field, int farmSize) {
    int answer = 0;
    int min_count = 999;
    int cur_count = 0;
    bool exist_mushroom = false;
    //������� 0 ������ 1 �� 2
    //�ش翵���� �������� ������ �� �˻�
    //�ش翵���� ���� ������ �� ������ ���� ġ�����ϴ� ������ ������ ��ȯ
    //��������� �������� ���Եȴٸ� return -1;
    //string���� farmsize������ �����Ŀ� ó���ϴ� ��ĵ� ����

   //i , j for�� �������� �����ϴ� for�� 
   //k , e for�� ������������ farmsize ���θ� ���� �ش������
   //���ǿ� ���� ó��
    for (int i = 0; i <= field.size() - farmSize; i++) {
        for (int j = 0; j <= field[0].size() - farmSize; j++) {
            cur_count = 0;
            for (int k = i; k < i+ farmSize; k++) {
                for (int e = j; e <j+ farmSize; e++) {
                    if (field[k][e] == 2) {
                        exist_mushroom = true;
                        break;
                    }
                    if (field[k][e] == 1)cur_count++;
                }
                if (exist_mushroom)break;
            }

            if (exist_mushroom) {
                exist_mushroom = false;
                continue;
            }
            min_count = min(min_count, cur_count);

        }
    }

    return min_count;
}
int main() {
    vector<vector<int>> maps;
    int n=0, m=0 , a=0;
    cin >> n >> m >> a;
    vector<int>v;
    //maps Ʋ�����
    for (int i = 0; i < n; i++) {
        maps.push_back(v);
        for (int j = 0; j < m; j++) {
            maps[i].push_back(0);
        }
    }
    //������ �ٴ����� �Է¹ޱ�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &maps[i][j]);
        }
    }

	cout<<solution(maps,a);
}