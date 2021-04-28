#pragma warning(disable:4996)
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT_CNT 200

//�л��� ������ ������ ����ü
typedef struct studentInfo {
    int num;
    char name[10];
    char address[100];
    char phone[12];
    int koScore;
    int dsScore;
}studentInfo;

//����ü�� ����������ڸ� ������ ������ ����
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

//���α׷��� ����������� �޴�(�Լ�)�� �̵�.
int main() {
    while(1) menu();
}

//�޴��� �̵��Ǿ����� ��°� �����Է��� ���� ���̵�.
void menu() {
    int tapNum;
    char exit_scan;
    printf("\n  ====== �л� ���� ���α׷� =======\n");
    printf("  +-------------------------------+\n");
    printf("  |                               |\n");
    printf("  |   1.�л�����     2. �л��˻�  |\n");
    printf("  |   3.�������     4.  ����     |\n");
    printf("  |                               |\n");
    printf("  +-------------------------------+\n");
    printf("  ���̵� : ");
    scanf("%d", &tapNum);   //�ǳѹ��� �Է¹���
    system("cls");          //�ý���ȭ�� Ŭ����

    switch (tapNum)
    {
    case 1: //1�Է½� �л����� ������ �̵�
        printf("\n  ====== �л� ���� ���α׷� =======\n");
        printf("  +--------- �л� ���� -----------+\n");
        printf("  |                               |\n");
        printf("  |   1. �л��߰�   2. ����ó��   |\n");
        printf("  |                               |\n");
        printf("  +-------------------------------+\n");
        printf("  ���̵� : ");
        tapNum = 0;
        scanf("%d", &tapNum);
        system("cls");

        if (tapNum == 1) {          //1�Է½� �л��� �߰��ϴ� ������ �̵�
            init();
            return;
        }
        else if (tapNum == 2) {     //2�Է½� ����ó�� ������ �̵�
            del();
            return;
        }
        else {                      //�̿��� ��� ERRORó��
            printf("\n   ERROR : ������ �ϳ��� �����Ͻÿ�. \n");
            return;
        }
        break;
    case 2:         //2�Է½� �˻�â���� �̵�
        search();
        break;
    case 3:         //3�Է½� ������� â���� �̵�
        topScore();
        break;
    case 4:         //���Ḧ Ȯ����
        printf("\n   �����Ͻðڽ��ϱ�?(Y) : ");
        do {
            scanf("%c", &exit_scan);
        } while (exit_scan == 10);
        if (exit_scan == 'Y' || exit_scan == 'y')   //���� �Է°��� y���
            exit(1);            //exit�� �̿��Ͽ� �ڵ带 ����
        else {
            printf("\n   ���Ḧ �ϽǷ��� Y�� �����ּ���.\n");
            return;
        }
        break;
    default:       //1,2,3,4���� ���ڸ� �Է½� ERROR���
        printf("\n   ERROR : ������ �ϳ��� �����Ͻÿ�. \n");
        return;
    }
    return;
}

