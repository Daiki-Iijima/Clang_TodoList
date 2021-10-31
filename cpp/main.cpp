#include "file_spriter.hpp"
#include "input.hpp"
#include "input_console.hpp"
#include "input_file.hpp"
#include "list.hpp"
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

void ShowList() {
    //  ファイルを読み込む
    InputFile fileInput;
    fstream file;
    file.open("test.txt", ios::in);

    if (!file.is_open()) {
        cout << "ファイルが開けませんでした" << endl;
        return;
    }

    file >> fileInput;

    file.close();

    FileSpritter fileSpriter(fileInput.get_data(), fileInput.get_size());

    for (int i = 0; i < fileSpriter.get_row_count(); ++i) {
        cout << i << ":" << fileSpriter.get_sprit_data(i) << endl;
    }
}

int main() {
    //  コンソールから入力を取得
    InputConsole inputConsole;
    cin >> inputConsole;

    char inputChar = inputConsole.get_data()[0];

    if (inputChar == 'L') {
        ShowList();
    }
    if (inputChar == 'A') {
        //  ファイルを読み込む
        InputFile fileInput;
        fstream file;
        file.open("test.txt", ios::out | ios::app);

        if (!file.is_open()) {
            cout << "ファイルが開けませんでした" << endl;
            return 1;
        }

        InputConsole ic;
        cin >> ic;
        file << ic.get_data() << endl;

        file.close();
    }
    if (inputChar == 'C' || inputChar == 'D') {
        ShowList();

        //  ファイルを読み込む
        InputFile fileInput;
        fstream readfile;
        readfile.open("test.txt", ios::in);

        if (!readfile.is_open()) {
            cout << "ファイルが開けませんでした" << endl;
            return 1;
        }

        readfile >> fileInput;

        readfile.close();

        ofstream file;
        file.open("test.txt", ios::out);
        if (!file.is_open()) {
            cout << "ファイルが開けませんでした" << endl;
            return 1;
        }

        FileSpritter fileSpriter(fileInput.get_data(), fileInput.get_size());

        cout << "消去する番号を入力してください" << endl;
        InputConsole ic;
        cin >> ic;

        int no = ic.get_data()[0] - '0';

        for (int i = 0; i < fileSpriter.get_row_count(); ++i) {
            if (no == i) {
                continue;
            }
            file << fileSpriter.get_sprit_data(i);
            //  最後の行改行は入れない
            if (i != fileSpriter.get_row_count()) {
                file << endl;
            }
        }

        file.close();

        ShowList();
    }

    return 0;
}
