//分治法求解序列最大最小元素

#include <stdio.h>

void MAXMIN(int left,int right,int a[],int *max,int *min) {
    int lmax,lmin,rmax,rmin,mid;

    if (left==right) {
        *max=*min=a[left];	//序列只有一个元素，最大值和最小值都是它本身 
    } 
	else if (left==right-1) {	//序列有两个元素，通过比较得出序列的最大值与最小值 
        if (a[left]<a[right]) {
            *max=a[right];
            *min=a[left];
        }
		else {
            *max=a[left];
            *min=a[right];
        }
    }
	else {	//序列过长需要进行分解 
        mid=(left+right)/2;
        MAXMIN(left,mid,a,&lmax,&lmin);	//左半部分递归寻找最大最小值 
        MAXMIN(mid+1,right,a,&rmax,&rmin);	//右半部分递归寻找最大最小值 
        if (lmax>rmax) {	//左右两部分最大值进行比较 
            *max=lmax;
        }
		else {
            *max=rmax;
        }
        if (lmin<rmin) {	//左右两部分最小值进行比较 
            *min=lmin;
        }
		else {
            *min=rmin;
        }
    }
}

int main() {
    int n,max,min; 
    printf("请输入序列的长度：");
    scanf("%d",&n);
    int a[n];	//此时n被赋值，可以用于定义数组
    for(int left=0;left<n;left++) {
    	printf("请输入序列的第%d个元素：",left+1);
        scanf("%d",&a[left]);
    }
    MAXMIN(0,n-1,a,&max,&min);
    printf("最大值：%d\n",max);
    printf("最小值：%d\n",min);
    return 0;
}

