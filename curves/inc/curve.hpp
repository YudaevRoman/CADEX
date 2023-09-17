/*
Описание базового класса кривых
Данный класс является полностью абстрактным, поскольку он лишь описывает
требуемые в реализации методы для классов наследников
*/

#pragma once
#include <string>

#include "vector3d.hpp"

namespace Curves {

    class Curve {
      public:
        virtual void     To_String(std::string& buffer) const = 0;
        virtual Point3D  Get_Point(double t_parameter) const  = 0;
        virtual Vector3D Get_TangentVector(double t_parameter) const;
    };

}  // namespace Curves