#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8

typedef struct {
    int x;
    int y;
} Node;

int maze[MAX][MAX] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 1},
    {0, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0}
};

int vis[MAX][MAX];
int px[MAX][MAX], py[MAX][MAX];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// ����������������Թ�
void bfs(int x, int y)
{
    if (x == MAX - 1 && y == MAX - 1)
    {
        Node ans[MAX * MAX];
        int size = 0;

        while (x != 0 || y != 0)
        {
            ans[size].x = x;  // ����·���ϵ� x ����
            ans[size].y = y;  // ����·���ϵ� y ����
            size++;

            int tx = px[x][y], ty = py[x][y];
            x = tx, y = ty;  // ���ݵ���һ���ڵ�
        }
        printf("�Թ���һ��·��:\n");
        printf("(0,0)");
        for (int i = size - 1; i >= 0; i--)
        {
            printf("->(%d,%d)", ans[i].x, ans[i].y);  // �������·���ϵ�����
        }
        printf("\n");

        return;
    }

    vis[x][y] = 1;  // ��ǵ�ǰ�ڵ�Ϊ�ѷ���

    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];  // �������ڽڵ������

        if (xx >= 0 && xx < MAX && yy >= 0 && yy < MAX && !vis[xx][yy] && maze[xx][yy] != 1)
        {
            px[xx][yy] = x;  // ��¼·���ϵ� x ����
            py[xx][yy] = y;  // ��¼·���ϵ� y ����
            bfs(xx, yy);  // �ݹ�������ڽڵ�
        }
    }
}


// ��ӡ����·�����Թ�
void PrintMaze()
{
    printf("�Թ�·�����ӻ�:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (maze[i][j] == 1) {
                printf("* ");  // ǽ��
            } else if (i == 0 && j == 0) {
                printf("S ");  // ���
            } else if (i == MAX - 1 && j == MAX - 1) {
                printf("E ");  // �յ�
            } else {
                int isPath = 0;  // �Ƿ�Ϊ·���ϵĵ�
                int x = MAX - 1, y = MAX - 1;
                while (x != 0 || y != 0) {
                    if (px[x][y] == i && py[x][y] == j) {
                        printf("P ");  // ·���ϵĵ�
                        isPath = 1;
                        break;
                    }
                    int tempX = px[x][y];  // ������һ���ڵ�� x ����
                    int tempY = py[x][y];  // ������һ���ڵ�� y ����
                    x = tempX;  // ���µ�ǰ�ڵ�� x ����Ϊ��һ���ڵ�� x ����
                    y = tempY;  // ���µ�ǰ�ڵ�� y ����Ϊ��һ���ڵ�� y ����
                }
                if (!isPath) {
                    printf("0 ");  // ����·��
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    printf("�Թ�:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    memset(vis, 0, sizeof(vis));
    memset(px, -1, sizeof(px));
    memset(py, -1, sizeof(py));

    bfs(0, 0);
    printf("\n");

    PrintMaze();

    return 0;
}

