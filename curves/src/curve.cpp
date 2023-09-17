#include "../inc/curve.hpp"

namespace Curves {

    Vector3D Curve::Get_TangentVector(double t_parameter) const {
        return {
            Get_Point(t_parameter), {0, 0, 0}
        };
    }

}  // namespace Curves