//递归求解 n个数的r组合 （给出具体的组合方式，例如: n=8, r=5）

#include<stdio.h>

//n表示总共的数的个数，r表示要选择的数的个数，index表示当前已选择数的个数，A数组用于存储已选择的数 
void Comb(int n,int r,int index,int *A) {
	if(r>n) {
		printf("输入错误!(r不可以大于n)/n"); 	//表示输入错误，因为要选择的数的个数不能大于总共的数的个数 
		return; 
	} 
	
    if (r==0) {	//已选择了完成，可以输出组合方式了。
        for (int i=index-1;i>=0;i--) {	//遍历已选择的数数组A，从索引index-1开始到0，依次打印出选择的数
            printf("%d ",A[i]);
        }
        printf("\n");
    	return; 
    }

    for (int i=n;i>=r;i--) {	//从n开始循环到r，从高往低循环 
        A[index]=i;	//将当前的数i放入数组A的索引为index的位置，表示选择了这个数作为其中一个组合的一部分
        Comb(i-1,r-1,index+1,A);	//递归调用Comb函数，将选择的数个数r减1，将已选择的数个数index加1
	}
}

int main() {
    int n,r;
    printf("请输入n与r的值：");
    scanf("%d%d",&n,&r);
    int A[r];
    Comb(n,r,0,A);	//开始计算n个数的r组合并输出具体的组合方式
    return 0;
}

