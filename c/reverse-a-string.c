#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char value1[128]; strcpy(value1, argv[1]);

  int len = strlen(value1);
  char reversed[len + 1];
  for (int i = 0; i < len; i++) {
    reversed[i] = value1[len - i - 1];
  }
  reversed[len] = '\0';

  printf("%s", reversed);
}
