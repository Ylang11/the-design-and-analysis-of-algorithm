//测试用例：m=3 n=7
//利润表 q ：
//	0.11 0.13 0.15 0.21 0.24 0.30 0.35
//  0.12 0.16 0.21 0.23 0.25 0.24 0.34
//  0.08 0.12 0.20 0.24 0.26 0.30 0.35

#include <stdio.h>
#define MAX_SIZE 100

//m 项目数	n 总投资数	q利润表（由用户进行输入） 
void AllocateResources(int m, int n, double q[MAX_SIZE][MAX_SIZE]) {
    double f[MAX_SIZE];                  // 存储最大利润
    int a[MAX_SIZE][MAX_SIZE];          // 存储投资方案	第i个项目在总投资额为j时，当前项目所分配的投资额度 
    double temp[MAX_SIZE];               // 临时存储最大利润
    int gain[MAX_SIZE];                  // 存储每个项目的投资额
    int rest;                       // 剩余的总投资额

    for (int j = 0; j <= n; j++) {
        f[j] = q[1][j];             // 初始化第一行的最大利润，只考虑第一个项目时的最大利润
        a[1][j] = j;                // 初始化第一行的投资方案，只考虑第一个项目时的投资方案 
    }

    for (int k = 2; k <= m; k++) {  // 动态规划求解最优解，k为项目编号（从第二个项目开始） 
        for (int j = 0; j <= n; j++) {
            temp[j] = q[k][j];       // 初始化临时最大利润，确保在后续的计算中，考虑到当前项目的利润 
            a[k][j] = 0;             // 初始化投资方案，表示在当前的状态下还没有确定具体的投资方案 
        }
        for (int j = 0; j <= n; j++) {	//遍历可能的总投资额j	j为总投资额，i为当前项目投资额 
            for (int i = 0; i <= j; i++) {	//遍历当前总投资额j下的所有投资额组合i
                if (f[j - i] + q[k][i] > temp[j]) {    // 如果当前方案的利润更大，则更新临时最大利润和投资方案
                    temp[j] = f[j - i] + q[k][i];	//q[k][i]为当前项目利润	f[j-i]为上一项目利润 
                    a[k][j] = i;	//保存最大投资额 
                }
            }
        }
        for (int j = 0; j <= n; j++) {
            f[j] = temp[j];         // 更新最大利润，把这轮计算的最新项目得出的最大利润加进利润表中 
        }
    }

    rest = n;                       // 初始化剩余总投资额

    for (int i = m; i >= 1; i--) {   // 根据最优解获取投资额和项目编号
        gain[i] = a[i][rest];	//获取投资额记录 
        rest = rest - gain[i];
    }

    printf("项目编号\t投资额\n");     // 输出结果
    for (int i = 1; i <= m; i++) {
        printf("%d\t\t%d\n", i, gain[i]);
    }
    printf("-----------------------\n");
    printf("最大利润\t%.3lf\n", f[n]);
}

int main() {
    int m, n;
    double q[MAX_SIZE][MAX_SIZE];

    printf("请输入项目数 m：");        // 读取项目数和总投资数
    scanf("%d", &m);

    printf("请输入总投资数 n：");
    scanf("%d", &n);

    printf("请输入利润表：\n");        // 读取利润表
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lf", &q[i][j]);
        }
    }

    AllocateResources(m, n, q);      // 调用函数进行资源分配

    return 0;
}

