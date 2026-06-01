#include <stdbool.h>

bool isValid(char * s) {
    int total = 0;
    char a[10005];
    for (int i = 0; s[i] != '\0'; i++) {
        char b = s[i];
        if (b == '(' || b == '{' || b == '[') {
            a[total] = b;
            total++;
        } else {
            if (total == 0) {
                return false;
            }
            char c = a[total - 1];

            if ((b == ')' && c == '(') || (b == '}' && c == '{') || (b == ']' && c == '[')) {
                total--;
            } else {
                return false;
            }
        }
    }
    return total == 0;
}