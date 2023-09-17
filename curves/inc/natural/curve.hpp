/*
Описание базового класса кривых
Данный класс является полностью абстрактным, поскольку он лишь описывает
требуемые в реализации методы для классов наследников
*/

#pragma once
#define CURVES_POINT3D
#define CURVES_VECTOR3D
#include "../../headers.hpp"

namespace Curves {
    namespace Natural {

        class Curve {
          public:
            virtual Point3D  Get_Point(double t_parameter) const = 0;
            virtual Vector3D Get_TangentVector(double t_parameter) const;
        };

    }  // namespace Natural
}  // namespace Curves