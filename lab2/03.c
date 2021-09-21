#include <stdio.h>

void iso_triangle_1 () {
    short n;
    printf("Enter the height of the triangle: ");
    scanf("%hd", &n);
    for (short i = 1; i < n * 2; i += 2) {
        for (short j = n - i / 2; j > 1; j--) {
            printf(" ");
        }
        for (short j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    } 
}

void iso_triangle_2 () {
    short n;
    printf("Enter the maximum width of the triangle: ");
    scanf("%hd", &n);
    for (short i = 1; i <= n * 2; i++) {
        for (short j = 0; j < i / 2; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (short i = n * 2; i >= 1; i--) {
        for (short j = 0; j < i / 2; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void rectangle () {
    short w, h;
    printf("Enter the width and height: ");
    scanf("%hd%hd", &w, &h);  
    for (short i = 0; i < h; i++) {
        for (short j = 0; j < w; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main () {
    printf("Enter the number of the pattern:\n");
    printf("1 - isosceles triangle (vertical);\n");
    printf("2 - isosceles triangle (horizontal);\n");
    printf("3 - rectangle.\n");
    short num;
    scanf("%hd", &num);
    switch (num)
    {
    case 1:
        iso_triangle_1();
        break;
    
    case 2:
        iso_triangle_2();
        break;

    case 3:
        rectangle();
        break;

    default:
        printf("No such pattern!\n");
        return 0;
    }
    return 0;
}