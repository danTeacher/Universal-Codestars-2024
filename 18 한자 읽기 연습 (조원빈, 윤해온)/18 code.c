#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define SIZE 15


char CorrectA1[SIZE][5] =
{
    "人",
    "水",
    "大",
    "小",
    "母",
    "正",
    "火",
    "生",
    "山",
    "多",
    "上",
    "石",
    "天",
    "手",
    "心"
};
char CorrectB1[SIZE][3] =
{
    "인",
    "수",
    "대",
    "소",
    "모",
    "정",
    "화",
    "생",
    "산",
    "다",
    "상",
    "석",
    "천",
    "수",
    "심"
};
char CorrectC1[SIZE][10] =
{
    "사람 인",
    "물 수",
    "큰 대",
    "작을 소",
    "어미 모",
    "바를 정",
    "불 화",
    "날 생",
    "산 산",
    "많을 다",
    "윗 상",
    "돌 석",
    "하늘 천",
    "손 수",
    "마음 심"
};

char CorrectA2[SIZE][5] =
{
    "命",
    "白",
    "速",
    "言",
    "家",
    "毛",
    "學",
    "地",
    "文",
    "用",
    "名",
    "無",
    "品",
    "古",
    "死"
};
char CorrectB2[SIZE][3] =
{
    "명",
    "백",
    "속",
    "언",
    "가",
    "모",
    "학",
    "지",
    "문",
    "용",
    "명",
    "무",
    "품",
    "고",
    "사"
};
char CorrectC2[SIZE][10] =
{
    "목숨 명",
    "흰 백",
    "빠를 속",
    "말씀 언",
    "집 가",
    "털 모",
    "배울 학",
    "땅 지",
    "글월 문",
    "쓸 용",
    "이름 명",
    "없을 무",
    "물건 품",
    "쓸 고",
    "죽을 사"
};

char CorrectA3[SIZE][5] =
{
    "油",
    "道",
    "雪",
    "利",
    "烏",
    "龍",
    "夢",
    "破",
    "神",
    "魂",
    "靑",
    "走",
    "國",
    "冊",
    "老"
};
char CorrectB3[SIZE][3] =
{
    "유",
    "도",
    "설",
    "이",
    "오",
    "용",
    "몽",
    "파",
    "신",
    "혼",
    "청",
    "주",
    "국",
    "책",
    "노"
};
char CorrectC3[SIZE][13] =
{
    "기름 유",
    "길 도",
    "눈 설",
    "이로울 이",
    "까마귀 오",
    "용 용",
    "꿈 몽",
    "깨트릴 파",
    "귀신 신",
    "넋 혼",
    "푸를 청",
    "달릴 주",
    "나라 국",
    "책 책",
    "늙을 노"
};

char CorrectA4[SIZE][5] =
{
    "卯",
    "擧",
    "虹",
    "兩",
    "退",
    "鷄",
    "會",
    "藥",
    "勞",
    "答",
    "鼻",
    "翼",
    "賣",
    "與",
    "禁"
};
char CorrectB4[SIZE][3] =
{
    "묘",
    "거",
    "홍",
    "양",
    "퇴",
    "계",
    "회",
    "약",
    "노",
    "답",
    "비",
    "익",
    "매",
    "여",
    "금"
};
char CorrectC4[SIZE][13] =
{
    "토끼 묘",
    "들 거",
    "무지개 홍",
    "양 양",
    "물러날 퇴",
    "닭 계",
    "모일 회",
    "약 약",
    "일할 노",
    "대답할 답",
    "코 비",
    "날개 익",
    "팔 매",
    "줄 여",
    "금할 금"
};
char lol[3];
int a,i;
int start = 1;


int Level1(void)
{
    int co = 0;
    for (int i = 0; i < 5; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        a = rand() % SIZE;
        printf("\n%s\n", CorrectA1[a]);
        scanf("%s", lol);
        if (strcmp(lol, CorrectB1[a]) == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            printf("정답!\n");
            co += 1;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            printf("실패! 정답은 '%s'\n", CorrectC1[a]);
        }
    }
    return co;
}

int Level2(void)
{
    int co = 0;
    for (int i = 0; i < 5; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        a = rand() % SIZE;
        printf("\n%s\n", CorrectA2[a]);
        scanf("%s", lol);
        if (strcmp(lol, CorrectB2[a]) == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            printf("정답!\n");
            co += 1;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            printf("실패! 정답은 '%s'\n", CorrectC2[a]);
        }
    }
    return co;
}

int Level3(void)
{
    int co = 0;
    for (int i = 0; i < 5; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        a = rand() % SIZE;
        printf("\n%s\n", CorrectA3[a]);
        scanf("%s", lol);
        if (strcmp(lol, CorrectB3[a]) == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            printf("정답!\n");
            co += 1;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            printf("실패! 정답은 '%s'\n", CorrectC3[a]);
        }
    }
    return co;
}

int Level4(void)
{
    int co = 0;
    for (int i = 0; i < 5; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        a = rand() % SIZE;
        printf("\n%s\n", CorrectA4[a]);
        scanf("%s", lol);
        if (strcmp(lol, CorrectB4[a]) == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            printf("정답!\n");
            co += 1;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            printf("실패! 정답은 '%s'\n", CorrectC4[a]);
        }
    }
    return co;
}

int main(void)
{
    srand(time(NULL));
    restart:
    for (;;)
    {
        int dd, ad, as = 1, asdf;
        if (as == 1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("\nLevel1:\n\n");
            ad = Level1();
            dd = ad;
            if (ad >= 3)
            {
                as += 1;
            }
        }
        if (as == 2) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("\nLevel2:\n\n");
            ad = Level2();
            dd += ad;
            if (ad >= 4)
            {
                as += 1;
            }
        }
        if (as == 3)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("\nLevel3:\n\n");
            ad = Level3();
            dd += ad;
            if (ad >= 3)
            {
                as += 1;
            }
        }
        if (as == 4)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("\nLevel4:\n\n");
            ad = Level4();
            dd += ad;
            if (ad >= 3)
            {
                as += 1;
            }
        }
        if (as == 5)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        printf("\n당신의 맞은 개수: %d", dd);
        if (dd == 20)
        {
            printf("\n!!한자 마스터!!\n");
        }
        else if (dd >= 18)
        {
            printf("\n아깝네요! 올백을 위해 파이팅!!\n");
        }
        else if (dd >= 15)
        {
            printf("\n한자 고인물!!\n");
        }
        else if (dd >= 13)
        {
            printf("\n한자의 고수!\n");
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("\n(1.다시하기 / 2.종료하기)");
        asdf == 1;
        scanf("%d", &asdf);
        if (asdf == 2)
        {
            printf("크레딧:\n======제 작======\n     조원빈\n===보고서 작성===\n  윤해온,조원빈\n====특별 도움====\n     정두강\n======도 움======\n       쌤\n======팀 명======\n      HΦCL\n플레이해주셔서 감사합니다.");
        break;
        }
        if (asdf == 1)
        {
            goto restart;
        }
    }
    return 0;
}
