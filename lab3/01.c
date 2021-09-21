// create github repo with all the links

#include <stdio.h>
#include <string.h>

typedef struct {
    char key;
    int value;
} dict;

int main() {
    char str[255];
    dict dic[255];
    short dic_len = 0;
    scanf("%[^\n]", str);
    for (short i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            char flag = 't';
            for (short j = 0; j < dic_len; j++) {
                if (str[i] == dic[j].key) {
                    dic[j].value++;
                    flag = 'f';
                    break;
                }
            }
            if (flag == 't') {
                dic[dic_len].key = str[i];
                dic[dic_len].value = 1;
                dic_len++;
                flag = 'f';
            }
        }
    }
    for (short i = 0;  i < dic_len; i++) {
        printf("%c ", dic[i].key);
        for (short j = 0; j < dic[i].value; j++) {
            printf(".");
        }
        printf("\n");
    }
    printf("\n");
    short max_value = 0;
    for (short i = 0; i < dic_len; i++) {
        printf("%c ", dic[i].key);
        max_value = (dic[i].value > max_value) ? dic[i].value : max_value;
    }
    printf("\n");
    short k = 1;
    while (k - 1 < max_value) {
        for (short i = 0; i < dic_len; i++) {
            if (k <= dic[i].value) {
                printf(". ");
            } else {
                printf("  ");
            }
        }
        k++;
        printf("\n");
    }
    return 0;
}