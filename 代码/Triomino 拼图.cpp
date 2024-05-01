#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int a[MAX_SIZE][MAX_SIZE];
int b[MAX_SIZE][MAX_SIZE];
int color1 = 0; // 颜色编号
int color2 = 0;
int n;

void Tromino1(int row, int col, int x, int y, int size)
{
    if (size == 1)
        return;
    int s = size / 2;
    ++color1;

    // 根据象限的位置递归调用Tromino函数,顺时针方向 
    if (x <= (row+s-1) && y <= (col+s-1))	//判断点 (x, y) 是否在象限二内
    {
        Tromino1(row, col, x, y, s);
    }
    else
    {
        a[row+s-1][col+s-1] = color1;	//设置象限二的右下角为当前颜色编号
        Tromino1(row, col, row+s-1, col+s-1, s);	//将处理范围缩小到了象限二
    }

    if (x <= (row+s-1) && y >= (col+s))	//判断点 (x, y) 是否在象限一内
    {
        Tromino1(row, col+s, x, y, s);
    }
    else
    {
        a[row+s-1][col+s] = color1;	//设置象限一的右下角为当前颜色编号
        Tromino1(row, col+s, row+s-1, col+s, s);	//将处理范围缩小到了象限一
    }

    if (x >= (row+s) && y >= (col+s))	//判断点 (x, y) 是否在象限四内
    {
        Tromino1(row+s, col+s, x, y, s);
    }
    else
    {
        a[row+s][col+s] = color1;	//设置象限四的右下角为当前颜色编号
        Tromino1(row+s, col+s, row+s, col+s, s);	//将处理范围缩小到了象限四
    }

    if (x >= (row+s) && y <= (col+s-1))	//判断点 (x, y) 是否在象限三内
    {
        Tromino1(row+s, col, x, y, s);
    }
    else
    {
        a[row+s][col+s-1] = color1;	//设置象限三的右下角为当前颜色编号
        Tromino1(row+s, col, row+s, col+s-1, s);	//将处理范围缩小到了象限三
    }

}

void Tromino2(int row, int col, int x, int y, int size)
{
    if (size == 1)
        return;
    int s = size / 2;
    ++color2;

    // 根据象限的位置递归调用Tromino函数,逆时针方向 
    
    if (x <= (row+s-1) && y >= (col+s))	//判断点 (x, y) 是否在象限一内
    {
        Tromino2(row, col+s, x, y, s);
    }
    else
    {
        b[row+s-1][col+s] = color2;	//设置象限一的右下角为当前颜色编号
        Tromino2(row, col+s, row+s-1, col+s, s);	//将处理范围缩小到了象限一
    }

    if (x <= (row+s-1) && y <= (col+s-1))	//判断点 (x, y) 是否在象限二内
    {
        Tromino2(row, col, x, y, s);
    }
    else
    {
        b[row+s-1][col+s-1] = color2;	//设置象限二的右下角为当前颜色编号
        Tromino2(row, col, row+s-1, col+s-1, s);	//将处理范围缩小到了象限二
    }

    if (x >= (row+s) && y <= (col+s-1))	//判断点 (x, y) 是否在象限三内
    {
        Tromino2(row+s, col, x, y, s);
    }
    else
    {
        b[row+s][col+s-1] = color2;	//设置象限三的右下角为当前颜色编号
        Tromino2(row+s, col, row+s, col+s-1, s);	//将处理范围缩小到了象限三
    }

    if (x >= (row+s) && y >= (col+s))	//判断点 (x, y) 是否在象限四内
    {
        Tromino2(row+s, col+s, x, y, s);
    }
    else
    {
        b[row+s][col+s] = color2;	//设置象限四的右下角为当前颜色编号
        Tromino2(row+s, col+s, row+s, col+s, s);	//将处理范围缩小到了象限四
    }

}

int main()
{
    int x, y;
    printf("请输入棋盘规格：");
	scanf("%d",&n);
	printf("请输入空缺位置：");
	scanf("%d %d",&x,&y);

    Tromino1(1, 1, x, y, n);
    Tromino2(1, 1, x, y, n);

    // 输出第一种策略 
    printf("\n第一种策略：\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }

    // 输出第二种策略
    printf("\n第二种策略：\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%3d", b[i][j]);
        printf("\n");
    }

    return 0;
}

