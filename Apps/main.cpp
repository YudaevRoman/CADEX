#include <iostream>

#define TEST_TASK_BY_BASIC_CURVES
#define TEST_TASK_WITHOUT_OMP
#include "headers.hpp"

using namespace TestTask::ByBasicCurves;

int main() {

    char key;

    do {
        TestTask_WithOMP();
        std::cout << "If you want to finish, press 'n'\n";
        key = std::cin.get();
        std::cout << std::endl << std::endl;
    } while (key != 'n');

    system("pause");

    return 0;
}
