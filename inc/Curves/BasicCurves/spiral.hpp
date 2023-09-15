/*
Описание спирали
Переопределяет виртуальные методы базового класса и реализует поля для установки
радиуса и шага
*/

#pragma once
#include "curve.hpp"

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