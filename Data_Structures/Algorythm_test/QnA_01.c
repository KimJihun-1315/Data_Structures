//저항계산기
//
//black   0  1
//brown   1  10
//red     2  100
//orange  3  1000
//yellow  4  10000
//green   5  100000
//blue    6  1000000
//violet  7  10000000
//grey    8  100000000
//white   9  1000000000
//
//색을 입력 받았을때 저항의 값을 출력하시오

#include <stdio.h>
#pragma warning(disable: 4996)

int main() {
	char color[11] = { "black", "brown", "red","orange", "yellow", "green", "blue", "violet" "grey", "white" };
	char input_text;
	int value[3];
	long long r = 0;

	for (int i = 0; i < 3; i++)
	{
		scanf("%s", input_text);
		for (int j = 0; j < 10; j++)
		{
			if (color[j] == input_text) value[i] = j;
		}
	}

	r = value[0] * 10 + value[1];
	for (int i = 0; i < value[2]; ++i) r *= 10;

	printf("%lld", r)  ;

}