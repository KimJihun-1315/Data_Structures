//Binary_Serch(���� Ž��)
#include <stdio.h>

int BSearch(int ar[], int len, int target);
int printLinear(int idx);

int main(void) {
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
	printLinear(idx);

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	printLinear(idx);
}

int BSearch(int ar[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;
	int count = 0;

	while (first <= last)
	{
		count++;
		mid = (first + last) / 2;

		if (target == ar[mid])
		{
			printf("����Ƚ�� : %d\n", count);
			return mid;
		}
		else
		{
			if (target < ar[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	printf("����Ƚ�� : %d\n", count);
	return -1;
}


int printLinear(int idx) {
	if (idx == -1)
		printf("Ž������ \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);
}