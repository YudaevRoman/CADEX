#include <cmath>
#include <stdexcept>

#define LIMITING_COEFFICIENTS_MACRO
#define BASIC_CURVES_MACRO
#define ELLIPSE_MACRO
#include "../../../inc/headers.hpp"


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

        Vector3D Ellipse::Get_Derivative(double t_parameter) const {
            Vector3D vec = Curve::Get_Derivative(t_parameter);
            vec.two.x    = vec.one.x - radius_by_x * std::sin(t_parameter);
            vec.two.y    = vec.one.y + radius_by_y * std::cos(t_parameter);
            return vec;
        }

        double Ellipse::Get_Radius_By_X() const {
            return radius_by_x;
        }

        double Ellipse::Get_Radius_By_Y() const {
            return radius_by_y;
        }

    }  // namespace BasicCurves
}  // namespace Curves