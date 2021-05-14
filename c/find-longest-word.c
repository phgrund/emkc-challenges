#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void appendToString(char *dest, const char *source) {
    int i, j;
    int sourceLength = strlen(source);
    // printf("append '%s' to '%s' = ", source, dest);
    for (i = 0, j = strlen(dest); i < sourceLength; i++, j++) {
        dest[j] = source[i];
    }
    dest[j] = '\0';
    // printf("%s\n", dest);
}

int main(int argc, char **argv) {
    char value1[128]; strcpy(value1, argv[1]);

    char inputLength = strlen(value1);

    char output[inputLength];
    char buffer[inputLength];

    int k = 0;
    int max = -1;

    // i = iterates over the input string
    // j = iterates over the buffer string
    // k = iterates over the output string

    for (int i = 0, j = 0; i <= inputLength; i++) {
        char val = value1[i];
        if (val == ',' || val == '\0') {
            if (j > max) {
                output[0] = '\0';
                appendToString(output, buffer);
                max = k = j;
            } else if (j == max) {
                output[k++] = ',';
                output[k] = '\0';
                k += j;
                appendToString(output, buffer);
            }
            j = 0;
            buffer[0] = '\0';
        } else if (val != ' ') {
            buffer[j++] = tolower(val);
        }
    }

    printf("%s", output);
}
