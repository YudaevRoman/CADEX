/*
Функции выполняющие тестовое задание без применения OpenMP
*/

#pragma once
#include <memory>
#include <string>
#include <vector>

#include "../../curves/inc/circle.hpp"

extern void Show_SumRadius_NotOMP(
    std::string& buffer, std::vector<std::shared_ptr<Curves::Circle>>& circles);
    
extern void Example_NotOMP();