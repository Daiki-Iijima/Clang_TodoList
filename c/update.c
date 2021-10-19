#include "update.h"
#include <stdio.h>
#include <stdlib.h>

int updateData(char *fileName) {
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
    count++;
  }

  //  ファイルを閉じる
  fclose(fp);

  //  消去する番号を要求
  char s[256];
  printf("更新したい項目番号を入力してください:");
  //  改行文字が最後に含まれる
  fgets(s, 256, stdin);

  char nStr[256];
  int charCount = 0;

  //  番号じゃなかった場合エラー
  for (int i = 0; i < 256; i++) {
    if (s[i] >= '0' && s[i] <= '9') { //  数字判定
      // printf("%cは数字です\n", s[i]);
      nStr[charCount] = s[i];
      charCount++;
    } else if (s[i] == '\n') { //  改行文字がきたら終了
      break;
    } else {
      printf("数字を入力してください");
    }
  }

  char updateText[256];

  //  変更する文字列の取得
  fgets(updateText, 256, stdin);

  //  文字列を数字に変換
  //  -1は配列で使用するので、1を0として扱いたいから
  int number = atoi(nStr) - 1;

  for (int i = 0; i < count; i++) {
    //  指定された行の場合
    if (i == number) {
      for (int j = 7; j < 256; j++) {
        str[i][j] = updateText[j - 7];
      }
    }
  }

  //  書き込み
  FILE *wFp;
  wFp = fopen(fileName, "w");

  //ファイルオープンに失敗したとき
  if (wFp == NULL) {
    //失敗を表示し終了
    printf("ファイルオープン失敗\n");
    return -1;
  }

  //  文字列としてファイルポインタに設定されているファイルに書き込む
  //  戻り地は書き込み成功した文字数
  for (int i = 0; i < count; i++) {
    fputs(str[i], wFp);
  }

  //  ファイルを閉じる
  fclose(fp);
  return 0;
}
