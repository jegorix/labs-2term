//
// Created by jegorix on 19.04.25.
//
//Создать дек для целых чисел. Максимальный размер дека вводится с экрана. Создать
//функции для ввода и вывода элементов дека. При каждом вводе числа слева удаляется элемент, и если
//он не совпадает с введенным числом, то введенное число добавляется справа.
//



#include "deque_actions.h"


Deque* create_deque(int deque_size)
{
    Deque* deque = malloc(sizeof(Deque));
    deque->begin = NULL;
    deque->back = NULL;
    deque->max_size = deque_size;
    printf("\nДек был успешно создан, его размер = %d\n", deque->max_size);
    return deque;
}

int isEmpty(Deque* deque)
{
    return deque->begin == NULL;
}

int get_size_deq(Deque* deque)
{
    deNode* current = deque->begin;
    int size = 0;
    while(current != NULL)
    {
        size++;
        current = current->Next;
    }
    return size;
}



void deq_base_output(Deque* deque)
{
    deNode* current_2 = deque->begin;
    printf("\nСодержимое дека в прямом порядке:\n");
    while(current_2 != NULL)
    {
        printf("%d ", current_2->value);
        current_2 = current_2->Next;
    }
    printf("\n");
}


void deque_output(Deque* deque)
{
    if(isEmpty(deque))
    {
        printf("\nДек пуст...\n");
        return;
    }

    printf("\nВ каком формате вывести дек?\n"
           "В прямой последовательности - любая клавиша\n"
           "В обратной последовательности - 1\n");
    printf(">> ");

    char user_input[50];
    deNode* current_1 = deque->back;
    deNode* current_2 = deque->begin;
    fgets(user_input, 50, stdin);

    switch (user_input[0]) {
        case '1':
            printf("\nСодержимое дека в обратном порядке:\n");
            while(current_1 != NULL)
            {
                printf("%d ", current_1->value);
                current_1 = current_1->Prev;
            }
            printf("\n");
            break;

        default:
            printf("\nСодержимое дека в прямом порядке:\n");
            while(current_2 != NULL)
            {
                printf("%d ", current_2->value);
                current_2 = current_2->Next;
            }
            printf("\n");

    }

}


void push_front(Deque* deque, int data)
{
    int deSize = get_size_deq(deque);
    if(deSize >= deque->max_size)
    {
        printf("Дек переполнен! Нельзя добавить элемент %d (максимальный размер: %d).\n", data, deque->max_size);
        return;
    }

    deNode* newNode = malloc(sizeof(deNode));
    newNode->Next = NULL;
    newNode->Prev = NULL;
    newNode->value = data;

    if(deque->begin == NULL)
    {
        deque->begin = newNode;
        deque->back = newNode;
    }
    else
    {
        newNode->Next = deque->begin;
        deque->begin->Prev = newNode;
        deque->begin = newNode;
    }

}



void push_back(Deque* deque, int data)
{
    int deSize = get_size_deq(deque);
    if(deSize >= deque->max_size)
    {
        printf("Дек переполнен! Нельзя добавить элемент %d (максимальный размер: %d).\n", data, deque->max_size);
        return;
    }

    deNode* newNode = malloc(sizeof(deNode));
    newNode->Next = NULL;
    newNode->Prev = NULL;
    newNode->value = data;

    if(deque->back == NULL)
    {
        deque->begin = newNode;
        deque->back = newNode;
    }
    else
    {
        newNode->Prev = deque->back;
        deque->back->Next = newNode;
        deque->back = newNode;
    }

}



void deque_push_menu(Deque* deque, int value)
{
    printf("\nВыберите место добавления элемента в дек\n"
           "В начало - 1\n"
           "В конец -  любая другая клавиша\n");
    printf(">> ");
    char user_input[50];

    fgets(user_input, 50, stdin);

    switch (user_input[0]) {
        case '1':
            push_front(deque, value);
            printf("\nЭлемент %d успешно добавлен в начало дека\n", value);
            break;

        default:
            push_back(deque, value);
            printf("\nЭлемент %d успешно добавлен в конец дека\n", value);


    }

}


void deque_fill(Deque* deque)
{
    int current_size = get_size_deq(deque);
    if (current_size >= deque->max_size)
    {
        printf("\nНевозможно выполнить операцию заполнение дека,\n"
               "так как он уже заполнен\n");
        return;
    }

    printf("Заполнение в ручную - 1\n");
    printf("Случайными значениями - любая другая клавиша\n");
    printf(">> ");
    char user_input[50];
    fgets(user_input, 50, stdin);

    switch (user_input[0]) {

        case '1':
        {
            for (int i = 0; i < deque->max_size; i++) {
                printf("\nВведите число для добавления:\n");
                printf(">> ");
                int data = execute_verification(min_limit, max_limit);
                push_back(deque, data);
            }
            printf("\nДек был успешно заполнен!\n");
        }break;

        default:
        {
            for (int i = 0; i < deque->max_size; i++) {
                int data = rand_min_limit + rand() % (rand_max_limit - rand_min_limit + 1);
                push_back(deque, data);
            }
            printf("\nДек был успешно заполнен!\n");
        }break;


    }


}

