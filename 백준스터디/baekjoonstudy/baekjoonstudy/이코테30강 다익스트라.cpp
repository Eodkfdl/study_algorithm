#include <stdio.h>

#define INT_MAX 2147483647 // �ִ� ����
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 7  // ������ ��
#define INF 1000    // ���Ѵ� (������ ���� ���)

int weight[MAX_VERTICES][MAX_VERTICES] = {
  {0,7,INF,INF,3,10,INF},
  {7,0,4,10,2,6,INF},
  {INF,4,0,2,INF,INF,INF},
  {INF,10,2,0,11,9,4},
  {3,2,INF,11,0,INF,5},
  {10,6,INF,9,INF,0,INF},
  {INF,INF,INF,4,5,INF,0}
};

int distance[MAX_VERTICES]; // ���� �������κ����� �ִ� ��� �Ÿ�
int found[MAX_VERTICES];  // �湮�� ���� ǥ��

int choose(int distance[], int n, int found[])
{
    // ���� distance �迭���� ���� ���� ����ġ ���� ��ġ�ϰ� �ִ�
    // �迭�� �ε����� ã�� ��ȯ�ϴ� �Լ�

    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;

    // �ּҰ� min�� ã�� �ݺ����̴�.
    // �湮�� ���� ���� ������ ���� distance�迭�� ������ ���Ѵ�.
    for (i = 0; i < n; i++)
    {
        // �湮�� ���� ���� �����̰� ��������� �ּҰ� min ���� �۴ٸ�
        if (distance[i] < min && found[i] == FALSE)
        {
            // �ּҰ��� �ǹ��ϴ� min ������ �������ش�.
            min = distance[i];

            // �ּҰ��� ������ �ش� ������ �ε����� minpos�� �����Ѵ�.
            minpos = i;
        }
    }
    // distnace �迭���� �ּҰ��� ��ġ�ϰ� �ִ� �ε����� ��ȯ�Ѵ�.
    return minpos;
}

void shortest_path(int start, int n)// start �������� n ���������� �ִ� ��θ� ã�� �˰���
{
    int i, u, w;

    /* �ʱ�ȭ �۾� */
    for (i = 0; i < n; i++)
    {
        // ���� ���� start�� �������� ���� ���� ����ġ��
        // distance �迭�� �ʱ�ȭ �Ѵ�.
        distance[i] = weight[start][i];

        // ���� ������ �������Ƿ� �湮 ǥ���� ������ �ϴ�
        // found �迭�� FALSE�� �ʱ�ȭ �Ѵ�.
        found[i] = FALSE;
    }
    // ���� ������ ���������� �湮���θ� TRUE�� �����Ѵ�.
    found[start] = TRUE;
    distance[start] = TRUE;

    for (i = 0; i < n - 1; i++) // ������ ���� ���� ���� ���������Ƿ� ���⼭�� �ϳ��� �� ��ŭ�� �ݺ��Ѵ�.
    {
        // �ּҰ��� �ִ� �ε����� ������ u�� �����Ѵ�.
        u = choose(distance, n, found);

        // ���� distance �迭���� ���� ���� ���� ��ġ�� �ε����� u�̹Ƿ�
        // u�� ������ ������ �Ѵ�. �����԰� ���ÿ� TRUE�� ���� ���ָ� �湮 ǥ�ø� �Ѵ�.
        found[u] = TRUE;

        // �ּ� ����ġ�� �ִ� ������ ���� S�� �߰��� �� �츮�� ������ �� �ִ� ������ �ִٸ�
        // �� ������ �������ش�. ���Ѵ� (�� PG������ 1000)���� ���� �Ÿ��� ���ŵǴ� ������
        // �� �Ÿ����� ª�� �Ÿ��� ���ŵǴ� ������ �Ʒ��� ������ �״�� �۵��Ѵ�.
        for (w = 0; w < n; w++)
        {
            // ���� ���õǾ� ���� ���� �����̰�
            if (found[w] == FALSE)
            {
                // ���� �� ���������� �Ÿ� (distance[u]) + ���� w������ �Ÿ���
                // ������ w���������� �Ÿ����� �����ٸ� �� ������ �������ش�.
                if (distance[u] + weight[u][w] < distance[w])
                {
                    distance[w] = distance[u] + weight[u][w];
                }
            }
        }
    }

}

void main()
{
    shortest_path(0, MAX_VERTICES);
}


