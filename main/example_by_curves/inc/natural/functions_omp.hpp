/*
Функции выполняющие тестовое задание с применением OpenMP
*/

#pragma once
#include <memory>

#define EXAMPLE_BY_CURVES_NATURAL
#define EXAMPLE_FUNCTIONS
#include "../../../headers.hpp"

namespace ExampleByCurves {
    namespace Natural {

        extern void Show_SumRadius_OMP(
            std::string& buffer, std::vector<std::shared_ptr<Circle>>& circles);
        extern void Example_OMP();

    }  // namespace Natural
}  // namespace ExampleByCurves