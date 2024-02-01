#include <stdio.h>
#include <stdlib.h>

int main() {
    // Переменные для отслеживания длины текущего слова и количества слов на одну букву
    int length = 0;
    int k = 0;

    // Массив для хранения введенной строки и переменная для введенной буквы
    char str[150];
    char a;

    // Ввод строки с клавиатуры
    printf("Введите строку: ");
    fgets(str, 149, stdin);
    printf("\n%s\n", str); // Вывод введенной строки

    // Ввод буквы с клавиатуры
    printf("Введите букву: ");
    scanf("%c", &a);

    // Вывод слов, состоящих из одной введенной буквы
    printf("Слова на одну букву:\t");
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n') {
            // Если предыдущий символ текущего слова равен введенной букве
            if (str[i - length] == a) {
                k++; // Увеличиваем счетчик слов
                // Выводим слово, состоящее из одной буквы, и добавляем табуляцию
                for (int j = i - length; j < i; j++) {
                    printf("%c", str[j]);
                }
                printf("\t");
            }
            length = 0; // Сброс счетчика длины слова
        } else {
            length++; // Увеличение счетчика длины слова
        }
    }

    // Вывод статистики
    if (k != 0) {
        printf("\nКоличество слов на одну букву: %d", k);
    } else {
        printf("Нужных слов нет");
    }

    return 0;
}