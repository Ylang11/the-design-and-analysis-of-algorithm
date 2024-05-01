#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8

typedef struct {
    int x;
    int y;
} Coordinate;

int dx[] = {0, 1, 0, -1};  // 方向数组，表示x轴上的移动方向
int dy[] = {1, 0, -1, 0};  // 方向数组，表示y轴上的移动方向

int maze[MAX][MAX] = {
    {0, 0, 0, 0, 0, 0, 0, 0},  // 迷宫数组
    {0, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 1},
    {0, 1, 0, 0, 1, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0}
};

int visited[MAX][MAX];  // 记录迷宫中的位置是否被访问过
int px[MAX][MAX], py[MAX][MAX];  // 记录每个位置的前一个位置的坐标

// 使用深度优先搜索寻找迷宫中的路径
void DFS(int x, int y)
{
    if (x == MAX - 1 && y == MAX - 1) {
        return;
    }

    visited[x][y] = 1;  // 标记当前位置为已访问

    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (new_x >= 0 && new_x < MAX && new_y >= 0 && new_y < MAX && !visited[new_x][new_y] && maze[new_x][new_y] != 1) {
            px[new_x][new_y] = x;  // 记录当前位置的前一个位置的x坐标
            py[new_x][new_y] = y;  // 记录当前位置的前一个位置的y坐标
            DFS(new_x, new_y);  // 继续深度优先搜索
        }
    }
}

// 打印带有路径的迷宫
void PrintMaze()
{
    printf("迷宫的一条路径:\n");
    int path[MAX * MAX][2];  // 存储路径的坐标
    int pathLength = 0;  // 路径的长度
    int x = MAX - 1;  // 终点的x坐标
    int y = MAX - 1;  // 终点的y坐标

    // 从终点回溯到起点，将路径的坐标存入path数组中
    while (x != 0 || y != 0) {
        path[pathLength][0] = x;
        path[pathLength][1] = y;
        pathLength++;
        int tempX = px[x][y];  // 上一个位置的x坐标
        int tempY = py[x][y];  // 上一个位置的y坐标
        x = tempX;  // 更新当前位置的x坐标
        y = tempY;  // 更新当前位置的y坐标
    }

    printf("(0, 0) ");
    // 倒序打印路径的坐标，即从起点到终点的路径
    for (int i = pathLength - 1; i >= 0; i--) {
        printf("->(%d, %d) ", path[i][0], path[i][1]);
    }
    printf("\n");
    printf("\n");

    printf("迷宫路径可视化:\n");
    // 打印迷宫，墙壁用"*"表示，起点用"S"表示，终点用"E"表示，路径用"P"表示，可行路径用"0"表示
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (maze[i][j] == 1) {
                printf("* ");  // 墙壁
            } else if (i == 0 && j == 0) {
                printf("S ");  // 起点
            } else if (i == MAX - 1 && j == MAX - 1) {
                printf("E ");  // 终点
            } else {
                int isPath = 0;
                // 判断当前位置是否为路径上的点
                for (int k = 0; k < pathLength; k++) {
                    if (path[k][0] == i && path[k][1] == j) {
                        printf("P ");  // 路径
                        isPath = 1;
                        break;
                    }
                }
                if (!isPath) {
                    printf("0 ");  // 可行路径
                }
            }
        }
        printf("\n");
    }
}



int main()
{
	    printf("迷宫:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
	
    memset(visited, 0, sizeof(visited));  // 初始化visited数组为0
    DFS(0, 0);  // 从起点开始进行深度优先搜索
    
    PrintMaze();  // 打印带有路径的迷宫

    return 0;
}

