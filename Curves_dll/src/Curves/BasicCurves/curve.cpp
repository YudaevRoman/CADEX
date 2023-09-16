
#define BASIC_CURVES_MACRO
#define CURVE_MACRO
#include "../../../headers.hpp"

namespace Curves {

    namespace BasicCurves {
        Vector3D Curve::Get_TangentVector(double t_parameter) const {
            return {
                Get_Point(t_parameter), {0, 0, 0}
            };
        }

    }  // namespace BasicCurves
}  // namespace Curves