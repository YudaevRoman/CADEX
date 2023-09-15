#include "../../../inc/Curves/BasicCurves/circle.hpp"

#include <cmath>
#include <stdexcept>

#include "../../../inc/Curves/limiting_coefficients_of_curves.hpp"

namespace Curves {

    namespace BasicCurves {

        Circle::Circle(double _radius) {
            if (_radius <= MIN_RADIUS_FOR_CIRCLE ||
                _radius >= MAX_RADIUS_FOR_CIRCLE) {
                throw std::invalid_argument("Invalid radius\n");
            }
            radius = _radius;
        }

        Point3D Circle::Get_Point(double t_parameter) const {
            return {radius * std::cos(t_parameter),
                    radius * std::sin(t_parameter), 0};
        }

        Point3D Circle::Get_Derivative(double t_parameter) const {
            return {-radius * std::sin(t_parameter),
                    radius * std::cos(t_parameter), 0};
        }
    }  // namespace BasicCurves
}  // namespace Curves