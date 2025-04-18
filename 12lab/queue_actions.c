//
// Created by jegorix on 18.04.25.
//

#include "queue_actions.h"


Queue* create_queue(int queue_size)
{
    Queue* queue = malloc(sizeof(Queue));

    queue->begin = NULL;
    queue->back = NULL;
    queue->max_size = queue_size;
    printf("Очередь успешно создана, ее размер = %d", queue_size);
    return queue;
}


void queue_output(Queue* queue)
{
    Node* current = queue->begin;
    printf("Содержимое очереди:\n");

    if(current == NULL)
    {
        printf("Очередь пуста...\n");
        return;
    }

    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->Next;
    }

}


int get_size(Queue* queue)
{
    int q_size = 0;
    Node* current = queue->begin;
    while(current != NULL)
    {
        q_size++;
        current = current->Next;
    }

    return q_size;
}


void queue_push(Queue* queue, int value)
{
    int current_size = get_size(queue);

    if(current_size >= queue->max_size)
    {
        printf("Очередь переполнена! Нельзя добавить элемент %d (максимальный размер: %d).\n", value, queue->max_size);
    }

    Node* new_node = malloc(sizeof(new_node));

    new_node->value = value;
    new_node->Next = NULL;

    if(queue->back == NULL)
    {
        queue->back = new_node;
        queue->begin = new_node;
    }

    else
    {
       queue->back->Next = new_node;
       queue->back = new_node;
    }

}

void queue_fill(Queue* queue)
{
    int current_size = get_size(queue);
    if (current_size >= queue->max_size)
    {
        printf("Невозможно выполнить операцию заполнение очереди,\n"
               "так как она уже заполнена\n");
        return;
    }

    printf("Заполнение в ручную - 1\n");
    printf("Случайными значениями - любая другая клавиша\n");
    char user_input[50];
    fgets(user_input, 50, stdin);

    switch (user_input[0]) {

        case '1':
        {
            for (int i = 0; i < queue->max_size; i++) {
                printf("Введите число для добавления:\n");
                int data = execute_verification(min_limit, max_limit);
                queue_push(queue, data);
            }
            printf("Очередь была успешно заполнена!\n");
        }break;

        default:
        {
            for (int i = 0; i < queue->max_size; i++) {
                int data = rand_min_limit + rand() % (rand_max_limit - rand_min_limit + 1);
                queue_push(queue, data);
            }
            printf("Очередь была успешно заполнена!\n");
        }break;


    }


}

int queue_pop(Queue* queue)
{
    if(queue->begin == NULL)
    {
        printf("Очередь пуста! Извлечение невозможно.\n");
        return -1;
    }

    Node* temp = queue->begin;
    int data = temp->value;

    queue->begin = queue->begin->Next;

    if(queue->begin == NULL)
    {
        queue->back = NULL;
    }
    free(temp);
    return data;

}

void clear_queue(Queue* queue)
{
    if(queue->begin == NULL)
    {
        printf("\nОчередь пуста...\n");
        return;
    }
    while(queue->begin != NULL)
    {
        queue_pop(queue);
    }
}




void queue_actions_menu()
{
    printf("Введите максимальный размер очереди\n");
    int queue_size = execute_verification(0, max_limit);
    Queue* queue = create_queue(queue_size);
    int catch;

    while(1) {

        printf("\nВыберите операцию для работы с очередью:\n"
               "1 - Вывод очереди на экран\n"
               "2 - Заполнение очереди\n"
               "3 - Добавление элемента в очередь\n"
               "4 - Извлечение элемента очереди\n"
               "5 - Узнать размер очереди\n"
               "6 - Режим удаления и совпадения\n"
               "7 - Стереть очередь\n"
               "8 - Выход\n");

        int user_input = execute_verification(1, 8);

        switch (user_input) {
            case 1:
                queue_output(queue);
                break;

            case 2:
            queue_fill(queue);
                break;

            case 3:
                printf("Введите число для добавления:\n");
                int data = execute_verification(min_limit, max_limit);
                queue_push(queue, data);
                break;

            case 4:
                catch = queue_pop(queue);
                if(catch == -1)
                {
                    continue;
                }
                printf("\nПервый элемент в очереди %d\n", catch);
                break;


            case 5:
                printf("Количество элементов очереди: %d\n", get_size(queue));
                break;

            case 7:
                clear_queue(queue);
                printf("\nОчередь успешно очищена\n");
                break;

            case 8:
                printf("Выход...\n");
                exit(1);

        }

    }


}
