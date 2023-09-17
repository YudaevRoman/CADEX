/*
Функции выполняющие тестовое задание с применением OpenMP
*/

#pragma once
#include <memory>
#include <string>
#include <vector>

#include "../../curves/inc/circle.hpp"

extern void Show_SumRadius_OMP(
    std::string& buffer, std::vector<std::shared_ptr<Curves::Circle>>& circles);
    
extern void Example_OMP();