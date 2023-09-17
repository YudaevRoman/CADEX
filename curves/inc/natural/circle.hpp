/*
Описание окружности
Переопределяет виртуальные методы базового класса и реализует поле для установки
радиуса
*/

#pragma once
#define CURVES_NATURAL
#define CURVES_CURVE
#include "../../headers.hpp"

namespace Curves {
    namespace Natural {

        class Circle : public Curve {
          private:
            double radius;

          public:
            Circle(double _radius);
            Point3D  Get_Point(double t_parameter) const override;
            Vector3D Get_TangentVector(double t_parameter) const override;
            double   Get_Radius() const;
        };

    }  // namespace Natural
}  // namespace Curves