//���� ���� ���α׷�
//�л� ��ȣ ������ �迭�� ����
//scanf(), scanf_s

//[���� �Է� �κ�]
//�л������� �Է����ּ���.
//�й�:
//�̸�:
//�ּ�:
//��ȭ��ȣ:
//���� ���� :
//�ڷᱸ�� ���� :
//
//[�˻� �κ�]
//�й��� �Է��ϼ���. 1101�� �Է��ϸ�
//�л�����(�й�, �̸�, �ּ� ��)�� ���´�.
//���� �ش� �л��� ������ ���ٰ� ����Ѵ�.
//
//[���� ���]
//���� ������ �л��� ���� ��� �л��� �����ϴ� ����� �߰��Ѵ�.
//�ش� �й��� ��� �� ĭ���� ��µǰ� �ϵ� �̸����� �����С��̶�� ���ڰ� ������ �Ѵ�.
//
//[1�� ��� ���]
//���� ������ ���� ���� �л��� ����ϴ� ��� �߰��ϱ�
//�ڷᱸ�� ������ ���� ���� �л��� ����ϴ� ��� �߰��ϱ�
//
//[�������]
//�߸��� �Է��� �߻��� ��� �Ǵ��Ͽ� �����޽��� �����ֱ�.
//��) �й��� �Է��ϼ���. 11129
//4�ڸ��� �Է��ϼ���.������ ������ ó���ϱ�


#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT_CNT 200

typedef struct studentInfo {
    int num;
    char name[10];
    char address[100];
    char phone[12];
    int koScore;
    int dsScore;
}studentInfo;


studentInfo studentsInfo[STUDENT_CNT];
int hiDSScore = 0;
int hiKoScore = 0;

int studentNumberParsing(char* scanNum);
void init();
void del();
void search();
void topScore();
void menu();
void SelectTopDSScore();
void SelectTopKoScore();

int main() {
    while(1) menu();
}

void menu() {
    int tapNum;
    char exit_scan;
    printf("\n");
    printf("  ====== �л� ���� ���α׷� =======\n");
    printf("  +-------------------------------+\n");
    printf("  |                               |\n");
    printf("  |   1.�л�����     2. �л��˻�  |\n");
    printf("  |   3.�������     4.  ����     |\n");
    printf("  |                               |\n");
    printf("  +-------------------------------+\n");
    printf("  ���̵� : ");
    scanf("%d", &tapNum);

    printf("\n\n\n");

    switch (tapNum)
    {
    case 1:
        printf("  ====== �л� ���� ���α׷� =======\n");
        printf("  +--------- �л� ���� -----------+\n");
        printf("  |                               |\n");
        printf("  |   1. �л��߰�   2. �л�����   |\n");
        printf("  |                               |\n");
        printf("  +-------------------------------|\n");
        printf("  ���̵� : ");
        tapNum = 0;
        scanf("%d", &tapNum);
        printf("\n\n");

        if (tapNum == 1) {
            init();
            return;
        }
        else if (tapNum == 2) {
            del();
            return;
        }
        else {
            printf("������ �ϳ��� �����Ͻÿ�. \n");
            return;
        }
        break;
    case 2:
        search();
        break;
    case 3:
        topScore();
        break;
    case 4:
        printf("�����Ͻðڽ��ϱ�?(Y) : ");
        do {
            scanf("%c", &exit_scan);
        } while (exit_scan == 10);
        if (exit_scan == 'Y')
            exit(1);
        else {
            printf("���Ḧ �ϽǷ��� Y�� �����ּ���.\n");
            return;
        }
        break;
    default:
        printf("������ �ϳ��� �����Ͻÿ�. \n");
        return;
    }
    return;
}

void init() {
    char scanNum[5];
    char idx;
    printf("  ------------�л� �߰�------------\n");
    printf("    �й�   : ");

    // ����� �� �й��� �ƴҶ� ����ó��
    scanf("%s", scanNum);
    idx = studentNumberParsing(scanNum);
    if (idx == 0)return;


    if (studentsInfo[idx].num != 0)
    {
        printf("�̹� ���� ����������\n");
        return;
    }
    if (strcmp(studentsInfo[idx].name, "����") == 0)
    {
        printf("���� ���� ����������\n");
        return;
    }


    studentsInfo[idx].num = atoi(scanNum);


    printf("    �̸�   : ");
    scanf("%s", studentsInfo[idx].name);

    printf("    �ּ�   : ");
    scanf("%s", studentsInfo[idx].address);

    printf("  ��ȭ��ȣ : ");
    scanf("%s", studentsInfo[idx].phone);

    while (1) {
        printf("  �������� : ");
        scanf("%d", &studentsInfo[idx].koScore);
        if (studentsInfo[idx].koScore > 100 || studentsInfo[idx].koScore < 0)
        {
            printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ�\n");
            continue;
        }
        else {
            break;
        }
    }

    while (1) {
        printf("  �ڱ����� : ");
        scanf("%d", &studentsInfo[idx].dsScore);
        if (studentsInfo[idx].dsScore > 100 || studentsInfo[idx].dsScore < 0)
        {
            printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ�\n");
            continue;
        }
        else {
            break;
        }
    }
    printf("\n\n\n\n\n");

    if (studentsInfo[hiDSScore].dsScore < studentsInfo[idx].dsScore)
    {
        hiDSScore = idx;
    }
    if (studentsInfo[hiKoScore].koScore < studentsInfo[idx].koScore)
    {
        hiKoScore = idx;
    }

    return;
}

