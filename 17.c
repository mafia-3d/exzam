#include <stdio.h>
#include <stdlib.h>

int main() {
    int E[10][10]; // Массив (матрица) размером 10x10
    int n; // Размерность матрицы (количество строк и столбцов)

    // Ввод размерности матрицы
    printf("Введите n:");
    scanf("%d", &n);

    // Проверка на корректность введенного значения n
    while (n > 10 || n <= 0) {
        printf("Введите n (от 1 до 10):");
        scanf("%d", &n);
    }

    // Ввод элементов матрицы
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &E[i][j]);
        }
        printf("\n");
    }

    // Вывод введенной матрицы
    printf("Введенная матрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", E[i][j]);
        }
        printf("\n");
    }

    // Обработка матрицы: подсчет отрицательных элементов в каждом столбце
    for (int j = 0; j < n; j++) {
        int col = 0; // Инициализация переменной col для подсчета отрицательных элементов в текущем столбце
        for (int i = 0; i < n; i++) {
            if (E[i][j] < 0) {
                col = col + 1; // Увеличение счетчика при обнаружении отрицательного элемента
            }
        }
        // Замена элемента на главной диагонали на количество отрицательных элементов в столбце
        E[j][j] = col;
        printf("\nКоличество отрицательных элементов в %d столбце: %d", j + 1, col);
    }
    printf("\n");

    // Вывод измененной матрицы
    printf("Матрица после обработки:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", E[i][j]);
        }
        printf("\n");
    }

    return 0;
}
