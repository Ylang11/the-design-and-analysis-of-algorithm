//汉诺塔问题（分别计算 4-10阶汉诺塔问题，统计各自需要多少移动步数，并作出比较）
//	1																														1
//	2				2									1				1									2				2
//	3				3		1       3	2	1		3	2				2	3		1	2	3		1		3				3
//	A	B	C		A	B	C		A	B	C		A	B	C		A	B	C		A	B	C		A	B	C		A	B	C

#include<stdio.h>

//m表示当前需要移动的圆盘层数，count指针用于统计移动步数，from、to和temp分别表示起始柱子、目标柱子和临时柱子
void Move(int m,int *count,char from,char to,char temp) {
    if (m == 1) {	//层数等于1时，直接从起始盘移动到目标盘
        (*count)++;
        printf("第%d次移动：%c盘的数字%d搬到%c盘\n", *count,from,m,to); 
    } else {
        Move(m-1,count,from,temp,to);	//层数大于1时，先将从起始盘移动到临时盘 
        (*count)++;	//移动步数加1 
        printf("第%d次移动：%c盘的数字%d搬到%c盘\n", *count,from,m,to);
        Move(m-1,count,temp,to,from);	//再从临时盘移动到目标盘 
    }
}

int main() {
    int m,count = 0;
    char from,to,temp;
    from = 'A';	//初始化 
    to = 'C';
    temp = 'B';
    printf("请输入汉诺塔的层数：");
    scanf("%d", &m);
    Move(m,&count,from,to,temp);
    printf("最终移动步数：%d\n", count);
    return 0;
}

