#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

// Функція для підрахунку груп з трьох знаків оклику "!!!"
bool ContainsTripleExclamationC(const char* str) {
    size_t len = strlen(str);
    if (len < 3) return false;
    for (size_t i = 0; i < len - 2; ++i) {
        if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!') {
            return true;
        }
    }
    return false;
}

// Функція для заміни трійок знаків оклику "!!!" на "**"
char* ReplaceTripleExclamationC(char* str) {
    size_t len = strlen(str);
    if (len < 3) return str;

    char* tmp = (char*)malloc(len * 2 + 1); // Забезпечуємо достатньо місця для замін
    char* t = tmp;
    tmp[0] = '\0';

    size_t i = 0;
    while (i < len && str[i + 2] != 0) {
        if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!') {
            strcat(t, "**");
            t += 2;
            i += 3;
        }
        else {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    while (i < len) {
        *t++ = str[i++];
    }
    *t = '\0';

    strcpy(str, tmp);
    free(tmp);
    return str;
}

int main() {
    char str[101];
    printf("Enter string:\n");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; // Видалення символу нового рядка

    // Перевірка, чи містить рядок групу з трьох знаків оклику "!!!"
    bool containsTripleExclamation = ContainsTripleExclamationC(str);
    printf("Contains triple exclamation: %s\n", containsTripleExclamation ? "Yes" : "No");

    // Заміна трійок знаків оклику "!!!" на "**"
    char* dest = ReplaceTripleExclamationC(str);
    printf("Modified string: %s\n", dest);

    return 0;
}
