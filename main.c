#include "add.h"
#include "ln.h"
#include "rm.h"
#include "update.h"
#include <stdio.h>
#include <string.h>

char *FILE_NAME = "todo.md";

int main(int argc, char *argv[]) {

  if (strcmp(argv[1], "add") == 0) {

    int result = add(FILE_NAME, argv[2]);
    printf("結果 : %d", result);
  }

  if (strcmp(argv[1], "ln") == 0) {

    int result = showData(FILE_NAME);
    printf("結果 : %d", result);
  }

  if (strcmp(argv[1], "rm") == 0) {

    int result = removeData(FILE_NAME);
    printf("結果 : %d", result);
  }

  if (strcmp(argv[1], "up") == 0) {

    int result = updateData(FILE_NAME);
    printf("結果 : %d", result);
  }

  return 0;
}
