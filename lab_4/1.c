#include <stdio.h>
void func() {
    static int x = 5;
    int y = 5;
    while (y < 10 && x < 10) {
        printf("x = %d, y = %d\n", x, y); 
        x++;
        y++;
        func();
    } 
}
int main() { 
    func();
}