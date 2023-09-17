/*
Описание окружности
Переопределяет виртуальные методы базового класса и реализует поле для установки
радиуса
*/

#pragma once
#include "curve.hpp"

namespace Curves {

    class Circle : public Curve {
      private:
        double radius;

      public:
        Circle(double _radius);
        void     To_String(std::string& buffer) const override;
        Point3D  Get_Point(double t_parameter) const override;
        Vector3D Get_TangentVector(double t_parameter) const override;
        double   Get_Radius() const;
    };

}  // namespace Curves