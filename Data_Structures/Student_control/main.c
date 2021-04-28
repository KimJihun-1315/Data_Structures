#pragma warning(disable:4996)
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT_CNT 200

//학생의 정보를 저장할 구조체
typedef struct studentInfo {
    int num;
    char name[10];
    char address[100];
    char phone[12];
    int koScore;
    int dsScore;
}studentInfo;

//구조체와 성적고득점자를 저장할 공간을 선언
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

//프로그램을 실행시켰을때 메뉴(함수)로 이동.
int main() {
    while(1) menu();
}

//메뉴로 이동되었을때 출력과 숫자입력을 통해 탭이동.
void menu() {
    int tapNum;
    char exit_scan;
    printf("\n  ====== 학생 관리 프로그램 =======\n");
    printf("  +-------------------------------+\n");
    printf("  |                               |\n");
    printf("  |   1.학생관리     2. 학생검색  |\n");
    printf("  |   3.순위출력     4.  종료     |\n");
    printf("  |                               |\n");
    printf("  +-------------------------------+\n");
    printf("  탭이동 : ");
    scanf("%d", &tapNum);   //탭넘버를 입력받음
    system("cls");          //시스템화면 클리어

    switch (tapNum)
    {
    case 1: //1입력시 학생관리 탭으로 이동
        printf("\n  ====== 학생 관리 프로그램 =======\n");
        printf("  +--------- 학생 관리 -----------+\n");
        printf("  |                               |\n");
        printf("  |   1. 학생추가   2. 전학처리   |\n");
        printf("  |                               |\n");
        printf("  +-------------------------------+\n");
        printf("  탭이동 : ");
        tapNum = 0;
        scanf("%d", &tapNum);
        system("cls");

        if (tapNum == 1) {          //1입력시 학생을 추가하는 탭으로 이동
            init();
            return;
        }
        else if (tapNum == 2) {     //2입력시 전학처리 탭으로 이동
            del();
            return;
        }
        else {                      //이외의 경우 ERROR처리
            printf("\n   ERROR : 보기중 하나를 선택하시오. \n");
            return;
        }
        break;
    case 2:         //2입력시 검색창으로 이동
        search();
        break;
    case 3:         //3입력시 고득점자 창으로 이동
        topScore();
        break;
    case 4:         //종료를 확인함
        printf("\n   종료하시겠습니까?(Y) : ");
        do {
            scanf("%c", &exit_scan);
        } while (exit_scan == 10);
        if (exit_scan == 'Y' || exit_scan == 'y')   //만약 입력값이 y라면
            exit(1);            //exit을 이용하여 코드를 종료
        else {
            printf("\n   종료를 하실려면 Y를 눌러주세요.\n");
            return;
        }
        break;
    default:       //1,2,3,4외의 숫자를 입력시 ERROR출력
        printf("\n   ERROR : 보기중 하나를 선택하시오. \n");
        return;
    }
    return;
}

