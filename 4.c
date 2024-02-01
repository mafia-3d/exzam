#include <stdio.h>

int main() {
    // Ввод размеров матрицы
    int n, m;  //  n - количество строк, m - количество столбцов
    printf("Введите количество строк (n): ");
    scanf("%d", &n);
    printf("Введите количество столбцов (m): ");
    scanf("%d", &m);

    // Инициализация матрицы
    float matrix[10][10];  //  matrix - матрица элементов типа float размером не более 10x10

    // Ввод элементов матрицы
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("Введите элемент [%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    // Поиск строки с максимальным количеством отрицательных элементов
    int max_neg_row = -1;  //  max_neg_row - номер строки с максимальным количеством отрицательных элементов
    int max_neg_count = -1;  //  max_neg_count - количество отрицательных элементов в строке

    for (int i = 0; i < n; ++i) {
        int neg_count = 0;
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] < 0) {
                neg_count++;
            }
        }
        if (neg_count > max_neg_count) {
            max_neg_count = neg_count;
            max_neg_row = i;
        }
    }

    // Поиск строки с максимальным количеством положительных элементов
    int max_pos_row = -1;  //  max_pos_row - номер строки с максимальным количеством положительных элементов
    int max_pos_count = -1;  //  max_pos_count - количество положительных элементов в строке

    for (int i = 0; i < n; ++i) {
        int pos_count = 0;
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] > 0) {
                pos_count++;
            }
        }
        if (pos_count > max_pos_count) {
            max_pos_count = pos_count;
            max_pos_row = i;
        }
    }

    // Обмен строк, если есть отрицательные и положительные элементы
    if (max_neg_count > 0 && max_pos_count > 0) {
        for (int j = 0; j < m; ++j) {
            float temp = matrix[max_neg_row][j];
            matrix[max_neg_row][j] = matrix[max_pos_row][j];
            matrix[max_pos_row][j] = temp;
        }

        // Вывод матрицы после обмена строк
        printf("\nМатрица после обмена строк:\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%.2f\t", matrix[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nОтрицательные или положительные элементы отсутствуют.\n");
    }

    return 0;
}

