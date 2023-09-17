/*
Функции выполняющие тестовое задание без применения OpenMP
*/

#pragma once
#include <memory>

#define EXAMPLE_BY_CURVES_NATURAL
#define EXAMPLE_FUNCTIONS
#include "../../../headers.hpp"

namespace ExampleByCurves {
    namespace Natural {

        extern void Show_SumRadius_NotOMP(
            std::string& buffer, std::vector<std::shared_ptr<Circle>>& circles);
        extern void Example_NotOMP();

    }  // namespace Natural
}  // namespace ExampleByCurves