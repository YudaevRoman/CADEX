/*
Описание спирали
Переопределяет виртуальные методы базового класса и реализует поля для установки
радиуса и шага
*/

#pragma once
#include "curve.hpp"

namespace Curves {

    class Spiral : public Curve {
      private:
        double radius;
        double stap;

      public:
        Spiral(double _radius, double _stap);
        void     To_String(std::string& buffer) const override;
        Point3D  Get_Point(double t_parameter) const override;
        Vector3D Get_TangentVector(double t_parameter) const override;
        double   Get_Radius() const;
        double   Get_Stap() const;
    };

}  // namespace Curves