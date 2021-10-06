#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define chrtoint(a) (int) ((int) a - 48)

char RETURN = 0;

void is_date_correct(char date[255]) {
    // check for wrong date format
    if (date[strlen(date) - 1] != ' ') {
        if (strlen(date) != 19) {
            RETURN = 1;
        }
    }

    short day = chrtoint(date[0]) * 10 + chrtoint(date[1]); 
    short month = chrtoint(date[3]) * 10 + chrtoint(date[4]); 
    short year = chrtoint(date[6]) * 1000 + chrtoint(date[7]) * 100 + chrtoint(date[8]) * 10 + chrtoint(date[9]);
    // check leap year condition
    char is_leap_year = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));

    // month check [1, 12]
    if (month < 1 || month > 12) {
        RETURN = 1;
    }

    // days in a month check
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day > 31 || day < 1) {
            RETURN = 1;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30 || day < 1) {
            RETURN = 1;
        }
    }
    if (month == 2) {
        if (is_leap_year) {
            if (day < 1 || day > 29) {
                RETURN = 1;
            }
        } else {
            if (day < 1 || day > 28) {
                RETURN = 1;
            }
        }
    }

    // time validity check
    short hour = chrtoint(date[11]) * 10 + chrtoint(date[12]);
    short minute = chrtoint(date[14]) * 10 + chrtoint(date[15]);
    short second = chrtoint(date[17]) * 10 + chrtoint(date[18]);
    if (hour > 23 || hour < 1 || minute > 59 || minute < 0 || second > 59 || second < 0) {
        RETURN = 1;
    }
}

void is_name_correct(char name[50]) {
    // check for character validity
    for (char i = 0; i < strlen(name); i++) {
        if (!(name[i] == 32 || (name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122))) {
            RETURN = 1;
            break;
        }
    }
}

typedef struct {
    char name[16], pair_pcs[10];
    short amount;
    char size[10];
} Order;

Order is_order_correct(char order[255]) {
    char c = order[strlen(order) - 1], i = 0;
    // printf("Order: %s %lu\n", order, strlen(order));
    char pair_pcs[10], name[16], size_c[16];
    short amount = 0;
    float size = 0.0;
    char flag = 0;
    // removing after-string spaces
    while (c == ' ') {
        c = order[strlen(order) - 1 - i];
        i++;
        flag = 1;
    }
    // c = order[strlen(order) - 1 - i];
    if (flag)
        i--;
    printf("CHAR: %c %d\n", c, RETURN);
    // get pair_pcs
    short pair_len = 0;
    while (c != ' ') {
        c = order[strlen(order) - 1 - i];
        pair_pcs[pair_len] = c;
        i++;
        pair_len++;
    }
    pair_pcs[pair_len - 1] = '\0';

    // get amount
    c = order[strlen(order) - 1 - i];
    short power_10 = 1;
    while (c != ' ') {
        amount += chrtoint(c) * power_10;
        c = order[strlen(order) - 1 - i];
        i++;
        power_10 *= 10;
    }
    amount /= 10;

    // get size
    short size_len = 0;
    c = order[strlen(order) - 1 - i];
    while (c != ' ') {
        c = order[strlen(order) - 1 - i];
        size_c[size_len] = c;
        i++;
        size_len++;
    }
    size_c[size_len] = '\0';
    // reverse size string and convert it to float
    for (short i = 0; i < strlen(size_c) / 2; i++) {
        char tmp;
        tmp = size_c[i];
        size_c[i] = size_c[strlen(size_c) - 1 - i];
        size_c[strlen(size_c) - 1 - i] = tmp;
    }
    // printf("%s", size_c);
    // size = strtof(" 165", NULL);
    // printf("Size: %f %s\n", size, size_c);

    // get name
    c = order[strlen(order) - 1 - i];
    char name_len = 0;
    while (i != strlen(order) + 1) {
        c = order[strlen(order) - 1 - i];
        name[name_len] = c;
        i++;
        name_len++;
    }
    printf("1: %s %d %s %s %d\n", pair_pcs, amount, size_c, name, RETURN);
    is_name_correct(name);

    // reversing the name and pcs_pair
    for (short i = 0; i < strlen(name) / 2; i++) {
        char tmp;
        tmp = name[i];
        name[i] = name[strlen(name) - 1 - i];
        name[strlen(name) - 1 - i] = tmp;
    }
    for (short i = 0; i < strlen(pair_pcs) / 2; i++) {
        char tmp;
        tmp = pair_pcs[i];
        pair_pcs[i] = pair_pcs[strlen(pair_pcs) - 1 - i];
        pair_pcs[strlen(pair_pcs) - 1 - i] = tmp;
    }

    // checking pcs/pair cases
    if (amount <= 0)
        RETURN = 1;
    if (strcmp(pair_pcs, "pair") != 0 && strcmp(pair_pcs, "pcs") != 0)
        RETURN = 1;
    printf("%d %s\n", amount, pair_pcs);
    if (strcmp(pair_pcs, "pair") == 0 && amount > 1) {
        // printf("Here!");
        strcpy(pair_pcs, "pairs");
    }   

    printf("%s %d %f %s %d", pair_pcs, amount, size, name, RETURN);
    printf("\n");

    
    Order res = {.amount = amount};
    strcpy(res.size, size_c);
    strcpy(res.pair_pcs, pair_pcs);
    strcpy(res.name, name);
    return res;
}

