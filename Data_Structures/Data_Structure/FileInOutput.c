#include <stdio.h>
#pragma warning (disable:4996)



int main() {
	FILE* fp1 = fopen("file.txt", "r");
	FILE* fp2 = fopen("answer.txt", "w");
	int n1, n2;
	fscanf(fp1, "%s %d", &n1, &n2);
	fprintf(fp2, "%d %d", n1, n2);
	fclose(fp1);
	fclose(fp2);
	return 0;
}