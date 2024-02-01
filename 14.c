#include <stdio.h>
#include <string.h>

int main() {


    // Массив для хранения введенной строки
    char input[1000];

    // Массив для хранения текущего слова
    char word[100];

    // Счетчик коротких слов
    int shortWordCount = 0;

    // Ввод символьной строки с клавиатуры
    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);

    // Вывод исходной строки
    printf("Исходная строка: %s", input);

    // Разбор строки и подсчет коротких слов
    for (int i = 0, j = 0; i <= strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '\0' || input[i] == '\n') {
            // Проверка длины текущего слова
            if (j < 4 && j > 0) {
                // Вывод короткого слова
                printf("Короткое слово: %s\n", word);
                shortWordCount++;
            }
            // Обнуление текущего слова
            memset(word, 0, sizeof(word));
            // Сброс счетчика символов в слове
            j = 0;
        } else {
            // Заполнение текущего слова
            word[j++] = input[i];
        }
    }

    // Вывод количества коротких слов
    if (shortWordCount == 0) {
        printf("Нет слов длиной менее 4 символов.\n");
    } else {
        printf("Количество коротких слов: %d\n", shortWordCount);
    }

    return 0;
}

