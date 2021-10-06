#include <stdio.h>
#define BOOK_LENGTH 3

typedef struct {
    char name[100];
    unsigned char ingredients_length;
    char ingredients[100][100];
} recipe;

int main() {
    recipe recipe_book[BOOK_LENGTH] = {
        {
            .name = "Pizza",
            .ingredients_length = 4,
            .ingredients = {"Cheese", "Flour", "Eggs", "Tomatoes"}
        },
        {
            .name = "Pasta",
            .ingredients_length = 3,
            .ingredients = {"Pasta", "Butter", "Water"}
        },
        {
            .name = "Rice",
            .ingredients_length = 3,
            .ingredients = {"Rice", "Water", "Soy Sauce (optional)"}
        }
    };

    for (char i = 0; i < BOOK_LENGTH; i++) {
        printf("Name: %s\n", recipe_book[i].name);
        for (char j = 1; j <= recipe_book[i].ingredients_length; j++) {
            printf("\tIngredient %d: %s\n", j, recipe_book[i].ingredients[j - 1]);
        }
    }

    return 0;
}