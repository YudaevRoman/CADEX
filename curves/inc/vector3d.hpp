/*
Описание структуры трёхмерного вектора
*/

#pragma once
#include "point3d.hpp"

namespace Curves {

    struct Vector3D {
      public:
        Point3D one;
        Point3D two;
    };

}  // namespace Curves