int pop_back(Deque* deque)
{
    if(isEmpty(deque))
    {
        printf("\nДек пуст! Извлечение невозможно.\n");
        return -1;
    }

    deNode* temp = deque->back;
    int data = temp->value;
    deque->back = deque->back->Prev;

    if(deque->back == NULL)
    {
        deque->begin = NULL;
    }
    else
    {
        deque->back->Next = NULL;
    }

    free(temp);
    return data;
}


int pop_front(Deque* deque)
{
    if(isEmpty(deque))
    {
        printf("\nДек пуст! Извлечение невозможно.\n");
        return -1;
    }

    deNode* temp = deque->begin;
    int data = temp->value;
    deque->begin = deque->begin->Next;

    if(deque->begin == NULL)
    {
        deque->back = NULL;
    }
    else
    {
        deque->begin->Prev = NULL;
    }

    free(temp);
    return data;
}




void deque_pop_menu(Deque* deque)
{
    printf("\nВыберите место извлечения элемента из дека\n"
           "Первый элемент - 1\n"
           "Последний элемент -  любая другая клавиша\n");
    printf(">> ");

    char user_input[50];

    fgets(user_input, 50, stdin);

    switch (user_input[0]) {
        case '1':
            printf("\nПервый элемент дека %d\n", pop_front(deque));
            break;

        default:
            printf("\nПоследний элемент дека %d\n",  pop_back(deque));

    }

}


void clear_deque(Deque* deque)
{
    while(!isEmpty(deque))
    {
        pop_back(deque);
    }
}


void special_deq_mode(Deque* deque)
{
    int running = 1;
    int count = 0;

    while(running) {
        if(isEmpty(deque))
        {
            printf("Дек пуст...\n"
                   "Выход...\n");
            running = 0;
            break;
        }

        if (count >= 5)
        {
            printf("\nЖелаете продолжить?\n"
                   "Да - любая клавиша\n"
                   "Нет - 1\n");
            printf(">> ");

            char user_input[50];
            fgets(user_input, 50, stdin);

            switch (user_input[0]) {
                case '1':
                    running = 0;
                    return;

                default:
                    count = 0;
                    break;
            }

        }
        deq_base_output(deque);
        printf("\nВведите число для анализа:\n");
        printf(">> ");
        int number = execute_verification(min_limit, max_limit);
        int value = pop_front(deque);
        if (number != value) {
            push_back(deque, number);
            printf("%d не совпал с элементом слева (%d) => он (%d) добавлен справа\n", number, value, number);
            deq_base_output(deque);
        }
        else {
            printf("%d совпал с элементом слева (%d)  => элемент слева (%d) просто удален\n", number, value, value);
            deq_base_output(deque);
        }
        count++;
    }
}




void deque_actions_menu()
{
    printf("Введите максимальный размер дека\n");
    printf(">> ");
    int deque_size = execute_verification(0, max_limit);
    Deque* deque = create_deque(deque_size);
    int running = 1;

    while(running) {

        printf("\nВыберите операцию для работы с деком:\n"
               "1 - Вывод дека на экран\n"
               "2 - Заполнение дека\n"
               "3 - Добавление элемента в дек\n"
               "4 - Извлечение элемента из дека\n"
               "5 - Узнать размер дека\n"
               "6 - Режим удаления и совпадения\n"
               "7 - Стереть дек\n"
               "8 - Выход\n");
        printf(">> ");

        int user_input = execute_verification(1, 8);

        switch (user_input) {
            case 1:
                deque_output(deque);
                break;

            case 2:
                deque_fill(deque);
                break;

            case 3:
                if(get_size_deq(deque) >= deque->max_size)
                {
                    printf("Дек переполнен! Нельзя добавить элемент (максимальный размер: %d).\n",deque->max_size);
                    continue;
                }
                printf("Введите число для добавления:\n");
                printf(">> ");
                int data = execute_verification(min_limit, max_limit);
                deque_push_menu(deque, data);
                break;

            case 4:

                deque_pop_menu(deque);

                break;


            case 5:
                printf("Количество элементов дека: %d\n", get_size_deq(deque));
                break;

            case 6:
                clear_deque(deque);
                deque_fill(deque);
                special_deq_mode(deque);


            case 7:
                clear_deque(deque);
                printf("\nДек успешно очищен\n");
                break;

            case 8:
                printf("Выход...\n");
                running = 0;
                continue;

        }

    }


}
