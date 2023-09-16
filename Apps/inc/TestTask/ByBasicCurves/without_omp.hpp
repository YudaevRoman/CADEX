/*
Функции выполняющие тестовое задание без применения OpenMP
*/

#pragma once
#define TEST_TASK_GENERAL
#include "../../../headers.hpp"

namespace TestTask {
    namespace ByBasicCurves {

        extern void Show_SumRadius_WithoutOMP(std::string&          buffer,
                                              std::vector<Circle*>& circles);
        extern void TestTask_WithoutOMP();

    }  // namespace ByBasicCurves
}  // namespace TestTask