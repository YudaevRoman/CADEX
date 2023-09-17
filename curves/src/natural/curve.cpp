#define CURVES_NATURAL
#define CURVES_CURVE
#include "../../headers.hpp"

namespace Curves {
    namespace Natural {

        Vector3D Curve::Get_TangentVector(double t_parameter) const {
            return {
                Get_Point(t_parameter), {0, 0, 0}
            };
        }

    }  // namespace Natural
}  // namespace Curves