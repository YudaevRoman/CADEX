#include "../../../inc/Curves/BasicCurves/ellipse.hpp"

#include <cmath>
#include <stdexcept>

#include "../../../inc/Curves/limiting_coefficients_of_curves.hpp"

namespace Curves {

    namespace BasicCurves {

        Ellipse::Ellipse(double _radius_by_x, double _radius_by_y) {
            if (_radius_by_x <= MIN_RADIUS_BY_X_FOR_ELLIPSE ||
                _radius_by_x >= MAX_RADIUS_BY_X_FOR_ELLIPSE) {
                throw std::invalid_argument("Invalid radius by x\n");
            }
            if (_radius_by_y <= MIN_RADIUS_BY_Y_FOR_ELLIPSE ||
                _radius_by_y >= MAX_RADIUS_BY_Y_FOR_ELLIPSE) {
                throw std::invalid_argument("Invalid radius by y\n");
            }

            radius_by_x = _radius_by_x;
            radius_by_y = _radius_by_y;
        }

        Point3D Ellipse::Get_Point(double t_parameter) const {
            return {radius_by_x * std::cos(t_parameter),
                    radius_by_y * std::sin(t_parameter), 0};
        }

        Point3D Ellipse::Get_Derivative(double t_parameter) const {
            return {-radius_by_x * std::sin(t_parameter),
                    radius_by_y * std::cos(t_parameter), 0};
        }
    }  // namespace BasicCurves
}  // namespace Curves