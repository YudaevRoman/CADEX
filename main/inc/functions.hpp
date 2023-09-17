/*
Общие функции выполняющие тестовое задание
*/

#pragma once
#include <memory>
#include <string>
#include <vector>

#include "../../curves/inc/circle.hpp"
#include "../../curves/inc/curve.hpp"
#include "../../curves/inc/ellipse.hpp"
#include "../../curves/inc/spiral.hpp"

extern void   Set_Curves(std::vector<std::shared_ptr<Curves::Curve>>& curves);

extern double Get_RandomReal(double min, double max);

extern int    Get_RandomInteger(int min, int max);

extern void Output_PointAndTangetVectorOfCurve(std::string&     buffer,
                                               Curves::Point3D  point,
                                               Curves::Vector3D derivative);
extern void Show_CurvesByParameter(
    std::string& buffer, std::vector<std::shared_ptr<Curves::Curve>>& curves);

extern void Get_CirclesFromCurves(
    std::vector<std::shared_ptr<Curves::Curve>>&  curves,
    std::vector<std::shared_ptr<Curves::Circle>>& circles);

extern void Sort_CirclesByParameter(
    std::vector<std::shared_ptr<Curves::Circle>>& circles);

extern void Show_Circles(std::string&                                  buffer,
                         std::vector<std::shared_ptr<Curves::Circle>>& circles);