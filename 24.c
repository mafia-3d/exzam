#include <stdio.h>
#include <ctype.h>

int main() {
    char inputString[1000]; // массив для хранения введенной строки
    int vowelStartCount = 0; // счетчик слов, начинающихся на гласную букву
    int insideWord = 0; // флаг, указывающий, находится ли программа внутри слова

    // Ввод строки
    printf("Введите строку: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Вывод исходной строки
    printf("\nИсходная строка: %s\n", inputString);

    // Поиск слов, начинающихся на гласную букву
    printf("Слова, начинающиеся на гласную букву:\n");

    for (int i = 0; inputString[i] != '\0'; i++) {
        // Проверка, является ли текущий символ буквой
        if (isalpha(inputString[i])) {
            // Если программа вне слова
            if (!insideWord) {
                // Если текущая буква - гласная, увеличиваем счетчик и выводим слово
                if (inputString[i] == 'a' || inputString[i] == 'e' || inputString[i] == 'i' || inputString[i] == 'o' || inputString[i] == 'u' ||
                    inputString[i] == 'A' || inputString[i] == 'E' || inputString[i] == 'I' || inputString[i] == 'O' || inputString[i] == 'U') {
                    vowelStartCount++;
                    insideWord = 1;
                    printf("%c", inputString[i]);
                }
            } else {
                // Если программа внутри слова, продолжаем выводить буквы слова
                printf("%c", inputString[i]);
            }
        } else {
            // Если текущий символ - не буква, программа вне слова
            if (insideWord) {
                // Если программа выходит из слова, выводим новую строку
                printf("\n");
            }
            insideWord = 0;
        }
    }

    // Вывод результата
    if (vowelStartCount == 0) {
        printf("Слов, начинающихся на гласную букву, не найдено.\n");
    } else {
        printf("Количество слов, начинающихся на гласную букву: %d\n", vowelStartCount);
    }

    return 0;
}

