/*
Общие функции выполняющие тестовое задание
*/

#pragma once
#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

#define _USE_MATH_DEFINES

#define ALL_CURVES_MACRO
#define TEST_TASK_GENERAL_CONSTANS
#include "../../../headers.hpp"

using namespace std;
using namespace chrono;
using namespace Curves;
using namespace BasicCurves;

namespace TestTask {
    namespace ByBasicCurves {

        extern void Set_Curves(std::vector<Curve*>& curves);

        extern double Get_RandomReal(double min, double max);

        extern int Get_RandomInteger(int min, int max);

        extern void Show_CurvesByParameter(std::string&         buffer,
                                           std::vector<Curve*>& curves);

        extern void Output_PointAndTangetVectorOfCurve(std::string& buffer,
                                                       Point3D      point,
                                                       Vector3D     derivative);

        extern void Get_CirclesFromCurves(std::vector<Curve*>&  curves,
                                          std::vector<Circle*>& circles);

        extern void Show_Circles(std::string&          buffer,
                                 std::vector<Circle*>& circles);

    }  // namespace ByBasicCurves
}  // namespace TestTask