#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int a[MAX_SIZE][MAX_SIZE];
int b[MAX_SIZE][MAX_SIZE];
int color1 = 0; // ��ɫ���
int color2 = 0;
int n;

void Tromino1(int row, int col, int x, int y, int size)
{
    if (size == 1)
        return;
    int s = size / 2;
    ++color1;

    // �������޵�λ�õݹ����Tromino����,˳ʱ�뷽�� 
    if (x <= (row+s-1) && y <= (col+s-1))	//�жϵ� (x, y) �Ƿ������޶���
    {
        Tromino1(row, col, x, y, s);
    }
    else
    {
        a[row+s-1][col+s-1] = color1;	//�������޶������½�Ϊ��ǰ��ɫ���
        Tromino1(row, col, row+s-1, col+s-1, s);	//������Χ��С�������޶�
    }

    if (x <= (row+s-1) && y >= (col+s))	//�жϵ� (x, y) �Ƿ�������һ��
    {
        Tromino1(row, col+s, x, y, s);
    }
    else
    {
        a[row+s-1][col+s] = color1;	//��������һ�����½�Ϊ��ǰ��ɫ���
        Tromino1(row, col+s, row+s-1, col+s, s);	//������Χ��С��������һ
    }

    if (x >= (row+s) && y >= (col+s))	//�жϵ� (x, y) �Ƿ�����������
    {
        Tromino1(row+s, col+s, x, y, s);
    }
    else
    {
        a[row+s][col+s] = color1;	//���������ĵ����½�Ϊ��ǰ��ɫ���
        Tromino1(row+s, col+s, row+s, col+s, s);	//������Χ��С����������
    }

    if (x >= (row+s) && y <= (col+s-1))	//�жϵ� (x, y) �Ƿ�����������
    {
        Tromino1(row+s, col, x, y, s);
    }
    else
    {
        a[row+s][col+s-1] = color1;	//���������������½�Ϊ��ǰ��ɫ���
        Tromino1(row+s, col, row+s, col+s-1, s);	//������Χ��С����������
    }

}

void Tromino2(int row, int col, int x, int y, int size)
{
    if (size == 1)
        return;
    int s = size / 2;
    ++color2;

    // �������޵�λ�õݹ����Tromino����,��ʱ�뷽�� 
    
    if (x <= (row+s-1) && y >= (col+s))	//�жϵ� (x, y) �Ƿ�������һ��
    {
        Tromino2(row, col+s, x, y, s);
    }
    else
    {
        b[row+s-1][col+s] = color2;	//��������һ�����½�Ϊ��ǰ��ɫ���
        Tromino2(row, col+s, row+s-1, col+s, s);	//������Χ��С��������һ
    }

    if (x <= (row+s-1) && y <= (col+s-1))	//�жϵ� (x, y) �Ƿ������޶���
    {
        Tromino2(row, col, x, y, s);
    }
    else
    {
        b[row+s-1][col+s-1] = color2;	//�������޶������½�Ϊ��ǰ��ɫ���
        Tromino2(row, col, row+s-1, col+s-1, s);	//������Χ��С�������޶�
    }

    if (x >= (row+s) && y <= (col+s-1))	//�жϵ� (x, y) �Ƿ�����������
    {
        Tromino2(row+s, col, x, y, s);
    }
    else
    {
        b[row+s][col+s-1] = color2;	//���������������½�Ϊ��ǰ��ɫ���
        Tromino2(row+s, col, row+s, col+s-1, s);	//������Χ��С����������
    }

    if (x >= (row+s) && y >= (col+s))	//�жϵ� (x, y) �Ƿ�����������
    {
        Tromino2(row+s, col+s, x, y, s);
    }
    else
    {
        b[row+s][col+s] = color2;	//���������ĵ����½�Ϊ��ǰ��ɫ���
        Tromino2(row+s, col+s, row+s, col+s, s);	//������Χ��С����������
    }

}

int main()
{
    int x, y;
    printf("���������̹��");
	scanf("%d",&n);
	printf("�������ȱλ�ã�");
	scanf("%d %d",&x,&y);

    Tromino1(1, 1, x, y, n);
    Tromino2(1, 1, x, y, n);

    // �����һ�ֲ��� 
    printf("\n��һ�ֲ��ԣ�\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }

    // ����ڶ��ֲ���
    printf("\n�ڶ��ֲ��ԣ�\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%3d", b[i][j]);
        printf("\n");
    }

    return 0;
}

