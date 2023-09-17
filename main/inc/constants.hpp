/*
Общие константы тестового задания
*/

#pragma once
#include <random>

extern const double t_parameter;

extern std::mt19937& Get_Generator();

extern int Get_MinContainerSize();

extern int Get_MaxContainerSize();

extern void Set_MinContainerSize(int min);

extern void Set_MaxContainerSize(int max);
