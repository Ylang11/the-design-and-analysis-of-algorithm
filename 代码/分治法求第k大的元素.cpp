#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
//按快速排序算法求数组最大K值
int Swap(int arr[], int left, int right){//将比基准数大的数放前面，将比基准数小的数放后面
	int temp = arr[left];
	while (left < right){
		while (temp >= arr[right] && left < right){
			right--;
		}
		arr[left] = arr[right];
		while (temp <= arr[left] && left < right){
			left++;
		}
		arr[right] = arr[left];
	}
	arr[right] = temp;//基准数放中间
	return right;
}

static int Findklargest(int a[], int left,int right, int k){
	int temp = Swap(a, left, right);//返回的是比基数大的数组的大小
	if (temp >= k)
		return Findklargest(a, left, temp - 1, k);//第k个值在大数数组这边
	else if (temp < k - 1)
		return Findklargest(a, temp + 1, right, k);//第k个数在小数数组这边，还是求第k个数的大小
	else
		return a[temp];
	return -1;
}

int main(){
	int a[] = { 5, 1, 2, 3, 8, 7, 6, 9, 5, 4, 3 };
	int num = sizeof(a) / sizeof(a[0]);
	int k = 0;
	scanf("%d", &k);
	int result = Findklargest(a, 0, num - 1, k);
	printf("%d\n", result);
	system("pause");
	return 0;
}

