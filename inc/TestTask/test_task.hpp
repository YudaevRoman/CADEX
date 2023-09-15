/*
Функции выполняющие тестовое задание
*/

#pragma once
#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

#define _USE_MATH_DEFINES

#define ALL_CURVES_MACRO
#include "../../inc/headers.hpp"

using namespace Curves;
using namespace BasicCurves;

namespace TestTask {

    extern const int    MIN_CONTAINER_SIZE;
    extern const int    MAX_CONTAINER_SIZE;
    extern const double parameter_t;

    extern std::random_device rd;
    extern std::mt19937       gen;

    extern void Test_Task();

    extern void   Set_Container(std::vector<Curve*>& container);
    extern double Get_Random_Real(double min, double max);
    extern int    Get_Random_Integer(int min, int max);

    extern void Show_Container_By_Parameter(std::string&         buffer,
                                            std::vector<Curve*>& container);
    extern void Output_Curves(std::string& buffer, Point3D point,
                              Point3D derivative);

    extern void Get_Circle_From_Container(std::vector<Curve*>&  container,
                                          std::vector<Circle*>& circles);

    extern void Show_Sum_Radius(std::string&          buffer,
                                std::vector<Circle*>& circles);

}  // namespace TestTask