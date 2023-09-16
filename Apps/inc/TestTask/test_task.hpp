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
#include "Apps/headers.hpp"

using namespace Curves;
using namespace BasicCurves;

namespace TestTask {

    extern const int    MIN_CONTAINER_SIZE;
    extern const int    MAX_CONTAINER_SIZE;
    extern const double t_parameter;

    extern std::random_device rd;
    extern std::mt19937       gen;

    extern void TestTask();

    extern void   Set_Container(std::vector<Curve*>& container);
    extern double Get_RandomReal(double min, double max);
    extern int    Get_RandomInteger(int min, int max);

    extern void Show_ContainerByParameter(std::string&         buffer,
                                          std::vector<Curve*>& container);
    extern void Output_Curves(std::string& buffer, Point3D point,
                              Vector3D derivative);

    extern void Get_CircleFromContainer(std::vector<Curve*>&  container,
                                        std::vector<Circle*>& circles);

    extern void Show_SumRadius(std::string&          buffer,
                               std::vector<Circle*>& circles);

}  // namespace TestTask