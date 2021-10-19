#include "add.h"
#include "check.h"
#include "ln.h"
#include "rm.h"
#include "update.h"
#include <stdio.h>
#include <string.h>

char *FILE_NAME = "todo.md";

int CheckDataFile(char *fileName);

int main(int argc, char *argv[]) {

  CheckDataFile(FILE_NAME);

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

  if (strcmp(argv[1], "ch") == 0) {

    int result = changeDataState(FILE_NAME);
    printf("結果 : %d", result);
  }

  return 0;
}

//  ファイルが生成されているかチェックする
//  絶対0が返ってくるはず
int CheckDataFile(char *fileName) {
  //  読みこみで開く
  FILE *fp = fopen(fileName, "r");

  //  ファイルが存在していない場合は作成する
  if (fp == NULL) {
    fp = fopen(fileName, "w");
    fclose(fp);
  }

  return 0;
}
