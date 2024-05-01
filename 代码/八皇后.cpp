#include <stdio.h>

#define BOARD_SIZE 4

int count = 0;                       // ����ⷨ�����ı���
int chess[BOARD_SIZE] = {0};         // һά�����ʾ���̣�����������ʾ�кţ�����Ԫ�ر�ʾ�к�

int Check(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (chess[i] == col || chess[i] - col == i - row || chess[i] - col == row - i)
            return 0;               // ��鵱ǰλ���Ƿ���֮ǰ�Ļʺ�λ�ó�ͻ������0��ʾ��ͻ������1��ʾ��ȫ
    }
    return 1;
}

void PrintBoard() {
    printf("��%d�ֽⷨ:\n", count + 1);     // ��ӡ��ǰ�ⷨ���
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (chess[row] == col)
                printf("Q ");               // ��ӡ�ʺ��λ��
            else
                printf("* ");               // ��ӡ�հ�λ��
        }
        printf("\n");
    }
    printf("\n");
}

void SolveEightQueens(int row) {
    if (row >= BOARD_SIZE) {
        PrintBoard();                       // �������������к󣬴�ӡ����ǰ���̵Ľⷨ
        count++;                            // �ⷨ������1
        return;
    }

    for (int col = 0; col < BOARD_SIZE; col++) {
        if (Check(row, col)) {
            chess[row] = col;                // �ڵ�ǰ�еĺϷ�λ�÷��ûʺ�
            SolveEightQueens(row + 1);       // �ݹ���÷�����һ�еĻʺ�
        }
    }
}

int main() {
    SolveEightQueens(0);                     // �ӵ�0�п�ʼ���ûʺ�
    printf("�ܹ���%d�ֽⷨ\n\n", count);      // ��ӡ�ⷨ��������
    return 0;
}

