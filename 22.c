#include <stdio.h>
#include <string.h>

int main() {
    // Объявление переменных
    char input[1000];  // Входная строка
    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);

    // Убираем символ новой строки, который добавляется функцией fgets
    input[strcspn(input, "\n")] = '\0';

    char *maxAWord = NULL;  // Слово с максимальным количеством букв 'a'
    int maxACount = 0;      // Максимальное количество букв 'a' в слове
    int wordNumber = -1;    // Номер слова с максимальным количеством букв 'a'

    // Разбиваем строку на слова
    char *token = strtok(input, " ");
    int currentWordNumber = 0;  // Текущий номер обрабатываемого слова

    // Обходим каждое слово
    while (token != NULL) {
        int count = 0;  // Количество букв 'a' в текущем слове
        // Подсчет количества букв 'a' в слове
        for (int i = 0; token[i] != '\0'; i++) {
            if (token[i] == 'a' || token[i] == 'A') {
                count++;
            }
        }

        // Сравниваем с предыдущими значениями
        if (count > maxACount) {
            maxACount = count;
            maxAWord = token;
            wordNumber = currentWordNumber;
        }

        // Получаем следующее слово
        token = strtok(NULL, " ");
        currentWordNumber++;
    }

    // Вывод результатов, включая исходную строку
    printf("Исходная строка: %s\n", input);
    if (maxAWord != NULL) {
        printf("Найденное слово: %s\n", maxAWord);
        printf("Номер слова: %d\n", wordNumber + 1); // Увеличиваем на 1, так как счет начинается с 0
        printf("Количество букв 'a' в слове: %d\n", maxACount);
    } else {
        printf("В строке нет слов с буквой 'a'.\n");
    }

    return 0;
}

