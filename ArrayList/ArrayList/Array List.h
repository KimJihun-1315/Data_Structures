#pragma once
#include <stdio.h>
#include "dot.h"
#define TRUE 1
#define FALSE 0
#define LIST_LEN 100 //배열의 길이 100
//typedef int LData; // LData --> int
typedef Point* LData; // LData --> Point*
typedef struct __Arrlist {
	LData  arr[LIST_LEN];//int arr[100];
	int numOfData;//데이터개수 저장
	int curPosition;//위치
}ArrayList;
typedef ArrayList List;
void ListInit(List* plist);//리스트 초기화
void LInsert(List* plist, LData data);
int LCount(List* plist);

LData LRemove(List* plist);
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);