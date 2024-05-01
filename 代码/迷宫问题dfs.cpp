#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8

typedef struct {
    int x;
    int y;
} Coordinate;

int dx[] = {0, 1, 0, -1};  // �������飬��ʾx���ϵ��ƶ�����
int dy[] = {1, 0, -1, 0};  // �������飬��ʾy���ϵ��ƶ�����

int maze[MAX][MAX] = {
    {0, 0, 0, 0, 0, 0, 0, 0},  // �Թ�����
    {0, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 1},
    {0, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0}
};

int visited[MAX][MAX];  // ��¼�Թ��е�λ���Ƿ񱻷��ʹ�
int px[MAX][MAX], py[MAX][MAX];  // ��¼ÿ��λ�õ�ǰһ��λ�õ�����

// ʹ�������������Ѱ���Թ��е�·��
void DFS(int x, int y)
{
    if (x == MAX - 1 && y == MAX - 1) {
        return;
    }

    visited[x][y] = 1;  // ��ǵ�ǰλ��Ϊ�ѷ���

    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (new_x >= 0 && new_x < MAX && new_y >= 0 && new_y < MAX && !visited[new_x][new_y] && maze[new_x][new_y] != 1) {
            px[new_x][new_y] = x;  // ��¼��ǰλ�õ�ǰһ��λ�õ�x����
            py[new_x][new_y] = y;  // ��¼��ǰλ�õ�ǰһ��λ�õ�y����
            DFS(new_x, new_y);  // ���������������
        }
    }
}

// ��ӡ����·�����Թ�
void PrintMaze()
{
    printf("�Թ���һ��·��:\n");
    int path[MAX * MAX][2];  // �洢·��������
    int pathLength = 0;  // ·���ĳ���
    int x = MAX - 1;  // �յ��x����
    int y = MAX - 1;  // �յ��y����

    // ���յ���ݵ���㣬��·�����������path������
    while (x != 0 || y != 0) {
        path[pathLength][0] = x;
        path[pathLength][1] = y;
        pathLength++;
        int tempX = px[x][y];  // ��һ��λ�õ�x����
        int tempY = py[x][y];  // ��һ��λ�õ�y����
        x = tempX;  // ���µ�ǰλ�õ�x����
        y = tempY;  // ���µ�ǰλ�õ�y����
    }

    printf("(0, 0) ");
    // �����ӡ·�������꣬������㵽�յ��·��
    for (int i = pathLength - 1; i >= 0; i--) {
        printf("->(%d, %d) ", path[i][0], path[i][1]);
    }
    printf("\n");
    printf("\n");

    printf("�Թ�·�����ӻ�:\n");
    // ��ӡ�Թ���ǽ����"*"��ʾ�������"S"��ʾ���յ���"E"��ʾ��·����"P"��ʾ������·����"0"��ʾ
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (maze[i][j] == 1) {
                printf("* ");  // ǽ��
            } else if (i == 0 && j == 0) {
                printf("S ");  // ���
            } else if (i == MAX - 1 && j == MAX - 1) {
                printf("E ");  // �յ�
            } else {
                int isPath = 0;
                // �жϵ�ǰλ���Ƿ�Ϊ·���ϵĵ�
                for (int k = 0; k < pathLength; k++) {
                    if (path[k][0] == i && path[k][1] == j) {
                        printf("P ");  // ·��
                        isPath = 1;
                        break;
                    }
                }
                if (!isPath) {
                    printf("0 ");  // ����·��
                }
            }
        }
        printf("\n");
    }
}



int main()
{
	    printf("�Թ�:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
	
    memset(visited, 0, sizeof(visited));  // ��ʼ��visited����Ϊ0
    DFS(0, 0);  // ����㿪ʼ���������������
    
    PrintMaze();  // ��ӡ����·�����Թ�

    return 0;
}

