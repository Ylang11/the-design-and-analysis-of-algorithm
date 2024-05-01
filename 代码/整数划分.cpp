#include <stdio.h>

void PrintPartition(int partition[], int length) {
    for (int i = 0; i < length - 1; i++) {
        printf("%d+", partition[i]);  // 打印划分中的一个元素
    }
    printf("%d", partition[length - 1]);  // 打印划分中的最后一个元素
    printf("\n");
}
 
int DivideInteger(int n, int m, int partition[], int index, int *count) {
    if (n == 0) {  // 如果n等于0，表示已经完成了一种划分
        PrintPartition(partition, index);  // 打印划分
        (*count)++;  // 划分数目加1
        return 1;  // 返回1表示找到了一种划分
    }
    if (m == 0)
        return 0;  // 如果m等于0，表示无法继续划分，返回0表示没有找到划分
    
    int sum = 0;
    for (int i = m; i >= 1; i--) {  // 从m开始递减，找出所有可能的划分方式
        if (i <= n) {  // 如果i小于等于n，表示这个数可以作为划分的一个元素
            partition[index] = i;  // 将i添加到划分数组中
            sum += DivideInteger(n - i, i, partition, index + 1, count);  // 递归调用划分函数
        }
    }
    return sum;  // 返回所有划分的总数
}

int main() {
    int n, count = 0;
    printf("请输入一个整数：");
    if (scanf("%d", &n) != 1) {
        printf("输入错误！\n");
        return 1;
    }
    printf("划分结果为：\n");
    
    int partition[n];  // 定义一个数组来保存划分结果
    DivideInteger(n, n, partition, 0, &count);  // 调用划分函数
    
    printf("\n划分数目最终为：%d\n", count);  // 打印划分的总数
    
    return 0;
}

