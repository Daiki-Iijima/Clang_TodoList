#include <stdio.h>  //  これは基本必要
#include <string.h> //  strlenで使用する

char *FILE_NAME = "todo.md";
const int BUF_SIZE = 1024;

int getLastCount(char *fileName);

int main(int argc, char *argv[]) {
  //ファイル構造体へのポインタを宣言
  FILE *fp;

  // 01.cppを読み込みモードで開く
  //ファイル名は自分でつけたファイル名を書いてください
  fp = fopen(FILE_NAME, "a");

  //ファイルオープンに失敗したとき
  if (fp == NULL) {
    //失敗を表示し終了
    printf("ファイルオープン失敗\n");
    return -1;
  }

  int count = getLastCount(FILE_NAME);
  // printf("%d", count);

  //  文字列としてファイルポインタに設定されているファイルに書き込む
  //  戻り地は書き込み成功した文字数
  int result = fprintf(fp, "%d. [ ] %s\n", count + 1, argv[1]);

  if (result == strlen(argv[1])) {
    printf("登録失敗");
  }

  //  ファイルを閉じる
  fclose(fp);
  return 0;
}

int getLastCount(char *fileName) {
  FILE *fp;
  char buf[BUF_SIZE];
  int line = 0;

  fp = fopen(fileName, "r");

  while (fgets(buf, BUF_SIZE, fp)) {
    line++;
  }

  return line;
}
