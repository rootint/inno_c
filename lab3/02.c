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

    for (short i = 0; i < dic_len; i++) {
        for (short j = i + 1; j < dic_len; j++) {
            if (dic[i].value < dic[j].value) {
                char k;
                int v;
                v = dic[i].value;
                dic[i].value = dic[j].value;
                dic[j].value = v;
                k = dic[i].key;
                dic[i].key = dic[j].key;
                dic[j].key = k;
            }
            if (dic[i].value == dic[j].value) {
                if (dic[i].key > dic[j].key) {
                    char k;
                    k = dic[i].key;
                    dic[i].key = dic[j].key;
                    dic[j].key = k;
                }
            }
        }
    }
    for (short i = 0; i < dic_len; i++) {
        printf("%c ", dic[i].key);
        for (short j = 0; j < dic[i].value; j++) {
            printf(".");
        }
        printf("\n");
    }

    return 0;
}