#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char value1[128]; strcpy(value1, argv[1]);

    char buffer[128];
    int sum = 0;
    int k = 0;
    for (int i = 0; i < 128; i++) {
        if (value1[i] == ',') {
            buffer[k] = '\0';
            sum += atoi(buffer);
            k = 0;
        } else {
            buffer[k++] = value1[i];
        }
    }
    buffer[k] = '\0';
    sum += atoi(buffer);
    printf("%d", sum);
}
