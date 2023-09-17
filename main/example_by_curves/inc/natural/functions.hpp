/*
Общие функции выполняющие тестовое задание
*/

#pragma once
#include <memory>
#include <string>
#include <vector>

#define CURVES_NATURAL
#define CURVES_ALL
#define EXAMPLE_GENERAL_CONSTANS
#include "../../../headers.hpp"

using namespace Curves;
using namespace Curves::Natural;

namespace ExampleByCurves {
    namespace Natural {

        extern void   Set_Curves(std::vector<std::shared_ptr<Curve>>& curves);
        extern double Get_RandomReal(double min, double max);
        extern int    Get_RandomInteger(int min, int max);

        extern void Output_PointAndTangetVectorOfCurve(std::string& buffer,
                                                       Point3D      point,
                                                       Vector3D     derivative);
        extern void Show_CurvesByParameter(
            std::string& buffer, std::vector<std::shared_ptr<Curve>>& curves);

        extern void Get_CirclesFromCurves(
            std::vector<std::shared_ptr<Curve>>&  curves,
            std::vector<std::shared_ptr<Circle>>& circles);

        extern void Sort_CirclesByParameter(
            std::vector<std::shared_ptr<Circle>>& circles);

        extern void Show_Circles(std::string&                          buffer,
                                 std::vector<std::shared_ptr<Circle>>& circles);

    }  // namespace Natural
}  // namespace ExampleByCurves