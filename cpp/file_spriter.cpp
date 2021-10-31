#include "file_spriter.hpp"
#include <cstring>
#include <iostream>

using namespace std;

FileSpritter::FileSpritter(const char *const data, int size) : m_row_count(0) {
    m_row_count = 0;

    //  改行数のカウント
    for (int i = 0; i < size; ++i) {
        if (data[i] == '\n') {
            ++m_row_count;
        }
    }

    //  改行でスプリット
    m_sprit_data[m_row_count];

    int bufsize = 1;
    int offset = 0;
    char *buf = new char[bufsize];

    m_row_count = 0;

    for (int i = 0; i < size; ++i) {
        if (data[i] == '\n') {
            m_sprit_data[m_row_count] = buf;
            m_sprit_data[m_row_count][bufsize - 1] = '\0'; //  末尾にNULL文字を挿入
            ++m_row_count;
            offset = i + 1;
            bufsize = 1;
            buf = new char[1];
            continue;
        }

        //  データの追加
        buf[i - offset] = data[i];

        //  配列を拡張
        //  改行が来たときにNULL文字を入れるために改行前に１バイト多く確保するために最後に処理している
        ++bufsize;
        char *newBuf = new char[bufsize];
        std::memcpy(newBuf, buf, bufsize);
        delete[] buf;
        buf = newBuf;
    }

    delete[] buf;
}

char *FileSpritter::get_sprit_data(int rowCount) const {
    return m_sprit_data[rowCount];
}

int FileSpritter::get_row_count() const {
    return m_row_count;
}
