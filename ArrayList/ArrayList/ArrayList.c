#include "ArrayList.h"
void ListInit(List* plist) {
	plist->numOfData = 0;//처음엔 0개
	plist->curPosition = -1;//위치는 -1
}
void LInsert(List* plist, LData data) {
	if (plist->numOfData > 100) {
		puts("저장 공간이 없음. 에러\n");
		return;
	}
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}
int LCount(List* plist) {
	return plist->numOfData;
}
LData LRemove(List* plist) {
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];
	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];
	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LFirst(List* plist, LData* pdata) {
	if (plist->numOfData == 0)
		return FALSE;
	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}