void init() {       //�л��� �߰��Ͽ� �ִ� ��
    char scanNum[5];
    char idx;
    printf("\n   ------------�л� �߰�------------\n");
    printf("     �й�   : ");

    // ����� �� �й��� �ƴҶ� ����ó��
    scanf("%s", scanNum);
    idx = studentNumberParsing(scanNum);
    if (idx == 0)return;


    if (studentsInfo[idx].num != 0) //�����ϴ� ��ȣ�϶�
    {
        printf("\n   ERROR : �̹� �����ϴ� ��ȣ�Դϴ�.\n");
        return;
    }
    if (strcmp(studentsInfo[idx].name, "����") == 0)  //�̸��� �������� ó���� �Ǿ�������
    {
        printf("\n   ERROR : ���� ó���� ��ȣ�Դϴ�.\n");
        return;
    }


    studentsInfo[idx].num = atoi(scanNum);


    printf("     �̸�   : ");
    scanf("%s", studentsInfo[idx].name);

    printf("     �ּ�   : ");
    scanf("%s", studentsInfo[idx].address);

    printf("   ��ȭ��ȣ : ");
    scanf("%s", studentsInfo[idx].phone);

    while (1) { //���������� ����ε� ���� �Էµɶ����� �ݺ�
        printf("   �������� : ");
        scanf("%d", &studentsInfo[idx].koScore);
        if (studentsInfo[idx].koScore > 100 || studentsInfo[idx].koScore < 0)    //100�ʰ� 0�̸��϶� ERROR
        {
            printf("\n   ERROR : �߸��� �Է��Դϴ�. �ٽ��Է��ϼ���.\n");
            continue;
        }
        else {
            break;
        }
    }

    while (1) { //�ڱ������� ����� �� ���� �Էµɶ����� �ݺ�
        printf("   �ڱ����� : ");
        scanf("%d", &studentsInfo[idx].dsScore);
        if (studentsInfo[idx].dsScore > 100 || studentsInfo[idx].dsScore < 0)   //100�ʰ� 0�̸��϶� ERROR
        {
            printf("\n   ERROR : �߸��� �Է��Դϴ�. �ٽ��Է��ϼ���.\n");
            continue;
        }
        else {
            break;
        }
    }

    if (studentsInfo[hiDSScore].dsScore < studentsInfo[idx].dsScore)
    {
        hiDSScore = idx;
    }
    if (studentsInfo[hiKoScore].koScore < studentsInfo[idx].koScore)
    {
        hiKoScore = idx;
    }
    system("cls");
    return;
}

void del() {        //�л��� ����ó���� ����ϴ� �Լ�
    char scanNum[5];    //�Է°��� �����ϴ� 5ũ���� �迭
    char scanchar;
    char idx;
    printf("   ----------- �л� ���� -----------\n");
    printf("     �й�   : ");

    scanf("%s", scanNum);
    idx = studentNumberParsing(scanNum);
    if (idx == 0)return;          //��ȯ���� 0�϶�(�Ľ̰������� ERROR�� �߻�) ����

    if (strcmp(studentsInfo[idx].name, "����") == 0)  //�̹� ����ó���� �Ǿ��°��� �Ǵ�
    {
        printf("\n   ERROR : �̹� ����ó���� �л��Դϴ�.\n");
        return;
    }
    if (studentsInfo[idx].num == 0)                   //�����ϴ� �л������� �Ǵ�
    {
        printf("\n   ERROR : �������� �ʴ� �л��Դϴ�.\n");
        return;
    }

    studentsInfo[idx].num = atoi(scanNum);

    printf("\n   %d %s �� ����ó�� �˴ϴ�.\n",studentsInfo[idx].num, studentsInfo[idx].name);   //����ó������ ���

    //����ó���Ǳ���� �л��� ���������� ���� ��� NULL���� �ְ� �̸� ��ġ�� '����'�̶�� ����
    studentsInfo[idx].name[0] = '\0';
    strcat(studentsInfo[idx].name, "����");
    studentsInfo[idx].address[0] = '\0';
    studentsInfo[idx].dsScore = NULL;
    studentsInfo[idx].koScore = NULL;
    studentsInfo[idx].num = NULL;
    studentsInfo[idx].phone[0] = '\0';

    //������ڸ� �����ϴ� ���α׷��� ���� ���л��� ������ ������ �ȵ��� ó����
    if (hiDSScore == idx)
    {
        SelectTopDSScore(); 
    }
    if (hiKoScore == idx)
    {
        SelectTopKoScore();
    }
    system("cls");
    return;
}