void del() {
    char scanNum[5];
    char scanchar;
    char idx;
    printf("  ----------- �л� ���� -----------\n");
    printf("    �й�   : ");

    scanf("%s", scanNum);
    idx = studentNumberParsing(scanNum);
    if (idx == 0)return;

    if (strcmp(studentsInfo[idx].name, "����") == 0)
    {
        printf("�̹� ���� ���� ����������\n");
        return;
    }
    if (studentsInfo[idx].num == 0)
    {
        printf("���������� ���� ����������\n");
        return;
    }

    studentsInfo[idx].num = atoi(scanNum);

    printf("  %d %s �� ����ó�� �˴ϴ�.\n",studentsInfo[idx].num, studentsInfo[idx].name);

    studentsInfo[idx].name[0] = '\0';
    strcat(studentsInfo[idx].name, "����");
    studentsInfo[idx].dsScore = NULL;
    studentsInfo[idx].koScore = NULL;
    studentsInfo[idx].num = NULL;
    studentsInfo[idx].phone[0] = '\0';
    printf("\n\n\n\n\n");

    if (hiDSScore == idx)
    {
        SelectTopDSScore();
    }
    if (hiKoScore == idx)
    {
        SelectTopKoScore();
    }

    return;
}

void search()
{
    char scanNum[5];
    int idx;
    printf("  ------------�л� ã��------------\n");
    printf("  �й� �Է� : ");
    scanf("%s", scanNum);
    printf("\n\n");
    idx = studentNumberParsing(scanNum);
    if (idx == 0) return;


    if (studentsInfo[idx].num != 0)
    {
        printf("�������� �ʴ� �л��� ��ã�ƿ�\n");
        return;
    }

    printf("  ------------�˻� ���------------\n");

    printf("    �й�   : %d\n", studentsInfo[idx].num);

    printf("    �̸�   : %s\n", studentsInfo[idx].name);

    printf("    �ּ�   : %s\n", studentsInfo[idx].address);

    printf("  ��ȭ��ȣ : %s\n", studentsInfo[idx].phone);

    printf("  �������� : %d\n", studentsInfo[idx].koScore);

    printf("  �ڱ����� : %d\n", studentsInfo[idx].dsScore);
}

void topScore() {
    if (hiDSScore == 0 || hiKoScore == 0)
    {
        printf("���� ����ڰ� �������� �ʽ��ϴ�.\n\n");
        return;
    }

    printf("  +-------- ���� ����� ----------+\n");
    printf("    ���� : %d %s (%d)\n", studentsInfo[hiKoScore].num, studentsInfo[hiKoScore].name, studentsInfo[hiKoScore].koScore);
    printf("    �ڱ� : %d %s (%d)\n", studentsInfo[hiDSScore].num, studentsInfo[hiDSScore].name, studentsInfo[hiDSScore].dsScore);
    printf("\n\n\n\n\n");
}

void SelectTopDSScore()
{
    int maxDSScore = INT_MIN;
    hiDSScore = 0;
    for (int i = 0; i < STUDENT_CNT; i++)
    {
        if (studentsInfo[i].num != 0)
        {
            if (maxDSScore < studentsInfo[i].dsScore)
            {
                maxDSScore = studentsInfo[i].dsScore;
                hiDSScore = i;
            }
        }
    }
}

void SelectTopKoScore()
{
    int maxKoScore = INT_MIN;
    hiKoScore = 0;
    for (int i = 0; i < STUDENT_CNT; i++)
    {
        if (studentsInfo[i].num != 0)
        {
            if (maxKoScore < studentsInfo[i].koScore)
            {
                maxKoScore = studentsInfo[i].koScore;
                hiKoScore = i;
            }
        }
    }
}



int studentNumberParsing(char* scanNum)
{
    int returnNum = 0;
             if (strlen(scanNum) != 4)
    {
        printf("TIP! : �˰��̳���? �й��� 4�����Դϴ�.\n");
        return 0;
    }
    if (scanNum[0] > '3' || scanNum[0] < '1') {
        printf("TIP! : �˰��̳���? �г��� 1�г���� 3�г������ �ִ�ϴ�.\n"); 
        return 0;
    }
    if (scanNum[1] > '3' || scanNum[1] < '1') {
        printf("TIP! : �˰��̳���? ���� 1�ݺ��� 3�ݱ����� �ִ�ϴ�.\n");
        return 0;
    }
    if (scanNum[2] > '2' || scanNum[2] < '0' || scanNum[3] > '9' || scanNum[3] < '0' || (scanNum[2] == '2' && scanNum[3] != '0')) {
        printf("TIP! : �˰��̳���? ��ȣ�� 1������ 20�������� �ִ�ϴ�.\n");
        return 0;
    }


    returnNum += (scanNum[0] - '0' - 1) * 60;
    returnNum += (scanNum[1] - '0' - 1) * 20;
    returnNum += (scanNum[2] - '0') * 10;
    returnNum += (scanNum[3] - '0') * 1;
    return returnNum;
}