//�������� : �� ������ ������ ���ϸ鼭 �����ϴ� ���
//�������� ����

#include<stdio.h>
#define num 5

int main() {
	int array[num] = { 567, 12, 766, 2, 34 };
	int i, j;
	int temp;
	int min;

	for (i = 0; i < num-1; i++) {
		min = i;
		for (j = i+1; j < num-1; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
		}
	}

	for (i = 0; i < num; i++) {
		printf("[%d] ", array[i]);
	}
}