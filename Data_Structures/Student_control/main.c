//성적 관리 프로그램
//학생 번호 순으로 배열에 보관
//scanf(), scanf_s

//[정보 입력 부분]
//학생정보를 입력해주세요.
//학번:
//이름:
//주소:
//전화번호:
//국어 점수 :
//자료구조 점수 :
//
//[검색 부분]
//학번을 입력하세요. 1101을 입력하면
//학생정보(학번, 이름, 주소 등)이 나온다.
//만약 해당 학생이 없으면 없다고 출력한다.
//
//[삭제 기능]
//전학 등으로 학생이 없을 경우 학생을 삭제하는 기능을 추가한다.
//해당 학번은 모두 빈 칸으로 출력되게 하되 이름에는 ‘전학’이라는 글자가 나오게 한다.
//
//[1등 출력 기능]
//국어 점수가 가장 높은 학생을 출력하는 기능 추가하기
//자료구조 점수가 가장 높은 학생을 출력하는 기능 추가하기
//
//[공통사항]
//잘못된 입력이 발생될 경우 판단하여 에러메시지 보여주기.
//예) 학번을 입력하세요. 11129
//4자리를 입력하세요.등으로 적절히 처리하기


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
    printf("  ====== 학생 관리 프로그램 =======\n");
    printf("  +-------------------------------+\n");
    printf("  |                               |\n");
    printf("  |   1.학생관리     2. 학생검색  |\n");
    printf("  |   3.순위출력     4.  종료     |\n");
    printf("  |                               |\n");
    printf("  +-------------------------------+\n");
    printf("  탭이동 : ");
    scanf("%d", &tapNum);

    printf("\n\n\n");

    switch (tapNum)
    {
    case 1:
        printf("  ====== 학생 관리 프로그램 =======\n");
        printf("  +--------- 학생 관리 -----------+\n");
        printf("  |                               |\n");
        printf("  |   1. 학생추가   2. 학생삭제   |\n");
        printf("  |                               |\n");
        printf("  +-------------------------------|\n");
        printf("  탭이동 : ");
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
            printf("보기중 하나를 선택하시오. \n");
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
        printf("종료하시겠습니까?(Y) : ");
        do {
            scanf("%c", &exit_scan);
        } while (exit_scan == 10);
        if (exit_scan == 'Y')
            exit(1);
        else {
            printf("종료를 하실려면 Y를 눌러주세요.\n");
            return;
        }
        break;
    default:
        printf("보기중 하나를 선택하시오. \n");
        return;
    }
    return;
}

void init() {
    char scanNum[5];
    char idx;
    printf("  ------------학생 추가------------\n");
    printf("    학번   : ");

    // 제대로 된 학번이 아닐때 예외처리
    scanf("%s", scanNum);
    idx = studentNumberParsing(scanNum);
    if (idx == 0)return;


    if (studentsInfo[idx].num != 0)
    {
        printf("이미 있음 ㅋㅋㄹㅃㅃ\n");
        return;
    }
    if (strcmp(studentsInfo[idx].name, "전학") == 0)
    {
        printf("전학 갔음 ㅋㅋㄹㅃㅃ\n");
        return;
    }


    studentsInfo[idx].num = atoi(scanNum);


    printf("    이름   : ");
    scanf("%s", studentsInfo[idx].name);

    printf("    주소   : ");
    scanf("%s", studentsInfo[idx].address);

    printf("  전화번호 : ");
    scanf("%s", studentsInfo[idx].phone);

    while (1) {
        printf("  국어점수 : ");
        scanf("%d", &studentsInfo[idx].koScore);
        if (studentsInfo[idx].koScore > 100 || studentsInfo[idx].koScore < 0)
        {
            printf("잘못 입력하셨습니다. 다시 입력하셈\n");
            continue;
        }
        else {
            break;
        }
    }

    while (1) {
        printf("  자구점수 : ");
        scanf("%d", &studentsInfo[idx].dsScore);
        if (studentsInfo[idx].dsScore > 100 || studentsInfo[idx].dsScore < 0)
        {
            printf("잘못 입력하셨습니다. 다시 입력하셈\n");
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
    printf("  ----------- 학생 전학 -----------\n");
    printf("    학번   : ");

    scanf("%s", scanNum);
    idx = studentNumberParsing(scanNum);
    if (idx == 0)return;

    if (strcmp(studentsInfo[idx].name, "전학") == 0)
    {
        printf("이미 전학 갔음 ㅋㅋㄹㅃㅃ\n");
        return;
    }
    if (studentsInfo[idx].num == 0)
    {
        printf("존재한적이 없음 ㅋㅋㄹㅃㅃ\n");
        return;
    }

    studentsInfo[idx].num = atoi(scanNum);

    printf("  %d %s 이 전학처리 됩니다.\n",studentsInfo[idx].num, studentsInfo[idx].name);

    studentsInfo[idx].name[0] = '\0';
    strcat(studentsInfo[idx].name, "전학");
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
    printf("  ------------학생 찾기------------\n");
    printf("  학번 입력 : ");
    scanf("%s", scanNum);
    printf("\n\n");
    idx = studentNumberParsing(scanNum);
    if (idx == 0) return;


    if (studentsInfo[idx].num != 0)
    {
        printf("존재하지 않는 학생은 못찾아연\n");
        return;
    }

    printf("  ------------검색 목록------------\n");

    printf("    학번   : %d\n", studentsInfo[idx].num);

    printf("    이름   : %s\n", studentsInfo[idx].name);

    printf("    주소   : %s\n", studentsInfo[idx].address);

    printf("  전화번호 : %s\n", studentsInfo[idx].phone);

    printf("  국어점수 : %d\n", studentsInfo[idx].koScore);

    printf("  자구점수 : %d\n", studentsInfo[idx].dsScore);
}

void topScore() {
    if (hiDSScore == 0 || hiKoScore == 0)
    {
        printf("성적 우수자가 존재하지 않습니다.\n\n");
        return;
    }

    printf("  +-------- 성적 우수자 ----------+\n");
    printf("    국어 : %d %s (%d)\n", studentsInfo[hiKoScore].num, studentsInfo[hiKoScore].name, studentsInfo[hiKoScore].koScore);
    printf("    자구 : %d %s (%d)\n", studentsInfo[hiDSScore].num, studentsInfo[hiDSScore].name, studentsInfo[hiDSScore].dsScore);
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
        printf("TIP! : 알고계셨나요? 학번은 4글자입니다.\n");
        return 0;
    }
    if (scanNum[0] > '3' || scanNum[0] < '1') {
        printf("TIP! : 알고계셨나요? 학년은 1학년부터 3학년까지만 있답니다.\n"); 
        return 0;
    }
    if (scanNum[1] > '3' || scanNum[1] < '1') {
        printf("TIP! : 알고계셨나요? 반은 1반부터 3반까지만 있답니다.\n");
        return 0;
    }
    if (scanNum[2] > '2' || scanNum[2] < '0' || scanNum[3] > '9' || scanNum[3] < '0' || (scanNum[2] == '2' && scanNum[3] != '0')) {
        printf("TIP! : 알고계셨나요? 번호는 1번부터 20번까지만 있답니다.\n");
        return 0;
    }


    returnNum += (scanNum[0] - '0' - 1) * 60;
    returnNum += (scanNum[1] - '0' - 1) * 20;
    returnNum += (scanNum[2] - '0') * 10;
    returnNum += (scanNum[3] - '0') * 1;
    return returnNum;
}