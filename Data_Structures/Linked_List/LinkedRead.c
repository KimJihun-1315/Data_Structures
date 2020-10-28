#include <stdio.h>
#include <stdlib.h>

typedef struct _node Node;	//Node라는 이름을 사용
typedef struct _node {
	int data;
	Node* next;
};

int main() {
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;
	Node* newNode = NULL;
	int  num;
	
	//입력받는 과정`
	printf("자연수를 입력하세요.(단 0입력시 종료)\n\n");
	while (1) {
		printf("입력 : ");
		scanf("%d", &num);
		if (num < 1)break;
		
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = num;
		newNode->next= NULL;
		
		if (head == NULL)              
			head = newNode;
		else
			tail->next = newNode;
		tail = newNode;
	}

	//출력하는 과정
	printf("\n연결리스트 데이터 출력\n");
	if (head == NULL) {
		printf("데이터가 없습니다.\n");
	}
	else {
		cur = head;
		printf("%d ", cur->data);
		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n"); 

	//메모리 해제과정
	if (head == NULL) {
		return 0;
	}
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d을(를) 삭제 합니다.\n", head->data);
		free(delNode);

		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}
