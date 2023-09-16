/*
Описание эллипса
Переопределяет виртуальные методы базового класса и реализует поля для установки
раддиусов по оси абсцисс и ординат
*/

#pragma once
#define BASIC_CURVES_MACRO
#define CURVE_MACRO
#include "../../../headers.hpp"

namespace Curves {

    namespace BasicCurves {

        class Ellipse : public Curve {
          private:
            double radius_by_x;
            double radius_by_y;

          public:
            Ellipse(double _radius_by_x, double _radius_by_y);
            Point3D  Get_Point(double t_parameter) const override;
            Vector3D Get_TangentVector(double t_parameter) const override;
            double   Get_RadiusByX() const;
            double   Get_RadiusByY() const;
        };
    }  // namespace BasicCurves
}  // namespace Curves