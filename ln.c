#include "ln.h"
#include <stdio.h>
#include <stdlib.h>

int showData(char *fileName) {
  //ファイル構造体へのポインタを宣言
  FILE *fp;
  char str[256][256]; //  1行の最高文字数(バイト数)
  int count = 0;

  //  w+ : 「書き込み」と「読み込み」モード
  //ファイル名は自分でつけたファイル名を書いてください
  fp = fopen(fileName, "r");

  //ファイルオープンに失敗したとき
  if (fp == NULL) {
    //失敗を表示し終了
    printf("ファイルオープン失敗\n");
    return -1;
  }

  //  ファイルの中身をすべて表示
  //  1:１行の文字列を入れる変数、2:1行の読み込むバイト数、3:ファイルのポインタ
  while (fgets(str[count], 256, fp) != NULL) {
    printf("%s", str[count]);
  }

  //  ファイルを閉じる
  fclose(fp);

  return 0;
}
