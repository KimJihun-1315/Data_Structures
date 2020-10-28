//버블정렬 : 두 인접한 수끼리 비교하면서 정렬하는 방법
//오름차순 정렬

#include<stdio.h>
#define num 10

int main() {
	int array[num] = { 153, 56, 9, 3, 26, 33, 99, 793, 47, 999 };
	int i, j;
	int temp;

	for (i = 0; i < num; i++) {
		for (j = 0; i < num - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < num; i++) {
		printf("[%d] ", array[i]);
	}
}