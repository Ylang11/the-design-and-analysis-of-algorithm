#include<stdio.h>
#include<string.h>

#define MAX 100

char a[MAX],b[MAX];	//�洢�ַ��� 
char maxstr[MAX][MAX];	//��ά����洢����������У����ܳ�����ͬ�����в�ͬ�� 
char LCS[MAX];	//�洢��ǰ����ѯ�Ĺ��������� 
int len_a,len_b,maxlen=0,maxstrCount=0;	//�����ַ������ȣ�����������г��ȣ�����������еĸ��� 

void MAXLEN(int pos_a,int pos_b,int len,char LCS[MAX]) {
	if(pos_a>=len_a || pos_b>=len_b) {	//�������鳤�� 
		if(len>maxlen) {	//��Ŀǰ�ַ������ȴ�����֪��ַ���������м�¼���� 
			maxlen=len;
			maxstrCount=0;
			LCS[len + 1] = '\0'; //�ڽ�β��ӿ��ַ�
			strcpy(maxstr[maxstrCount],LCS);	//��Ŀǰ�ַ����������ڴ洢��ַ����������� 
			maxstrCount++;
		}
		else if(len==maxlen) {	//��Ŀǰ�ַ�����������֪��ַ���������ͬ���򽫴˴�Ѱ�ҵ������д��� 
			LCS[len + 1] = '\0'; //�ڽ�β��ӿ��ַ�
			strcpy(maxstr[maxstrCount],LCS);
			maxstrCount++;
		}
		return;
	}
	for(int i=pos_b;i<len_b;i++) {	//a�����ַ���b�����ַ����бȶ� 
		if(a[pos_a] == b[i]) {	//�ַ��������뵱ǰ�������������� 
			LCS[len]=a[pos_a];
			MAXLEN(pos_a+1,i+1,len+1,LCS);	//�ݹ�Ѱ�ҹ����ַ� 
		}
	}
	MAXLEN(pos_a+1,pos_b,len,LCS);	//a��������λ�ú��Ƽ���Ѱ�ҹ����ַ� 
}


int main() {

	printf("�������һ������:");
	scanf("%s",a);
	printf("������ڶ�������:");
	scanf("%s",b);
	len_a = strlen(a);
	len_b = strlen(b);
	
	MAXLEN(0,0,0,LCS);
	
	printf("����������еĳ���Ϊ:%d\n",maxlen);
	for(int i=0;i<maxstrCount;i++) {
		printf("%s\n",maxstr[i]);
	}

	return 0;
}
