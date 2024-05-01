#include<stdio.h>
#include<string.h>

#define MAX 100

char a[MAX],b[MAX];	//存储字符串 
char maxstr[MAX][MAX];	//二维数组存储最长公共子序列（可能长度相同但序列不同） 
char LCS[MAX];	//存储当前所查询的公共子序列 
int len_a,len_b,maxlen=0,maxstrCount=0;	//两个字符串长度；最长公共子序列长度；最长公共子序列的个数 

void MAXLEN(int pos_a,int pos_b,int len,char LCS[MAX]) {
	if(pos_a>=len_a || pos_b>=len_b) {	//超出数组长度 
		if(len>maxlen) {	//若目前字符串长度大于已知最长字符串，则进行记录更新 
			maxlen=len;
			maxstrCount=0;
			LCS[len + 1] = '\0'; //在结尾添加空字符
			strcpy(maxstr[maxstrCount],LCS);	//将目前字符串存入用于存储最长字符串的数组中 
			maxstrCount++;
		}
		else if(len==maxlen) {	//若目前字符串长度与已知最长字符串长度相同，则将此次寻找的子序列存入 
			LCS[len + 1] = '\0'; //在结尾添加空字符
			strcpy(maxstr[maxstrCount],LCS);
			maxstrCount++;
		}
		return;
	}
	for(int i=pos_b;i<len_b;i++) {	//a序列字符与b序列字符进行比对 
		if(a[pos_a] == b[i]) {	//字符相等则存入当前公共子序列数组 
			LCS[len]=a[pos_a];
			MAXLEN(pos_a+1,i+1,len+1,LCS);	//递归寻找公共字符 
		}
	}
	MAXLEN(pos_a+1,pos_b,len,LCS);	//a序列索引位置后移继续寻找公共字符 
}


int main() {

	printf("请输入第一个序列:");
	scanf("%s",a);
	printf("请输入第二个序列:");
	scanf("%s",b);
	len_a = strlen(a);
	len_b = strlen(b);
	
	MAXLEN(0,0,0,LCS);
	
	printf("最长公共子序列的长度为:%d\n",maxlen);
	for(int i=0;i<maxstrCount;i++) {
		printf("%s\n",maxstr[i]);
	}

	return 0;
}
