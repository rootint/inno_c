#include <stdio.h>
#include <string.h>

char guess[3];
int attempt = 0;

void brute_force(char pass[3]) {
    switch (strlen(pass)) {
        case 1:
            for (char i = 32; i <= 126; i++) {
                attempt++;  
                if (i == pass[0]) {
                    guess[0] = i;
                    break;
                }
            }
        break;
        case 2:
            for (char i = 32; i <= 126; i++) {
                for (char j = 32; j <= 126; j++) {
                    attempt++;  
                    guess[0] = i;
                    guess[1] = j;
                    if (!strcmp(guess, pass)) {
                        return;
                    }
                }
            }
        break;

        case 3:
            for (char i = 32; i <= 126; i++) {
                for (char j = 32; j <= 126; j++) {
                    for (char k = 32; k <= 126; k++) {
                        attempt++;  
                        guess[0] = i;
                        guess[1] = j;
                        guess[2] = k;
                        if (!strcmp(guess, pass)) {
                            return;
                        }
                    }
                }
            }
        break;
    }
}

int main() {
    char pass[3];
    scanf("%s", pass);
    brute_force(pass);
    printf("Password: %s\nAttempts: %d\n", guess, attempt);
    return 0;
}