
#define BASIC_CURVES_MACRO
#define CURVE_MACRO
#include "../../../inc/headers.hpp"

namespace Curves {

    namespace BasicCurves {
        Vector3D Curve::Get_Derivative(double t_parameter) const {
            return {
                Get_Point(t_parameter), {0, 0, 0}
            };
        }

    }  // namespace BasicCurves
}  // namespace Curves