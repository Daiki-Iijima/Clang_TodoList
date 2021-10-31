#ifndef STRING_HPP_
#define STRING_HPP_

#include <iostream>

//  既存のstringライブラリのように動的に配列を拡張するように作成したinputクラス
class Input {
  public: //  base
    //  コンストラクタ
    Input();
    //  デストラクタ
    virtual ~Input();
    //  stream入力演算子のオーバーロード
    //  入力された値のchar型配列とサイズを取得する
    friend std::istream &operator>>(std::istream &instr, Input &input);

  protected:
    //  読みとリが終了したかチェックする
    virtual bool CheckEnd(const char &data) = 0;

  public: //  データの取得
    char *get_data() const;
    const size_t &get_size() const;

  private:
    //  入力されたデータ
    char *m_data;
    //  データサイズ
    size_t m_size;
};

#endif
