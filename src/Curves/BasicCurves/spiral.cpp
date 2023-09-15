
#include "../../../inc/Curves/BasicCurves/spiral.hpp"

#include <cmath>
#include <stdexcept>

#define LIMITING_COEFFICIENTS_MACRO
#define BASIC_CURVES_MACRO
#define SPIRAL_MACRO
#include "../../../inc/headers.hpp"
#undef SPIRAL_MACRO
#undef BASIC_CURVES_MACRO
#undef LIMITING_COEFFICIENTS_MACRO

namespace Curves {

    namespace BasicCurves {

        Spiral::Spiral(double _radius, double _stap) {
            if (_radius <= MIN_RADIUS_FOR_SPIRAL ||
                _radius >= MAX_RADIUS_FOR_SPIRAL) {
                throw std::invalid_argument("Invalid radius\n");
            }
            if (_stap <= MIN_STAP_FOR_SPIRAL || _stap >= MAX_STAP_FOR_SPIRAL) {
                throw std::invalid_argument("Invalid stap\n");
            }

            radius = _radius;
            stap   = _stap;
        }

        Point3D Spiral::Get_Point(double t_parameter) const {
            return {radius * std::cos(t_parameter),
                    radius * std::sin(t_parameter), stap * t_parameter};
        }

        Point3D Spiral::Get_Derivative(double t_parameter) const {
            return {-radius * std::sin(t_parameter),
                    radius * std::cos(t_parameter), stap};
        }

    }  // namespace BasicCurves
}  // namespace Curves