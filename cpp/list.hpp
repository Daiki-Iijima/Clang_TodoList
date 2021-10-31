#ifndef LIST_HPP_
#define LIST_HPP_

class List {
  public:
    //  コンストラクタ
    List(class Input const &input);

    //  一覧の表示
    void Show();

  private:
    const class Input &m_input;
};

#endif
