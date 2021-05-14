#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char value1[128]; strcpy(value1, argv[1]);

    int inputLen = strlen(value1);
    char unique[inputLen + 1];
    int found, foundCount = 0;

    for (int i = 0; i < inputLen; i++) {
        found = 0;
        for (int j = 0; j < i; j++) {
            if (value1[i] == unique[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unique[foundCount++] = value1[i];
        }
    }
    unique[foundCount] = '\0';

    int occurrences[foundCount - 1];
    for (int i = 0; i < foundCount - 1; i++) {
        occurrences[i] = 0;
    }

    for (int i = 0; i < foundCount - 1; i++) {
        for (int j = 0; j < inputLen; j++) {
            if (unique[i] == value1[j]) {
                occurrences[i]++;
            }
        }
    }

    int max = -1, maxIndex = -1;
    for (int i = 0; i < foundCount - 1; i++) {
        if (occurrences[i] > max) {
            max = occurrences[i];
            maxIndex = i;
        }
    }
    printf("%c\n", unique[maxIndex]);
}
