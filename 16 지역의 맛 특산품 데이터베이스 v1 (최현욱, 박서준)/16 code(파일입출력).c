 #include <stdio.h>
#include <string.h>

int main() {
    char region[50], season[50], food[50], filename[200];
    char buff[200];

    while (1) {
        printf("선택 가능 지역: 부산 제주도\n");
        printf("지역을 입력하세요: ");
        scanf("%s", region);

        printf("선택 가능 계절: 봄 여름 가을 겨울\n");
        printf("계절을 입력하세요: ");
        scanf("%s", season);

        sprintf(filename, "./%s/%s/%s.txt", region, season, season);
        FILE* file = fopen(filename, "r");
        if (file == NULL) {
            printf("파일을 여는 데 오류가 발생했습니다.\n");
            return -1;
        }

        printf("선택 가능 음식: ");
        if (fgets(buff, sizeof(buff), file) != NULL) {
            printf("%s\n", buff);
        }
        else {
            printf("오류 발생...\n");
        }
        fclose(file);
        
        printf("음식을 입력하세요: ");
        scanf("%s", food);

        sprintf(filename, "./%s/%s/%s.txt", region, season, food);
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("파일을 여는 데 오류가 발생했습니다.\n");
            return -1;
        }

        while (fgets(buff, sizeof(buff), file) != NULL) {
            printf("%s", buff);
        }
        printf("\n\n");
        
        fclose(file);
    }

    return 0;
}
