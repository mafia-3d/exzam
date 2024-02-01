#include <stdio.h>
#include <stdlib.h>

int main()
{

    int m;
    printf("Введите количество чисел, которое вы хотите ввести: ");
    scanf("%d", &m);

    printf("Введите %d чисел: \n", m);

    int* array = malloc(m *sizeof(int));    // создаем
                                          // динамический массив
    for (int i = 0; i < m; i++) {
        scanf("%d", &array[i]);  // считываем числа в ячейки массива
    }

    printf("Массив: \n");
    for (int i = 0; i < m; i++) {
        printf("%d\t", array[i]);
    }


    int x = 0;
    for (int i = 0; i < m; i++) {
        while (array[i] % 5 == 0 && i < m)  // выводим значение всех ячеек
        {
            for (int j = i; j < m - 1; j++) {
                array[j] = array[j + 1];
            }
            x++;
            m = m - 1;
        }
    }
    printf("\nНовый массив: \n");
    if (x != 0) {
        for (int i = 0; i < m; i++) {
            printf("%d\t", array[i]);
        }
    }
    else {
        printf("нет элементов кратных 5\n");
    }
    if (m == 0) printf("Все элементы удалены\n");;

    printf("\nУдаляем массив");

    free(array);  // удаляем динамический массив
    return 0;

}
