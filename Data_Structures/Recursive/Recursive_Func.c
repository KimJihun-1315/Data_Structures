#include <stdio.h>
#pragma warning (disable:4996)

void Recursive(int num);

int main(void) {
	Recursive(3);
	return 0;
}

void Recursive(int num) {
	if (num <= 0)
		return;
	printf("Recursive Call! %d\n", num);
	Recursive(num - 1);
}