void search()       //�л��˻��� ���� �Լ�
{
    char scanNum[5];    //�Է°��� ������ �迭
    int idx;            //��ȯ���� ������ �迭
    char end_scan;

    printf("\n   ------------�л� ã��------------\n"); 
    printf("  �й� �Է� : ");
    scanf("%s", scanNum);
    idx = studentNumberParsing(scanNum);    
    if (idx == 0) return;


    if (studentsInfo[idx].num == 0)
    {
        printf("\n   ERROR : �������� �ʴ� �л��Դϴ�.\n");
        return;
    }
     printf("\n   ------------�˻� ���------------\n");

    printf("     �й�   : %d\n", studentsInfo[idx].num);

    printf("     �̸�   : %s\n", studentsInfo[idx].name);

    printf("     �ּ�   : %s\n", studentsInfo[idx].address);

    printf("   ��ȭ��ȣ : %s\n", studentsInfo[idx].phone);

    printf("   �������� : %d\n", studentsInfo[idx].koScore);

    printf("   �ڱ����� : %d\n", studentsInfo[idx].dsScore);

    printf("\n   Ȯ�εǾ����ϱ�?(Y) : ");
    do {
        scanf("%c", &end_scan);
    } while (end_scan == 10);
    if (end_scan == 'Y' || end_scan == 'y')   //���� �Է°��� y���
        system("cls");
    else {
        printf("\n   ���Ḧ �ϽǷ��� Y�� �����ּ���.\n");

    }
}

//���� ������ڸ� ����ϴ� �ڵ�
void topScore() {
    if (hiDSScore == 0 || hiKoScore == 0)
    {
        printf("\n   ERROR : ���� ����ڰ� �������� �ʽ��ϴ�.\n\n");
        return;
    }

    printf("\n   +-------- ���� ����� ----------+\n");
    printf("     ���� : %d %s (%d)\n", studentsInfo[hiKoScore].num, studentsInfo[hiKoScore].name, studentsInfo[hiKoScore].koScore);
    printf("     �ڱ� : %d %s (%d)\n", studentsInfo[hiDSScore].num, studentsInfo[hiDSScore].name, studentsInfo[hiDSScore].dsScore);
    system("cls");

}

//�ڱ����� ������ڸ� �Ǵ��ϴ� �ڵ�
void SelectTopDSScore()
{
    int maxDSScore = INT_MIN;
    hiDSScore = 0;
    for (int i = 0; i < STUDENT_CNT; i++)   //�л�����ŭ for���� ������.
    {
        if (studentsInfo[i].num != 0)       //�л��� ������ �ִ°��� �Ǵ��Ͽ�
        {
            if (maxDSScore < studentsInfo[i].dsScore)   //�ִٸ� �ְ�����ڰ����� �л��� ������ ������ �Ǵ�
            {
                maxDSScore = studentsInfo[i].dsScore;   //���� �ְ�������� ���� ����
                hiDSScore = i;
            }
        }
    }
}

//��������������ڸ� �Ǵ��ϴ� �ڵ�(���� �ڵ�� �󼼼����� �����Ƿ� ����)
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


//�Է¹��� ��(scanNum)�� �� �ڸ����γ����� ������ �����ϰ� ���������� ��ȯ
int studentNumberParsing(char* scanNum)
{
    int returnNum = 0;
     if (strlen(scanNum) != 4)  //4�ڸ����� �ƴҶ� ERROR
    {
        printf("\n   ERROR : 4���ڷ� ���ڸ� �����Ͽ� �Է��ϼ���.\n");
        return 0;
    }
    if (scanNum[0] > '3' || scanNum[0] == '0') {    //�г� ������ ������� ERROR
        printf("\n   ERROR : �г�(1 ~ 3������ ���� �Է��ϼ���.)\n"); 
        return 0;
    }
    if (scanNum[1] > '3' || scanNum[1] == '0') {    //�й� ������ ������� ERROR
        printf("\n   ERROR : �й�(1 ~ 3������ ���� �Է��ϼ���.)\n");
        return 0;
    }
    if ((scanNum[2]=='0' && scanNum[3]=='0') || (scanNum[2] >= '2' && scanNum[3] > '0')) {  //�й� ������ ������� ERROR
        printf("\n   ERROR : �й�(01 ~ 20������ ���� �Է��ϼ���.)\n");
        return 0;
    }

    //�迭�� ������ ���� ���� �г⿡ 60�� ���ϰ� �ݿ� 20�� ���ϰ� ��ȣ�� �̿��Ͽ� �л������� 0���� 180���� ����
    returnNum += (scanNum[0] - '0' - 1) * 60;
    returnNum += (scanNum[1] - '0' - 1) * 20;
    returnNum += (scanNum[2] - '0') * 10;
    returnNum += (scanNum[3] - '0') * 1;
    return returnNum;
}