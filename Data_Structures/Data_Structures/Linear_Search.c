//Linear_Serch(¼øÂ÷ Å½»ö)
#include <stdio.h>

int LSerch(int ar[], int len, int target) {
	int i;
	for (i=0;  i<len; i++)
	{
		if (ar[i] == target)
			return i;
	}
	return -1;
}

int main(void) {
	int arr[] = { 3,5,2,4,9 };
	int idx;

	idx = LSerch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("Å½»ö½ÇÆĞ \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d \n", idx);

	idx = LSerch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("Å½»ö½ÇÆĞ \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d \n", idx);
}