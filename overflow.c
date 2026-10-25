/* демонстрація переповнень буфера та захисних практик */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============ Частина A: Стекове переповнення ============ */

void stack_overflow_demo(void)
{
    printf("=== Стекове переповнення (Stack Buffer Overflow) ===\n");

    int secret_value = 0xCAFE;
    char buffer[16];

    printf("До переповнення:  secret_value = 0x%X\n", secret_value);
    printf("  &buffer        = %p (розмір %zu)\n", (void *)buffer, sizeof(buffer));
    printf("  &secret_value  = %p\n", (void *)&secret_value);

    /* Демонстрація небезпечного копіювання (переповнення буфера) */
    /* Рядок містить 27 символів, що більше за 16 байтів буфера */
    strcpy(buffer, "Це дуже довгий рядок-тест!");

    printf("Після переповнення: secret_value = 0x%X (значення змінено через вихід за межі буфера у стеку)\n\n", secret_value);
}

/* ============ Частина B: Купове переповнення ============ */

void heap_overflow_demo(void)
{
    printf("=== Купове переповнення (Heap Buffer Overflow) ===\n");

    int *arr = malloc(10 * sizeof(int));
    if (arr == NULL) return;

    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    arr[10] = 999; 

    printf("arr[9] = %d (останній валідний елемент)\n", arr[9]);
    printf("arr[10] = %d (записано за межами купи)\n\n", arr[10]);

    free(arr);
}

/* ============ Частина C: Захисні практики ============ */

void safe_string_copy(char *dst, size_t dst_size, const char *src)
{
    if (dst_size == 0) return;

    /* Безпечне копіювання з використанням snprintf для запобігання переповненню */
    int written = snprintf(dst, dst_size, "%s", src);
    
    if (written >= (int)dst_size) {
        printf("[Попередження] Рядок було обрізано до %zu байтів!\n", dst_size - 1);
    }
}

int main(void)
{
    printf("=== Демонстрація переповнень буфера ===\n\n");

    stack_overflow_demo();
    heap_overflow_demo();

    printf("=== Безпечне копіювання ===\n");
    char safe_buf[16];
    safe_string_copy(safe_buf, sizeof(safe_buf),
                     "Дуже довгий рядок, що не поміститься у буфер");
    printf("safe_buf = \"%s\" (довжина: %zu)\n", safe_buf, strlen(safe_buf));

    return 0;
}
