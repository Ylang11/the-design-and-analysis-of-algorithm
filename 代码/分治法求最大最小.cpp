//���η�������������СԪ��

#include <stdio.h>

void MAXMIN(int left,int right,int a[],int *max,int *min) {
    int lmax,lmin,rmax,rmin,mid;

    if (left==right) {
        *max=*min=a[left];	//����ֻ��һ��Ԫ�أ����ֵ����Сֵ���������� 
    } 
	else if (left==right-1) {	//����������Ԫ�أ�ͨ���Ƚϵó����е����ֵ����Сֵ 
        if (a[left]<a[right]) {
            *max=a[right];
            *min=a[left];
        }
		else {
            *max=a[left];
            *min=a[right];
        }
    }
	else {	//���й�����Ҫ���зֽ� 
        mid=(left+right)/2;
        MAXMIN(left,mid,a,&lmax,&lmin);	//��벿�ֵݹ�Ѱ�������Сֵ 
        MAXMIN(mid+1,right,a,&rmax,&rmin);	//�Ұ벿�ֵݹ�Ѱ�������Сֵ 
        if (lmax>rmax) {	//�������������ֵ���бȽ� 
            *max=lmax;
        }
		else {
            *max=rmax;
        }
        if (lmin<rmin) {	//������������Сֵ���бȽ� 
            *min=lmin;
        }
		else {
            *min=rmin;
        }
    }
}

int main() {
    int n,max,min; 
    printf("���������еĳ��ȣ�");
    scanf("%d",&n);
    int a[n];	//��ʱn����ֵ���������ڶ�������
    for(int left=0;left<n;left++) {
    	printf("���������еĵ�%d��Ԫ�أ�",left+1);
        scanf("%d",&a[left]);
    }
    MAXMIN(0,n-1,a,&max,&min);
    printf("���ֵ��%d\n",max);
    printf("��Сֵ��%d\n",min);
    return 0;
}

