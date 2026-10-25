/* виправлена програма без помилок пам'яті */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *create_list(int count)
{
    Node *head = NULL;
    for (int i = count; i > 0; i--) {
        Node *node = malloc(sizeof(Node));
        if (node == NULL) return head;
        node->value = i;
        node->next = head;
        head = node;
    }
    return head;
}

void print_list(const Node *head)
{
    printf("Список: ");
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

void free_list(Node *head)
{
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void)
{
  
    int *values = calloc(5, sizeof(int));
    if (values == NULL) return EXIT_FAILURE;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += values[i];
    }
    printf("Сума (ініціалізована): %d\n", sum);
    free(values);
    int *arr = malloc(10 * sizeof(int));
    if (arr == NULL) return EXIT_FAILURE;
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 100;
    }
    free(arr);
    char *message = malloc(50);
    if (message == NULL) return EXIT_FAILURE;
    strcpy(message, "Важливе повідомлення");
    printf("Повідомлення: %s\n", message);
    free(message);

    int *buffer = malloc(100 * sizeof(int));
    if (buffer == NULL) return EXIT_FAILURE;
    buffer[0] = 42;
    free(buffer);

    Node *list = create_list(5);
    print_list(list);
    free_list(list); /* Звільнення пам'яті списку */

    return EXIT_SUCCESS;
}
