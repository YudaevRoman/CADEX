/*
Описание эллипса
Переопределяет виртуальные методы базового класса и реализует поля для установки
раддиусов по оси абсцисс и ординат
*/

#pragma once
#include "curve.hpp"

namespace Curves {

    class Ellipse : public Curve {
      private:
        double radius_by_x;
        double radius_by_y;

      public:
        Ellipse(double _radius_by_x, double _radius_by_y);
        void     To_String(std::string& buffer) const override;
        Point3D  Get_Point(double t_parameter) const override;
        Vector3D Get_TangentVector(double t_parameter) const override;
        double   Get_RadiusByX() const;
        double   Get_RadiusByY() const;
    };

}  // namespace Curves