void print_order(char name[50], char date[255], char orders_in[255][255], char order_count, FILE* foutput) {
    // making sure that all the input is valid
    is_name_correct(name);
    is_date_correct(date);
    Order orders_out[255];
    for (char i = 0; i < order_count; i++) {
        orders_out[i] = is_order_correct(orders_in[i]);
    }
    // outputting the string beautifully if all input is valid
    if (!RETURN) {
        // removing trailing spaces
        int i = strlen(name) - 1;
        while (name[i] == ' ') {
            name[i] = '\0';
            i--;
        }
        fprintf(foutput, "%s has rented ", name);
        // handling "," and "and" cases in output, hence the switch statement
        switch (order_count) {
            case 1: 
                fprintf(foutput, "%d %s of %s of size%s ", orders_out[0].amount, 
                                                            orders_out[0].pair_pcs,
                                                            orders_out[0].name,
                                                            orders_out[0].size);
            break;
            case 2:
                fprintf(foutput, "%d %s of %s of size%s and ", orders_out[0].amount, 
                                                                orders_out[0].pair_pcs,
                                                                orders_out[0].name,
                                                                orders_out[0].size);
                fprintf(foutput, "%d %s of %s of size%s ", orders_out[1].amount, 
                                                            orders_out[1].pair_pcs,
                                                            orders_out[1].name,
                                                            orders_out[1].size);
            break;
            default:
                for (char i = 0; i < order_count - 2; i++) {
                    fprintf(foutput, "%d %s of %s of size%s, ", orders_out[i].amount, 
                                                        orders_out[i].pair_pcs,
                                                        orders_out[i].name,
                                                        orders_out[i].size);
                }
                fprintf(foutput, "%d %s of %s of size%s and ", orders_out[order_count - 2].amount, 
                                                                orders_out[order_count - 2].pair_pcs,
                                                                orders_out[order_count - 2].name,
                                                                orders_out[order_count - 2].size);
                fprintf(foutput, "%d %s of %s of size%s ", orders_out[order_count - 1].amount, 
                                                            orders_out[order_count - 1].pair_pcs,
                                                            orders_out[order_count - 1].name,
                                                            orders_out[order_count - 1].size);
            break;

        }

        // output date and time
        char date_parsed[] = {date[0], date[1], date[2], date[3], date[4], date[5], date[6], date[7], date[8], date[9], '\0'};
        char time_parsed[] = {date[11], date[12], date[13], date[14], date[15], date[16], date[17], date[18], '\0'};
        fprintf(foutput, "on %s at %s.\n", date_parsed, time_parsed);
    }
}

int main() {
    FILE* finput = fopen("input.txt", "r");
    FILE* foutput = fopen("output.txt", "w");

    // fetching the data from the file
    char c = getc(finput), prev_c;
    char order_count = 0;
    char name[50], date[255], orders[255][255];
    char buf[255], buf_len = 0, op_code = 0;
    while (c != EOF) {
        if (prev_c == '\n' && c == '\n') {
            printf(":) %s %s %s %d\n", name, date, orders[0], order_count);
            print_order(name, date, orders, order_count, foutput);
            op_code = 0;
            buf_len = 0;
            order_count = 0;
            if (RETURN)
                break;
        } else {
            if (c == '\n') {
                switch (op_code) {
                    case 0:
                        buf[buf_len] = '\0';
                        strcpy(name, buf);
                        op_code++;
                        buf_len = 0;
                    break;
                    case 1:
                        buf[buf_len] = '\0';
                        strcpy(date, buf);
                        op_code++;
                        buf_len = 0;
                    break;
                    case 2:
                        printf("\n\nOrder %s\n\n", buf);
                        buf[buf_len] = '\0';
                        strcpy(orders[order_count], buf);
                        order_count++;
                        buf_len = 0;
                    break;
                }
            } else {
                buf[buf_len] = c;
                buf_len++;
            }
        }
        printf("%c", c);
        prev_c = c;
        c = getc(finput);
    }
    // adds last order as "while" doesn't do the last iteration
    printf("\n\nOrder %s\n\n", buf);
    buf[buf_len] = '\0';
    strcpy(orders[order_count], buf);
    order_count++;
    printf(":) %s %s %s %d\n", name, date, orders[0], order_count);
    print_order(name, date, orders, order_count, foutput);
    if (RETURN) {
        // deletes all previous file contents and rewrites everything 
        fclose(foutput);
        FILE* foutput = fopen("output.txt", "w");
        fprintf(foutput, "Invalid input!\n");
        return 0;
    }

    fclose(finput);
    fclose(foutput);
    return 0;
}