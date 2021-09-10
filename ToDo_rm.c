#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  //ファイル構造体へのポインタを宣言
  FILE *fp;
  char str[256][256]; //  1行の最高文字数(バイト数)
  int count = 0;

  //  w+ : 「書き込み」と「読み込み」モード
  //ファイル名は自分でつけたファイル名を書いてください
  fp = fopen("todo.md", "r");

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

  //  文字列を数字に変換
  //  -1は配列で使用するので、1を0として扱いたいから
  int number = atoi(nStr) - 1;

  char writeStr[256][256]; //  書き込む配列
  char itoc[10];           //  番号を文字列にする
  int flag = 0;
  int c = 0; // 行数カウント

  //  指定された列を消去して詰める
  for (int i = 0; i < count; i++) {
    if (i == number) {
      flag = 1;
      continue;
    }

    c++; //  行数をインクリメント

    for (int j = 0; j < 256; j++) {
      if (flag == 1) {
        if (j == 0) {
          snprintf(itoc, 10, "%d", c);
          writeStr[i - 1][j] = itoc[0];
        } else {
          writeStr[i - 1][j] = str[i][j];
        }
      } else {
        if (j == 0) {
          snprintf(itoc, 10, "%d", c);
          writeStr[i][j] = itoc[0];
        } else {
          writeStr[i][j] = str[i][j];
        }
      }
    }
  }

  //  書き込み
  FILE *wFp;
  wFp = fopen("todo.md", "w");

  //ファイルオープンに失敗したとき
  if (wFp == NULL) {
    //失敗を表示し終了
    printf("ファイルオープン失敗\n");
    return -1;
  }

  //  文字列としてファイルポインタに設定されているファイルに書き込む
  //  戻り地は書き込み成功した文字数
  for (int i = 0; i < count; i++) {
    fputs(writeStr[i], wFp);
  }

  //  ファイルを閉じる
  fclose(fp);
  return 0;
}
