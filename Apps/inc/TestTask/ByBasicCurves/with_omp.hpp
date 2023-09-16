/*
Функции выполняющие тестовое задание с применением OpenMP
*/

#pragma once
#include <omp.h>

#define TEST_TASK_GENERAL
#include "../../../headers.hpp"

namespace TestTask {
    namespace ByBasicCurves {

        extern void Show_SumRadius_WithOMP(std::string&          buffer,
                                           std::vector<Circle*>& circles);
        extern void TestTask_WithOMP();

    }  // namespace ByBasicCurves
}  // namespace TestTask