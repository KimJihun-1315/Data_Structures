#include <stdio.h>

void Hanoi(int num, char from, char by, char to);
int cnt;

int main(void) {
	Hanoi(20, 'A', 'B', 'C');
	printf("%d",cnt);
	return 0;
}

void Hanoi(int num, char from, char by, char to) {
	cnt++;
	if (num == 1) {
		printf("���� 1�� %c���� %c�� �̵�\n", from, to);
	}
	else {
		Hanoi(num - 1, from, to, by);
		printf("���� %d�� %c���� %c�� �̵�\n", num, from, to);
		Hanoi(num - 1, by, from, to);
	}
}