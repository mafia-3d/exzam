#include <stdio.h>
#include <string.h>

int main() {
    // Программа на языке C для определения максимального и минимального слова и их номеров в символьной строке.

    char input_string[100];  // \\ Переменная для хранения введенной строки, предполагается, что строка не более 100 символов.
    printf("Введите строку: ");
    fgets(input_string, sizeof(input_string), stdin);

    char max_word[20] = "", min_word[20] = "";  // \\ Переменные для хранения максимального и минимального слова, предполагается, что слова не более 20 символов.
    int max_word_number = 1, min_word_number = 1;  // \\ Переменные для хранения номеров максимального и минимального слова.

    int current_word_number = 1;  // \\ Счетчик номера текущего слова.

    for (int i = 0; input_string[i] != '\0'; i++) {
        char current_word[20];  // \\ Переменная для хранения текущего слова, предполагается, что слово не более 20 символов.
        int k = 0;  // \\ Счетчик символов в текущем слове.

        // Формирование текущего слова
        while (input_string[i] != ' ' && input_string[i] != '\n' && input_string[i] != '\0') {
            current_word[k++] = input_string[i++];  // \\ Записываем символ в текущее слово.
        }

        current_word[k] = '\0';  // \\ Завершаем текущее слово нулевым символом.

        // Проверка текущего слова и обновление максимального и минимального
        if (k > 0) {  // \\ Проверяем, что слово не пустое
            if (strlen(current_word) > strlen(max_word)) {
                strcpy(max_word, current_word);  // \\ Копирование найденного слова в переменную max_word.
                max_word_number = current_word_number;  // \\ Запись номера максимального слова.
            } else if (strlen(current_word) < strlen(min_word) || strlen(min_word) == 0) {
                strcpy(min_word, current_word);  // \\ Копирование найденного слова в переменную min_word.
                min_word_number = current_word_number;  // \\ Запись номера минимального слова.
            }
        }

        // Пропуск пробела, если есть
        if (input_string[i] == ' ') {
            current_word_number++;  // \\ Увеличиваем счетчик номера слова.
        }
    }

    // Вывод результатов
    printf("Исходная строка: %s", input_string);
    printf("Максимальное слово: %s\n", max_word);
    printf("Номер максимального слова: %d\n", max_word_number);
    printf("Минимальное слово: %s\n", min_word);
    printf("Номер минимального слова: %d\n", min_word_number);

    return 0;
}

