#include <stdio.h>
#include <string.h>

int main () {
    char s[256] = "";
    scanf("%s", s);
    for (int i = 0; i < strlen(s) / 2; i++) {
        char c = s[i];
        s[i] = s[strlen(s) - i - 1];
        s[strlen(s) - i - 1] = c;
    }
    printf("%s", s);
    
    return 0;
}