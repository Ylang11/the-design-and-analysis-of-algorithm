//��ŵ�����⣨�ֱ���� 4-10�׺�ŵ�����⣬ͳ�Ƹ�����Ҫ�����ƶ��������������Ƚϣ�
//	1																														1
//	2				2									1				1									2				2
//	3				3		1       3	2	1		3	2				2	3		1	2	3		1		3				3
//	A	B	C		A	B	C		A	B	C		A	B	C		A	B	C		A	B	C		A	B	C		A	B	C

#include<stdio.h>

//m��ʾ��ǰ��Ҫ�ƶ���Բ�̲�����countָ������ͳ���ƶ�������from��to��temp�ֱ��ʾ��ʼ���ӡ�Ŀ�����Ӻ���ʱ����
void Move(int m,int *count,char from,char to,char temp) {
    if (m == 1) {	//��������1ʱ��ֱ�Ӵ���ʼ���ƶ���Ŀ����
        (*count)++;
        printf("��%d���ƶ���%c�̵�����%d�ᵽ%c��\n", *count,from,m,to); 
    } else {
        Move(m-1,count,from,temp,to);	//��������1ʱ���Ƚ�����ʼ���ƶ�����ʱ�� 
        (*count)++;	//�ƶ�������1 
        printf("��%d���ƶ���%c�̵�����%d�ᵽ%c��\n", *count,from,m,to);
        Move(m-1,count,temp,to,from);	//�ٴ���ʱ���ƶ���Ŀ���� 
    }
}

int main() {
    int m,count = 0;
    char from,to,temp;
    from = 'A';	//��ʼ�� 
    to = 'C';
    temp = 'B';
    printf("�����뺺ŵ���Ĳ�����");
    scanf("%d", &m);
    Move(m,&count,from,to,temp);
    printf("�����ƶ�������%d\n", count);
    return 0;
}

