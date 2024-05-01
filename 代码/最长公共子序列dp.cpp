//����������е�һ��dp�㷨 

#include <stdio.h>
#include <string.h>

int c[100][100];
char a[100],b[100],str1[100],str2[100];
 
int max(int a,int b) {
    return (a > b) ? a : b;		//��Ŀ����Ƚ���������С 
}

//m,n�ֱ�Ϊa,b���� 
void LCS_LEN(int m, int n) {		//��ʼ��c[i][j],����forѭ�����Ƚ�a[i]��b[j] 
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            }	//��������Ϊa,b���������Ǵ�0��ʼ�ģ�����Ҫ��ȥ1 
            else if (a[i - 1] == b[j - 1]) {		//����������һ  
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else {		//a[i-1] !=b[j-1]�������ȡ��߻���������ֵ 
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
}

void BUILD_LCS1(int k, int i, int j) {		//k����ǰҪ�����������ַ�λ�á�i������ a �ĵ�ǰ������j������ b �ĵ�ǰ������
    if (i == 0 || j == 0) {		//һ�������Ѿ������꣬��������
        return;
    }
    if (a[i - 1] == b[j - 1]) {		//��ǰ�ַ���ͬ�������ַ���ӵ��������У�Ȼ�������ǰ���ݣ������һ���ַ���
        BUILD_LCS1(k - 1, i - 1, j - 1);
        str1[k] = a[i - 1];
    }
    else if (c[i - 1][j] >= c[i][j - 1]) {		//���򣬱Ƚ� c[i - 1][j] �� c[i][j - 1]��ѡ��ϴ���Ǹ�������л��ݣ��Ա�֤�����е���󻯡�
        BUILD_LCS1(k, i - 1, j);
    }
    else {		//c[i - 1][j] < c[i][j - 1]
        BUILD_LCS1(k, i, j - 1);
    }
}

//���������Ĳ�ͬ�����ڴ���a[i]��b[j]��ͬ������£���c[i-1][j]��c[i][j-1]��ͬʱ����ȡ��ͬ�Ĳ���


void BUILD_LCS2(int k, int i, int j) {		//k����ǰҪ�����������ַ�λ�á�i������ a �ĵ�ǰ������j������ b �ĵ�ǰ������
    if (i == 0 || j == 0) {		//һ�������Ѿ������꣬��������
        return;
    }
    if (a[i - 1] == b[j - 1]) {		//��ǰ�ַ���ͬ�������ַ���ӵ��������У�Ȼ�������ǰ���ݣ������һ���ַ���
        BUILD_LCS2(k - 1, i - 1, j - 1);
        str2[k] = a[i - 1]; 
    }
    else if (c[i - 1][j] > c[i][j - 1]) {		//���򣬱Ƚ� c[i - 1][j] �� c[i][j - 1]��ѡ��ϴ���Ǹ�������л��ݣ��Ա�֤�����е���󻯡�
        BUILD_LCS2(k, i-1, j);
    }
    else {		//c[i - 1][j] <= c[i][j - 1]
        BUILD_LCS2(k, i, j-1);
    }
}


int main() {
    printf("�����������ַ�����\n");
    printf("a: ");
    scanf("%s", a);
    printf("b: ");
    scanf("%s", b);

    int m = strlen(a);	//����a,b���� 
    int n = strlen(b);

    LCS_LEN(m, n);
    BUILD_LCS1(c[m][n], m, n);
    BUILD_LCS2(c[m][n], m, n);
    
    printf("�����������1: %s\n", str1 + 1);
    printf("�����������2: %s\n", str2 + 1);
    return 0;
}

