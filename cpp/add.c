#include "add.h"
#include <stdio.h>
#include <string.h>

const int BUF_SIZE = 1024;

int add(char *fileName, const char *addStr) {
  //ファイル構造体へのポインタを宣言
  FILE *fp;

  //ファイル名は自分でつけたファイル名を書いてください
  fp = fopen(fileName, "a");

  //ファイルオープンに失敗したとき
  if (fp == NULL) {
    //失敗を表示し終了
    printf("ファイルオープン失敗\n");
    return -1;
  }

  int count = getLineCount(fileName);

  //  文字列としてファイルポインタに設定されているファイルに書き込む
  //  戻り地は書き込み成功した文字数
  unsigned int result = fprintf(fp, "%d. [ ] %s\n", count + 1, addStr);
  //  ファイルを閉じる
  fclose(fp);

  if (result == -1) {
    return 1;
  }

  return 0;
  ;
}

//  行数を取得する
int getLineCount(char *fileName) {
  FILE *fp;
  char buf[BUF_SIZE];
  int line = 0;

  fp = fopen(fileName, "r");

  while (fgets(buf, BUF_SIZE, fp)) {
    line++;
  }

  return line;
}
