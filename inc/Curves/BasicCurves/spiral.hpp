/*
Описание спирали
Переопределяет виртуальные методы базового класса и реализует поля для установки
радиуса и шага
*/

#pragma once
#define BASIC_CURVES_MACRO
#define CURVE_MACRO
#include "../../headers.hpp"
#undef CURVE_MACRO
#undef BASIC_CURVES_MACRO

namespace Curves {
    namespace BasicCurves {

        class Spiral : public Curve {
          private:
            double radius;
            double stap;

          public:
            Spiral(double _radius, double _stap);
            Point3D Get_Point(double t_parameter) const override;
            Point3D Get_Derivative(double t_parameter) const override;
        };
    }  // namespace BasicCurves
}  // namespace Curves