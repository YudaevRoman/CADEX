#include "../inc/ellipse.hpp"

#include <cmath>
#include <stdexcept>

#include "../inc/limitations.hpp"


namespace Curves {

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

    void Ellipse::To_String(std::string& buffer) const {
        buffer.append("Type ellipse\n");
        buffer.append("Radius by X: ");
        buffer.append(std::to_string(Get_RadiusByX()));
        buffer.push_back('\n');
        buffer.append("Radius by Y: ");
        buffer.append(std::to_string(Get_RadiusByY()));
        buffer.push_back('\n');
    }

    Point3D Ellipse::Get_Point(double t_parameter) const {
        return {radius_by_x * std::cos(t_parameter),
                radius_by_y * std::sin(t_parameter), 0};
    }

    Vector3D Ellipse::Get_TangentVector(double t_parameter) const {
        Vector3D vec = Curve::Get_TangentVector(t_parameter);
        vec.two.x    = vec.one.x - radius_by_x * std::sin(t_parameter);
        vec.two.y    = vec.one.y + radius_by_y * std::cos(t_parameter);
        return vec;
    }

    double Ellipse::Get_RadiusByX() const {
        return radius_by_x;
    }

    double Ellipse::Get_RadiusByY() const {
        return radius_by_y;
    }


}  // namespace Curves