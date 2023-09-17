#include <cmath>
#include <stdexcept>

#define CURVES_LIMITATIONS
#define CURVES_NATURAL
#define CURVES_CIRCLE
#include "../../headers.hpp"

namespace Curves {
    namespace Natural {

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

        Vector3D Circle::Get_TangentVector(double t_parameter) const {
            Vector3D vec = Curve::Get_TangentVector(t_parameter);
            vec.two.x    = vec.one.x - radius * std::sin(t_parameter);
            vec.two.y    = vec.one.y + radius * std::cos(t_parameter);
            return vec;
        }

        double Circle::Get_Radius() const {
            return radius;
        }

    }  // namespace Natural
}  // namespace Curves