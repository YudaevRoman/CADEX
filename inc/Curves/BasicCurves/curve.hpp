/*
Описание базового класса кривых
Данный класс является полностью абстрактным, поскольку он лишь описывает
требуемые в реализации методы для классов наследников
*/

#pragma once
#define POINT3D_MACRO
#define VECTOR3D_MACRO
#include "../../headers.hpp"

namespace Curves {
    namespace BasicCurves {

        class Curve {
          public:
            virtual Point3D  Get_Point(double t_parameter) const = 0;
            virtual Vector3D Get_TangentVector(double t_parameter) const;
        };
    }  // namespace BasicCurves
}  // namespace Curves