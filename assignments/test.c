#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE* finput = fopen("input.txt", "r");
    FILE* foutput = fopen("output.txt", "w");

    

    fclose(finput);
    fclose(foutput);
    return 0;
}