#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m;
    printf("Введите количество чисел, которое вы хотите ввести: ");
    scanf("%d", &m);

    printf("Введите %d чисел: \n", m);

    int* array = malloc(m* sizeof(int));    // создаем
                                          // динамический массив
    for (int i = 0; i < m; i++) {
        scanf("%d", &array[i]);  // считываем числа в ячейки массива
    }

    printf("Массив: \n");
        for (int i = 0; i < m; i++) {
            printf("%d\t", array[i]);
        }
 
    printf("\nЧисла больше 10: \n");
    int x = 0;
    for (int i = 0; i < m; i++) {
        if(array[i]>10)  // выводим значение всех ячеек
        {
            printf("%d\t", array[i]);
            x++;
        }
    }

    if (x != 0) {
        printf("\nКоличество элементов: %d\n", x);
    }
    else {
        printf("Элементов больше 10 нет\n");
    }

    printf("\nУдаляем массив");

    free(array);  // удаляем динамический массив
	return 0;

}
