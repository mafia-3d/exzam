#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m;
    printf("Введите количество чисел, которое вы хотите ввести: ");
    scanf("%d", &m);

    printf("Введите %d чисел: \n", m);

    float* array =malloc(m*sizeof(float));    // создаем
                                          // динамический массив
    for (int i = 0; i < m; i++) {
        scanf("%f", &array[i]);  // считываем числа в ячейки массива
    }

    printf("Массив: \n");
        for (int i = 0; i < m; i++) {
            printf("%f\t", array[i]);
        }
 
    printf("\nПоложительные числа: \n");
    float sum=0;
    int x = 0;
    for (int i = 0; i < m; i++) {
        if(array[i]>0)  // выводим значение всех ячеек
        {
            printf("%f\t", array[i]);
            x++;
            sum = sum + array[i];
        }
    }
    sum = sum / (float) x;

    if (x != 0) {
        printf("\nКоличество элементов: %d\n", x);
        printf("Среднее арифметическое элементов: %f\n", sum);
    }
    else {
        printf("Положительных элементов нет\n");
    }

    printf("\nУдаляем массив");

    free(array);  // удаляем динамический массив
	return 0;

}
