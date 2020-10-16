#pragma once
#include <stdio.h>
#include "dot.h"
#define TRUE 1
#define FALSE 0
#define LIST_LEN 100 //�迭�� ���� 100
//typedef int LData; // LData --> int
typedef Point* LData; // LData --> Point*
typedef struct __Arrlist {
	LData  arr[LIST_LEN];//int arr[100];
	int numOfData;//�����Ͱ��� ����
	int curPosition;//��ġ
}ArrayList;
typedef ArrayList List;
void ListInit(List* plist);//����Ʈ �ʱ�ȭ
void LInsert(List* plist, LData data);
int LCount(List* plist);

LData LRemove(List* plist);
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);