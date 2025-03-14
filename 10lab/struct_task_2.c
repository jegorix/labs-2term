// Структура содержит информацию о геометрических фигурах: площадь (число), название (указатель),
// вложенную структуру – периметр (вещественное число) и цвет (строка фиксированной длины). 
// Найти фигуры с площадью, меньше заданной. Удалить фигуры с заданным названием.

// Новицкий

// 13.03.2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int execute_verirfication(int min_limit, int max_limit)
{
    char input[100];
    int number;
    char symbol;
     
    while(1)
    {
        if(fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Ошибка ввода! Попробуйте еще раз!\n");
            continue;
        }

        if (sscanf(input, "%d %c", &number, &symbol) != 1)
        {
            printf("Ошибка ввода! Введите целое число:\n");
            continue;
        }

        if (number > max_limit || number < min_limit)
        {
            printf("Ошибка ввода! Введите число из диапазона [%d, %d]:\n", min_limit, max_limit);
            continue;
        }

        return number;

    }

}



enum
{
    max_limit = 2147483647,
    min_limit = 0,
};


typedef struct
{
    float perm;

} Perimiter;



typedef struct
{
    int square;
    char* name;
    Perimiter perim;
    char* color;
} Square;



void handle_figure_input(int figure_count)
{
    Square* figure = malloc(sizeof(Square) * figure_count); // create figures array

    for(int i = 0; i < figure_count; i++)
    {
        char* fig_name = malloc(256 * sizeof(char));
        printf("Введите имя вашей фигуры № %d:\n", i + 1);
        fgets(fig_name, 256, stdin);
        fig_name[strcspn(fig_name, "\n")] = '\0';
        figure[i].name = malloc(strlen(fig_name) + 1);
        strcpy(figure[i].name, fig_name);
        free(fig_name);

        printf("Введите площадь фигуры '%s':\n", figure[i].name);
        figure[i].square = execute_verirfication(min_limit, max_limit);

        printf("Введите периметр фигуры '%s'\n", figure[i].name);
        figure[i].perim.perm = execute_verirfication(min_limit, max_limit);

        printf("Введите цвет фигуры '%s':\n", figure[i].name);
        char* fig_color = malloc(256 * sizeof(char));
        fgets(fig_color, 256, stdin);
        fig_color[strcspn(fig_name, "\n")] = '\0';
        figure[i].color = malloc(strlen(fig_color) + 1);
        strcpy(figure[i].color, fig_color);
        free(fig_color);

    }

    
}



void identify_figure_count()
{
    char* user_choice = malloc(50 * sizeof(char));
    printf("Введите количество фигур:\n");
    int figure_count = execute_verirfication(min_limit, max_limit);
    printf("Ввести фигуры вручную - 1. Рандомные фигуры - любая клавиша:\n");
    fgets(user_choice, sizeof(user_choice), stdin);

    switch(user_choice[0])
    {
        case '1':
        handle_figure_input(figure_count);
        break;

        // default:
        // random_figure_input(figure_count);
        // break;

    }

}




int main(void)
{

    identify_figure_count();


    // Square* circle = malloc(sizeof(Square) * 3);

    // circle[0].square = 26;
    // strcpy(circle[0].name, "Circle");

    // printf("%s\n", circle[0].name);


    return 0;
}