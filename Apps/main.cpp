#include <iostream>

#define TEST_TASK_MACRO
#include "Apps/headers.hpp"

int main() {

    char key;

    do {
        TestTask::TestTask();
        std::cout << "If you want to finish, press 'n'\n";
        std::cin >> key;
        std::cout << std::endl << std::endl;
    } while (key != 'n');

    system("pause");

    return 0;
}
