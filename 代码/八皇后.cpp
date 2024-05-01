#include <stdio.h>

#define BOARD_SIZE 4

int count = 0;                       // 保存解法数量的变量
int chess[BOARD_SIZE] = {0};         // 一维数组表示棋盘，数组索引表示行号，数组元素表示列号

int Check(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (chess[i] == col || chess[i] - col == i - row || chess[i] - col == row - i)
            return 0;               // 检查当前位置是否与之前的皇后位置冲突，返回0表示冲突，返回1表示安全
    }
    return 1;
}

void PrintBoard() {
    printf("第%d种解法:\n", count + 1);     // 打印当前解法编号
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (chess[row] == col)
                printf("Q ");               // 打印皇后的位置
            else
                printf("* ");               // 打印空白位置
        }
        printf("\n");
    }
    printf("\n");
}

void SolveEightQueens(int row) {
    if (row >= BOARD_SIZE) {
        PrintBoard();                       // 当遍历完所有行后，打印出当前棋盘的解法
        count++;                            // 解法数量加1
        return;
    }

    for (int col = 0; col < BOARD_SIZE; col++) {
        if (Check(row, col)) {
            chess[row] = col;                // 在当前行的合法位置放置皇后
            SolveEightQueens(row + 1);       // 递归调用放置下一行的皇后
        }
    }
}

int main() {
    SolveEightQueens(0);                     // 从第0行开始放置皇后
    printf("总共有%d种解法\n\n", count);      // 打印解法的总数量
    return 0;
}

