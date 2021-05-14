#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *arraySplit(char *string, char separator, int *countRef) {
    int count = 0;
    int k = 0;

    int size = 0;
    int stringLen = strlen(string);
    for (int i = 0; i < stringLen; i++) {
        if (string[i] == separator) size++;
    }
    size++;

    char buffer[strlen(string)];
    int *values = (int*) malloc(sizeof(int) * size);
    for (int i = 0; i < stringLen; i++) {
        if (string[i] == separator) {
            buffer[k] = '\0';
            values[count++] = atoi(buffer);
            k = 0;
        } else {
            buffer[k++] = string[i];
        }
    }
    buffer[k] = '\0';
    values[count] = atoi(buffer);
    *countRef = size;

    return values;
}

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleSort(int *arr, int size) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }
    } while (swapped);
}

int main(int argc, char **argv) {
    char value1[128]; strcpy(value1, argv[1]);

    int size;
    int *values;
    values = arraySplit(value1, ',', &size);

    bubbleSort(values, size);
    int i;
    for (i = 0; i < size - 1; i++) {
        printf("%d,", values[i]);
    }
    printf("%d", values[i]);
}
