/*
Описание структуры трёхмерного вектора
*/

#pragma once
#define CURVES_POINT3D
#include "../../headers.hpp"

namespace Curves {

    struct Vector3D {
      public:
        Point3D one;
        Point3D two;
    };
}  // namespace Curves