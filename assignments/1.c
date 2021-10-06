#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int c;
    c = *a;
    *a = *b;
    *a = c;
}

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
 
    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

void bubble_sort(int* arr, short arr_len) {
    printf("%d %d %d\n", arr[0], arr[1], arr_len);
    for (short i = 0; i < arr_len; i++) {
        for (short j = i + 1; j < arr_len; j++) {
            if (arr[i] > arr[j]) {
                printf("%d %d\n", arr[i], arr[j]);
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main () {
    FILE *in_file = fopen("input.txt", "r");
    FILE *out_file = fopen("output.txt", "w");

    // char buffer[255], res[255];
    int arr[1000];
    char buf[255];
    short buf_len = 0, arr_len = 0;

    int c = getc(in_file);

    while (c != EOF) {
        buf[buf_len++] = c;
        if (c == ' ') {
            arr[arr_len++] = (int) strtol(buf, NULL, 16);
            for (short i = 0; i < buf_len; i++) {
                buf[i] = 0;
            }
            buf_len = 0;
        }
        c = getc(in_file);
    }
    arr[arr_len++] = (int) strtol(buf, NULL, 16);

    // bubble_sort(arr, arr_len);
    qsort(arr, arr_len, sizeof(int), compare_ints);

    for (short i = 0; i < arr_len; i++) {
        fprintf(out_file, "%X ", arr[i]);
    }


    // fprintf(out_file, "%d", len);

    fclose(in_file);
    fclose(out_file);
    return 0;
}