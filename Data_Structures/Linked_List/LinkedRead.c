#include <stdio.h>
#include <stdlib.h>

typedef struct _node Node;	//Node��� �̸��� ���
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
	
	//�Է¹޴� ����`
	printf("�ڿ����� �Է��ϼ���.(�� 0�Է½� ����)\n\n");
	while (1) {
		printf("�Է� : ");
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

	//����ϴ� ����
	printf("\n���Ḯ��Ʈ ������ ���\n");
	if (head == NULL) {
		printf("�����Ͱ� �����ϴ�.\n");
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

	//�޸� ��������
	if (head == NULL) {
		return 0;
	}
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d��(��) ���� �մϴ�.\n", head->data);
		free(delNode);

		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d��(��) �����մϴ�.\n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}
