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

// 广度优先搜索遍历迷宫
void bfs(int x, int y)
{
    if (x == MAX - 1 && y == MAX - 1)
    {
        Node ans[MAX * MAX];
        int size = 0;

        while (x != 0 || y != 0)
        {
            ans[size].x = x;  // 保存路径上的 x 坐标
            ans[size].y = y;  // 保存路径上的 y 坐标
            size++;

            int tx = px[x][y], ty = py[x][y];
            x = tx, y = ty;  // 回溯到上一个节点
        }
        printf("迷宫的一条路径:\n");
        printf("(0,0)");
        for (int i = size - 1; i >= 0; i--)
        {
            printf("->(%d,%d)", ans[i].x, ans[i].y);  // 逆序输出路径上的坐标
        }
        printf("\n");

        return;
    }

    vis[x][y] = 1;  // 标记当前节点为已访问

    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];  // 计算相邻节点的坐标

        if (xx >= 0 && xx < MAX && yy >= 0 && yy < MAX && !vis[xx][yy] && maze[xx][yy] != 1)
        {
            px[xx][yy] = x;  // 记录路径上的 x 坐标
            py[xx][yy] = y;  // 记录路径上的 y 坐标
            bfs(xx, yy);  // 递归访问相邻节点
        }
    }
}


// 打印带有路径的迷宫
void PrintMaze()
{
    printf("迷宫路径可视化:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (maze[i][j] == 1) {
                printf("* ");  // 墙壁
            } else if (i == 0 && j == 0) {
                printf("S ");  // 起点
            } else if (i == MAX - 1 && j == MAX - 1) {
                printf("E ");  // 终点
            } else {
                int isPath = 0;  // 是否为路径上的点
                int x = MAX - 1, y = MAX - 1;
                while (x != 0 || y != 0) {
                    if (px[x][y] == i && py[x][y] == j) {
                        printf("P ");  // 路径上的点
                        isPath = 1;
                        break;
                    }
                    int tempX = px[x][y];  // 保存上一个节点的 x 坐标
                    int tempY = py[x][y];  // 保存上一个节点的 y 坐标
                    x = tempX;  // 更新当前节点的 x 坐标为上一个节点的 x 坐标
                    y = tempY;  // 更新当前节点的 y 坐标为上一个节点的 y 坐标
                }
                if (!isPath) {
                    printf("0 ");  // 可行路径
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    printf("迷宫:\n");
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

