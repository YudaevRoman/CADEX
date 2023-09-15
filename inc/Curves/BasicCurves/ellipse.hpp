/*
Описание эллипса
Переопределяет виртуальные методы базового класса и реализует поля для установки
раддиусов по оси абсцисс и ординат
*/


#pragma once
#include "curve.hpp"

namespace Curves {

    namespace BasicCurves {

        class Ellipse : public Curve {
          private:
            double radius_by_x;
            double radius_by_y;

          public:
            Ellipse(double _radius_by_x, double _radius_by_y);
            Point3D Get_Point(double t_parameter) const override;
            Point3D Get_Derivative(double t_parameter) const override;
        };
    }  // namespace BasicCurves
}  // namespace Curves