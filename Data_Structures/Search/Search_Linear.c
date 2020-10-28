//Linear_Serch(���� Ž��)
#include <stdio.h>
#pragma warning (disable:4996)

int LSerch(int ar[], int len, int target);
int printLinear(int idx);

int main(void) {
	int arr[] = { 3,5,2,4,9 };
	int idx;

	idx = LSerch(arr, sizeof(arr) / sizeof(int), 4);
	printLinear(idx);

	idx = LSerch(arr, sizeof(arr) / sizeof(int), 7);
	printLinear(idx);

	return 0;
}

int LSerch(int ar[], int len, int target) {
	int i;
	for (i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return i;
	}
	return -1;
}

int printLinear(int idx) {
	if (idx == -1)
		printf("Ž������ \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);
}