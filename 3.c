#include <stdio.h>

#define MAX_SIZE 10

int main() {
    // Инициализация переменных
    int n, m;  // Размеры матрицы (число строк и столбцов)
    printf("Введите размеры матрицы (n m, где n, m <= %d): ", MAX_SIZE);
    scanf("%d %d", &n, &m);

    int matrix[MAX_SIZE][MAX_SIZE];  // Матрица

    // Ввод элементов матрицы
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Поиск столбца с максимальным количеством отрицательных элементов
    int maxNegColumn = -1, maxNegCount = 0;  // Столбец и количество отрицательных элементов
    for (int j = 0; j < m; ++j) {
        int negCount = 0;  // Счетчик отрицательных элементов

        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] < 0) {
                negCount++;
            }
        }

        if (negCount > maxNegCount) {
            maxNegCount = negCount;
            maxNegColumn = j;
        }
    }

    // Поиск столбца с максимальным количеством положительных элементов
    int maxPosColumn = -1, maxPosCount = 0;  // Столбец и количество положительных элементов
    for (int j = 0; j < m; ++j) {
        int posCount = 0;  // Счетчик положительных элементов

        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] > 0) {
                posCount++;
            }
        }

        if (posCount > maxPosCount) {
            maxPosCount = posCount;
            maxPosColumn = j;
        }
    }

    // Вывод исходной матрицы
    printf("Исходная матрица:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Вывод информации о столбцах
    if (maxNegColumn != -1) {
        printf("Столбец с максимальным количеством отрицательных элементов: %d, количество: %d\n", maxNegColumn + 1, maxNegCount);
    } else {
        printf("Нет столбцов с отрицательными элементами\n");
    }

    if (maxPosColumn != -1) {
        printf("Столбец с максимальным количеством положительных элементов: %d, количество: %d\n", maxPosColumn + 1, maxPosCount);
    } else {
        printf("Нет столбцов с положительными элементами\n");
    }

    // Обмен найденных столбцов и вывод измененной матрицы
    if (maxNegColumn != -1 && maxPosColumn != -1) {
        for (int i = 0; i < n; ++i) {
            int temp = matrix[i][maxNegColumn];
            matrix[i][maxNegColumn] = matrix[i][maxPosColumn];
            matrix[i][maxPosColumn] = temp;
        }

        printf("Полученная матрица после обмена столбцов:\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

