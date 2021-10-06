#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE* finput = fopen("input.txt", "r");
    FILE* foutput = fopen("output.txt", "w");

    short str_maxlen, words_len = -1, spaces, flag;
    char words[400][400];

    // input the entire text, including the number at the bottom
    while((fscanf(finput, "%s", words[++words_len])) != EOF);
    // get the number at the bottom
    str_maxlen = (short) strtol(words[--words_len], NULL, 10);

    char output[400][400];
    short output_len = 0, current_len = str_maxlen;
    
    for (short i = 0; i < words_len; i++) {
        // put the word in an output array if it fits
        if (current_len - (int) strlen(words[i]) >= 0) {
            current_len -= (int) (strlen(words[i]) + 1);  
            strcpy(output[output_len], words[i]);
            output_len++;
        } else { // if it doesn't fit, output the line and initialize a new one
            current_len++;
            // prevents division by zero
            if (output_len - 1 > 0) {
                spaces = current_len / (output_len - 1);
                flag = current_len % (output_len - 1);
            } else {
                spaces = 1;
                flag = 0;
            }
            for (short j = 0; j < output_len; j++) {
                // outputs the word...
                fprintf(foutput, "%s", output[j]);
                // ...and this outputs spaces
                if (j != output_len - 1) {
                    // if a line exhausted all "spare" spaces, then input the same amount of spaces
                    for (short k = 0; k <= ((flag > 0) ? spaces + 1 : spaces); k++) {
                        fprintf(foutput, " ");
                    }
                    flag--;
                }
            }
            // initialize the next word into the output array
            fprintf(foutput, "\n");
            strcpy(output[0], words[i]);
            output_len = 1;
            current_len = str_maxlen - (strlen(words[i]) + 1);
        }
    }

    // output the last line left-justified
    for (short i = 0; i < output_len; i++) {
        fprintf(foutput, "%s ", output[i]);
    }
    
    fclose(finput);
    fclose(foutput);
    return 0;
}