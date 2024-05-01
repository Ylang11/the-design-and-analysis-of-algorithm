#include <stdio.h>

void PrintPartition(int partition[], int length) {
    for (int i = 0; i < length - 1; i++) {
        printf("%d+", partition[i]);  // ��ӡ�����е�һ��Ԫ��
    }
    printf("%d", partition[length - 1]);  // ��ӡ�����е����һ��Ԫ��
    printf("\n");
}
 
int DivideInteger(int n, int m, int partition[], int index, int *count) {
    if (n == 0) {  // ���n����0����ʾ�Ѿ������һ�ֻ���
        PrintPartition(partition, index);  // ��ӡ����
        (*count)++;  // ������Ŀ��1
        return 1;  // ����1��ʾ�ҵ���һ�ֻ���
    }
    if (m == 0)
        return 0;  // ���m����0����ʾ�޷��������֣�����0��ʾû���ҵ�����
    
    int sum = 0;
    for (int i = m; i >= 1; i--) {  // ��m��ʼ�ݼ����ҳ����п��ܵĻ��ַ�ʽ
        if (i <= n) {  // ���iС�ڵ���n����ʾ�����������Ϊ���ֵ�һ��Ԫ��
            partition[index] = i;  // ��i��ӵ�����������
            sum += DivideInteger(n - i, i, partition, index + 1, count);  // �ݹ���û��ֺ���
        }
    }
    return sum;  // �������л��ֵ�����
}

int main() {
    int n, count = 0;
    printf("������һ��������");
    if (scanf("%d", &n) != 1) {
        printf("�������\n");
        return 1;
    }
    printf("���ֽ��Ϊ��\n");
    
    int partition[n];  // ����һ�����������滮�ֽ��
    DivideInteger(n, n, partition, 0, &count);  // ���û��ֺ���
    
    printf("\n������Ŀ����Ϊ��%d\n", count);  // ��ӡ���ֵ�����
    
    return 0;
}

