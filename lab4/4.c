#include <stdio.h>
#include <time.h>

typedef struct {
    unsigned char day: 5;
    unsigned char month: 4;
    unsigned char year: 7;
} date;

void print_date(date dmy, unsigned short current_year) {
    printf("Day: %d\n", dmy.day);
    printf("Month: %d\n", dmy.month);
    printf("Year: %d\n", current_year - dmy.year);
}

int main() {
    // getting current year
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    unsigned short CURRENT_YEAR = tm.tm_year + 1900;

    // date insertion via {current_year - year of birth}
    date dmy = {28, 8, CURRENT_YEAR - 2003};
    
    print_date(dmy, CURRENT_YEAR);
    
    return 0;
}