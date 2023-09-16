/*
Общие функции выполняющие тестовое задание
*/

#pragma once
#include <cmath>
#include <random>

#define _USE_MATH_DEFINES

namespace TestTask {
    namespace ByBasicCurves {

        extern const int    MIN_CONTAINER_SIZE;
        extern const int    MAX_CONTAINER_SIZE;
        extern const double t_parameter;

        extern std::random_device rd;
        extern std::mt19937       gen;

    }  // namespace ByBasicCurves
}  // namespace TestTask