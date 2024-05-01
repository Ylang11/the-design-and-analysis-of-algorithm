//最长公共子序列第一问dp算法 

#include <stdio.h>
#include <string.h>

int c[100][100];
char a[100],b[100],str1[100],str2[100];
 
int max(int a,int b) {
    return (a > b) ? a : b;		//三目运算比较两个数大小 
}

//m,n分别为a,b长度 
void LCS_LEN(int m, int n) {		//初始化c[i][j],两重for循环，比较a[i]、b[j] 
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            }	//这里是因为a,b数组索引是从0开始的，所以要减去1 
            else if (a[i - 1] == b[j - 1]) {		//相等则计数加一  
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else {		//a[i-1] !=b[j-1]，不相等取左边或上面的最大值 
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
}

void BUILD_LCS1(int k, int i, int j) {		//k：当前要填充的子序列字符位置。i：序列 a 的当前索引。j：序列 b 的当前索引。
    if (i == 0 || j == 0) {		//一个序列已经遍历完，函数返回
        return;
    }
    if (a[i - 1] == b[j - 1]) {		//当前字符相同，将该字符添加到子序列中，然后继续向前回溯，填充下一个字符。
        BUILD_LCS1(k - 1, i - 1, j - 1);
        str1[k] = a[i - 1];
    }
    else if (c[i - 1][j] >= c[i][j - 1]) {		//否则，比较 c[i - 1][j] 和 c[i][j - 1]，选择较大的那个方向进行回溯，以保证子序列的最大化。
        BUILD_LCS1(k, i - 1, j);
    }
    else {		//c[i - 1][j] < c[i][j - 1]
        BUILD_LCS1(k, i, j - 1);
    }
}

//两个函数的不同点在于处理a[i]与b[j]不同的情况下，当c[i-1][j]与c[i][j-1]不同时所采取不同的操作


void BUILD_LCS2(int k, int i, int j) {		//k：当前要填充的子序列字符位置。i：序列 a 的当前索引。j：序列 b 的当前索引。
    if (i == 0 || j == 0) {		//一个序列已经遍历完，函数返回
        return;
    }
    if (a[i - 1] == b[j - 1]) {		//当前字符相同，将该字符添加到子序列中，然后继续向前回溯，填充下一个字符。
        BUILD_LCS2(k - 1, i - 1, j - 1);
        str2[k] = a[i - 1]; 
    }
    else if (c[i - 1][j] > c[i][j - 1]) {		//否则，比较 c[i - 1][j] 和 c[i][j - 1]，选择较大的那个方向进行回溯，以保证子序列的最大化。
        BUILD_LCS2(k, i-1, j);
    }
    else {		//c[i - 1][j] <= c[i][j - 1]
        BUILD_LCS2(k, i, j-1);
    }
}


int main() {
    printf("请输入两个字符序列\n");
    printf("a: ");
    scanf("%s", a);
    printf("b: ");
    scanf("%s", b);

    int m = strlen(a);	//计算a,b长度 
    int n = strlen(b);

    LCS_LEN(m, n);
    BUILD_LCS1(c[m][n], m, n);
    BUILD_LCS2(c[m][n], m, n);
    
    printf("最长公共子序列1: %s\n", str1 + 1);
    printf("最长公共子序列2: %s\n", str2 + 1);
    return 0;
}

