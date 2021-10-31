#include "input.hpp"
#include "list.hpp"
#include <iostream>

List::List(Input const &input) : m_input(input) {}

void List::Show() {
    char *data = m_input.get_data();
    for (int i = 0; i < m_input.get_size(); ++i) {
        std::cout << data[i] << std::endl;
    }
}
