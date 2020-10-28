#include <stdio.h>
#pragma warning (disable:4996)

int facto(int num);

int main(void) {
	int num;
	scanf("%d", &num);
	printf("%d! = %d", num, facto(num));
}

int facto(int num) {
	if (num == 0)
		return 1;
	else
		return num * facto(num - 1);
}