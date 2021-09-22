#include <stdio.h>

typedef struct {
    short day;
    char month[20];
    short year;
} ExamDay;

typedef struct {
    char name[255];
    char surname[255];
    short group_num;
    ExamDay day;
} Student;

int main() {
    Student student;
    printf("Enter your name: ");
    scanf("%s", student.name);
    printf("Enter your surname: ");
    scanf("%s", student.surname);
    printf("Enter your group number: ");
    scanf("%hd", &student.group_num);
    printf("Enter the date of your exam: (day month year) ");
    scanf("%hd %s %hd", &student.day.day, student.day.month, &student.day.year);

    printf("Name: %s %s %hd\n", student.name, student.surname, student.group_num);
    printf("Exam date: %hd %s %hd\n", student.day.day, student.day.month, student.day.year);
    return 0;
}