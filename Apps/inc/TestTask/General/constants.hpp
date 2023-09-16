/*
Общие функции выполняющие тестовое задание
*/

#pragma once
#include <cmath>
#include <random>

#define _USE_MATH_DEFINES

namespace TestTask {
    namespace ByBasicCurves {

        extern const double t_parameter;


        extern std::mt19937& Get_Generator();

        extern int  Get_MinContainerSize();
        extern int  Get_MaxContainerSize();
        extern void Set_MinContainerSize(int min);
        extern void Set_MaxContainerSize(int max);

    }  // namespace ByBasicCurves
}  // namespace TestTask