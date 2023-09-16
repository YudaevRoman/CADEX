/*
Описание окружности
Переопределяет виртуальные методы базового класса и реализует поле для установки
радиуса
*/

#pragma once
#define BASIC_CURVES_MACRO
#define CURVE_MACRO
#include "../../../headers.hpp"

namespace Curves {
    namespace BasicCurves {

        class Circle : public Curve {
          private:
            double radius;

          public:
            Circle(double _radius);
            Point3D  Get_Point(double t_parameter) const override;
            Vector3D Get_TangentVector(double t_parameter) const override;
            double   Get_Radius() const;
        };
    }  // namespace BasicCurves
}  // namespace Curves