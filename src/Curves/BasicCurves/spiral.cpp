#include <cmath>
#include <stdexcept>

#define LIMITING_COEFFICIENTS_MACRO
#define BASIC_CURVES_MACRO
#define SPIRAL_MACRO
#include "../../../inc/headers.hpp"

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

        Vector3D Spiral::Get_TangentVector(double t_parameter) const {
            Vector3D vec = Curve::Get_TangentVector(t_parameter);
            vec.two.x    = vec.one.x - radius * std::sin(t_parameter);
            vec.two.y    = vec.one.y + radius * std::cos(t_parameter);
            vec.two.z    = vec.one.z + stap;
            return vec;
        }

        double Spiral::Get_Radius() const {
            return radius;
        }

        double Spiral::Get_Stap() const {
            return stap;
        }

    }  // namespace BasicCurves
}  // namespace Curves