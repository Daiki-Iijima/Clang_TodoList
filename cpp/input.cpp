#include "input.hpp"
#include <cstring>
#include <ios>

Input::Input() : m_data(nullptr), m_size(1) {}

Input::~Input() {
    delete[] m_data;
}

//  生データの取得
char *Input::get_data() const {
    return m_data;
}
const size_t &Input::get_size() const {
    return m_size;
}

std::istream &operator>>(std::istream &instr, Input &input) {

    //  最初は1個の文字列を持つ配列を確保
    input.m_data = new char[input.m_size];

    for (;;) {
        //  読みとリ開始
        char data = instr.get();

        //  読みとリ終了のチェック
        //  継承先で設定しているはず
        if (input.CheckEnd(data)) {
            break;
        }

        //  データの追加
        input.m_data[input.m_size - 1] = data;
        //  現在確保しているメモリ+1の配列を確保
        ++input.m_size;
        char *newData = new char[input.m_size];
        //  データの移動
        memcpy(newData, input.m_data, input.m_size);
        //  前使っていたメモリは開放
        delete[] input.m_data;
        //  再取得した配列を設定
        input.m_data = newData;
    }

    //  終端文字を追加
    input.m_data[input.m_size] = '\0';

    return instr;
}