void init() {       //학생을 추가하여 주는 탭
    char scanNum[5];
    char idx;
    printf("\n   ------------학생 추가------------\n");
    printf("     학번   : ");

    // 제대로 된 학번이 아닐때 예외처리
    scanf("%s", scanNum);
    idx = studentNumberParsing(scanNum);
    if (idx == 0)return;


    if (studentsInfo[idx].num != 0) //존재하는 번호일때
    {
        printf("\n   ERROR : 이미 존재하는 번호입니다.\n");
        return;
    }
    if (strcmp(studentsInfo[idx].name, "전학") == 0)  //이름에 전학으로 처리가 되어있을때
    {
        printf("\n   ERROR : 전학 처리된 번호입니다.\n");
        return;
    }


    studentsInfo[idx].num = atoi(scanNum);


    printf("     이름   : ");
    scanf("%s", studentsInfo[idx].name);

    printf("     주소   : ");
    scanf("%s", studentsInfo[idx].address);

    printf("   전화번호 : ");
    scanf("%s", studentsInfo[idx].phone);

    while (1) { //국어점수가 제대로된 갑이 입력될때까지 반복
        printf("   국어점수 : ");
        scanf("%d", &studentsInfo[idx].koScore);
        if (studentsInfo[idx].koScore > 100 || studentsInfo[idx].koScore < 0)    //100초과 0미만일때 ERROR
        {
            printf("\n   ERROR : 잘못된 입력입니다. 다시입력하세요.\n");
            continue;
        }
        else {
            break;
        }
    }

    while (1) { //자구점수가 제대로 된 값이 입력될때까지 반복
        printf("   자구점수 : ");
        scanf("%d", &studentsInfo[idx].dsScore);
        if (studentsInfo[idx].dsScore > 100 || studentsInfo[idx].dsScore < 0)   //100초과 0미만일때 ERROR
        {
            printf("\n   ERROR : 잘못된 입력입니다. 다시입력하세요.\n");
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

void del() {        //학생의 전학처리를 담당하는 함수
    char scanNum[5];    //입력값을 저장하는 5크기의 배열
    char scanchar;
    char idx;
    printf("   ----------- 학생 전학 -----------\n");
    printf("     학번   : ");

    scanf("%s", scanNum);
    idx = studentNumberParsing(scanNum);
    if (idx == 0)return;          //반환값이 0일때(파싱과정에서 ERROR가 발생) 리턴

    if (strcmp(studentsInfo[idx].name, "전학") == 0)  //이미 전학처리가 되었는가를 판단
    {
        printf("\n   ERROR : 이미 전학처리된 학생입니다.\n");
        return;
    }
    if (studentsInfo[idx].num == 0)                   //존재하는 학생인지를 판단
    {
        printf("\n   ERROR : 존재하지 않는 학생입니다.\n");
        return;
    }

    studentsInfo[idx].num = atoi(scanNum);

    printf("\n   %d %s 이 전학처리 됩니다.\n",studentsInfo[idx].num, studentsInfo[idx].name);   //전학처리됨을 출력

    //전학처리되기로한 학생의 정보에대한 값을 모두 NULL값을 주고 이름 위치에 '전학'이라고 저장
    studentsInfo[idx].name[0] = '\0';
    strcat(studentsInfo[idx].name, "전학");
    studentsInfo[idx].address[0] = '\0';
    studentsInfo[idx].dsScore = NULL;
    studentsInfo[idx].koScore = NULL;
    studentsInfo[idx].num = NULL;
    studentsInfo[idx].phone[0] = '\0';

    //고득점자를 지정하는 프로그램을 돌려 전학생의 점수가 나오지 안도록 처리함
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

void search()       //학생검색을 위한 함수
{
    char scanNum[5];    //입력값을 저장할 배열
    int idx;            //반환값을 저장할 배열
    char end_scan;

    printf("\n   ------------학생 찾기------------\n"); 
    printf("  학번 입력 : ");
    scanf("%s", scanNum);
    idx = studentNumberParsing(scanNum);    
    if (idx == 0) return;


    if (studentsInfo[idx].num == 0)
    {
        printf("\n   ERROR : 존재하지 않는 학생입니다.\n");
        return;
    }
     printf("\n   ------------검색 목록------------\n");

    printf("     학번   : %d\n", studentsInfo[idx].num);

    printf("     이름   : %s\n", studentsInfo[idx].name);

    printf("     주소   : %s\n", studentsInfo[idx].address);

    printf("   전화번호 : %s\n", studentsInfo[idx].phone);

    printf("   국어점수 : %d\n", studentsInfo[idx].koScore);

    printf("   자구점수 : %d\n", studentsInfo[idx].dsScore);

    printf("\n   확인되었습니까?(Y) : ");
    do {
        scanf("%c", &end_scan);
    } while (end_scan == 10);
    if (end_scan == 'Y' || end_scan == 'y')   //만약 입력값이 y라면
        system("cls");
    else {
        printf("\n   종료를 하실려면 Y를 눌러주세요.\n");

    }
}

//성적 고득점자를 출력하는 코드
void topScore() {
    if (hiDSScore == 0 || hiKoScore == 0)
    {
        printf("\n   ERROR : 성적 우수자가 존재하지 않습니다.\n\n");
        return;
    }

    printf("\n   +-------- 성적 우수자 ----------+\n");
    printf("     국어 : %d %s (%d)\n", studentsInfo[hiKoScore].num, studentsInfo[hiKoScore].name, studentsInfo[hiKoScore].koScore);
    printf("     자구 : %d %s (%d)\n", studentsInfo[hiDSScore].num, studentsInfo[hiDSScore].name, studentsInfo[hiDSScore].dsScore);
    system("cls");

}

//자구점수 고득점자를 판단하는 코드
void SelectTopDSScore()
{
    int maxDSScore = INT_MIN;
    hiDSScore = 0;
    for (int i = 0; i < STUDENT_CNT; i++)   //학생수만큼 for문을 돌린다.
    {
        if (studentsInfo[i].num != 0)       //학생의 정보가 있는가를 판단하여
        {
            if (maxDSScore < studentsInfo[i].dsScore)   //있다면 최고득점자값보다 학생의 점수가 높은지 판단
            {
                maxDSScore = studentsInfo[i].dsScore;   //이후 최고득점자의 값에 저장
                hiDSScore = i;
            }
        }
    }
}

//국어점수고득점자를 판단하는 코드(위의 코드와 상세설명이 같으므로 생략)
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


//입력받은 값(scanNum)을 각 자리수로나누어 에러를 감지하고 정수형으로 반환
int studentNumberParsing(char* scanNum)
{
    int returnNum = 0;
     if (strlen(scanNum) != 4)  //4자리수가 아닐때 ERROR
    {
        printf("\n   ERROR : 4글자로 숫자를 구성하여 입력하세요.\n");
        return 0;
    }
    if (scanNum[0] > '3' || scanNum[0] == '0') {    //학년 범위를 벗어났을때 ERROR
        printf("\n   ERROR : 학년(1 ~ 3사이의 수를 입력하세요.)\n"); 
        return 0;
    }
    if (scanNum[1] > '3' || scanNum[1] == '0') {    //학반 범위를 벗어났을때 ERROR
        printf("\n   ERROR : 학반(1 ~ 3사이의 수를 입력하세요.)\n");
        return 0;
    }
    if ((scanNum[2]=='0' && scanNum[3]=='0') || (scanNum[2] >= '2' && scanNum[3] > '0')) {  //학번 범위를 벗어났을때 ERROR
        printf("\n   ERROR : 학번(01 ~ 20사이의 수를 입력하세요.)\n");
        return 0;
    }

    //배열로 나누어 받은 값을 학년에 60을 곱하고 반에 20을 곱하고 번호를 이용하여 학생순번을 0부터 180까지 나열
    returnNum += (scanNum[0] - '0' - 1) * 60;
    returnNum += (scanNum[1] - '0' - 1) * 20;
    returnNum += (scanNum[2] - '0') * 10;
    returnNum += (scanNum[3] - '0') * 1;
    return returnNum;
}