#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} dict;

int main() {
    dict dic[1000];
    short dic_len = 0;
    int arr[255];
    short arr_size = 0, buf_len = 0;
    char in_string[255];
    char buf[255];

    scanf("%[^\n]", in_string); // add a whitespace at the end
    for (short i = 0; i < strlen(in_string); i++) {
        buf[buf_len] = in_string[i];
        buf_len++;
        if (in_string[i] == ' ') {
            arr[arr_size] = (int) strtol(buf, NULL, 10);
            buf_len = 0;
            arr_size++;
        }
    }
    // for (short i = 0; i < arr_size; i++) {
    //     printf("%d ", arr[i]);
    // }

    for (short i = 0; i < arr_size; i++) {
        char flag = 't';
        for (short j = 0; j < dic_len; j++) {
            if (arr[i] == dic[j].key) {
                dic[j].value++;
                flag = 'f';
                break;
            }
        }
        if (flag == 't') {
            dic[dic_len].key = arr[i];
            dic[dic_len].value = 1;
            dic_len++;
            flag = 'f';
        }
    }

    for (short i = 0; i < dic_len; i++) {
        printf("%d ", dic[i].key);
    }
    printf("\n");

    return 0;
}