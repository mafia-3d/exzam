#include <stdio.h>
#include <string.h>

int main() {
    // Максимальная длина вводимой строки
    #define MAX_LENGTH 100

    // Буфер для вводимой строки
    char input[MAX_LENGTH];

    // Буфер для временного слова при обработке строки
    char word[MAX_LENGTH];

    // Ввод строки с клавиатуры
    printf("Введите строку из слов, разделенных пробелами: ");
    fgets(input, sizeof(input), stdin);

    // Длина вводимой строки
    int len = strlen(input);

    // Текущий индекс в слове
    int index = 0;

    // Флаг, указывающий наличие слова длиной менее 5 символов
    int min = 0;

    // Печать исходной строки
    printf("Исходная строка: %s", input);

    // Печать заголовка для полученной последовательности слов
    printf("Полученная последовательность слов: ");

    // Обработка вводимой строки
    for (int i = 0; i <= len; i++) {
        // Если символ не пробел и не конец строки, добавляем символ в текущее слово
        if (input[i] != ' ' && input[i] != '\0' && input[i] != '\n') {
            word[index++] = input[i];
        } else {
            // Если текущее слово короткое, устанавливаем флаг
            if (index < 5) {
                min = 1;
            } else {
                // Печать слова
                printf("%.*s ", index, word);
            }

            // Сброс индекса и обнуление временного слова
            index = 0;
            memset(word, 0, sizeof(word));
        }
    }

    // Печать сообщения, если нет коротких слов
    if (!min) {
        printf("Нет слов длиной менее 5 символов.");
    }

    return 0;
}

