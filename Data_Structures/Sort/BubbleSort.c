//버블정렬 : 두 인접한 수끼리 비교하면서 정렬하는 방법
//오름차순 정렬

#include<stdio.h>
#define num 5

int main() {
	int array[num] = { 567, 12, 766, 2, 34 };
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