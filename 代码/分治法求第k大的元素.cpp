#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
//�����������㷨���������Kֵ
int Swap(int arr[], int left, int right){//���Ȼ�׼���������ǰ�棬���Ȼ�׼��С�����ź���
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
	arr[right] = temp;//��׼�����м�
	return right;
}

static int Findklargest(int a[], int left,int right, int k){
	int temp = Swap(a, left, right);//���ص��ǱȻ����������Ĵ�С
	if (temp >= k)
		return Findklargest(a, left, temp - 1, k);//��k��ֵ�ڴ����������
	else if (temp < k - 1)
		return Findklargest(a, temp + 1, right, k);//��k������С��������ߣ��������k�����Ĵ�С
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

