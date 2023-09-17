#include <algorithm>

#define EXAMPLE_BY_CURVES_NATURAL
#define EXAMPLE_FUNCTIONS
#include "../../../headers.hpp"

namespace ExampleByCurves {
    namespace Natural {

        double Get_RandomReal(double min, double max) {
            std::uniform_real_distribution dist(min, max);
            return dist(Get_Generator());
        }
        int Get_RandomInteger(int min, int max) {
            std::uniform_int_distribution dist(min, max);
            return dist(Get_Generator());
        }
        void Set_Curves(std::vector<std::shared_ptr<Curve>>& curves) {
            int containerSize = Get_RandomInteger(Get_MinContainerSize(),
                                                  Get_MaxContainerSize());
            curves.clear();
            curves.reserve(containerSize);
            for (int i = 0; i < containerSize; i++) {
                switch (Get_RandomInteger(1, 3)) {
                    case 1: {
                        curves.push_back(std::make_shared<Circle>(Circle(
                            Get_RandomReal(MIN_RADIUS_FOR_CIRCLE + ACCURACY,
                                           MAX_RADIUS_FOR_CIRCLE - ACCURACY))));
                        break;
                    }
                    case 2: {
                        curves.push_back(std::make_shared<Ellipse>(Ellipse(
                            Get_RandomReal(
                                MIN_RADIUS_BY_X_FOR_ELLIPSE + ACCURACY,
                                MAX_RADIUS_BY_X_FOR_ELLIPSE - ACCURACY),
                            Get_RandomReal(
                                MIN_RADIUS_BY_Y_FOR_ELLIPSE + ACCURACY,
                                MAX_RADIUS_BY_Y_FOR_ELLIPSE - ACCURACY))));
                        break;
                    }
                    case 3: {
                        curves.push_back(std::make_shared<Spiral>(Spiral(
                            Get_RandomReal(MIN_RADIUS_FOR_SPIRAL + ACCURACY,
                                           MAX_RADIUS_FOR_SPIRAL - ACCURACY),
                            Get_RandomReal(MIN_STAP_FOR_SPIRAL + ACCURACY,
                                           MAX_STAP_FOR_SPIRAL - ACCURACY))));
                        break;
                    }
                }
            }
        }

        void Output_PointAndTangetVectorOfCurve(std::string& buffer,
                                                Point3D      point,
                                                Vector3D     derivative) {
            buffer.append("Point: {");
            buffer.append(std::to_string(point.x));
            buffer.append(", ");
            buffer.append(std::to_string(point.y));
            buffer.append(", ");
            buffer.append(std::to_string(point.z));
            buffer.append("}\n");

            buffer.append("Tangent vector: one{");
            buffer.append(std::to_string(derivative.one.x));
            buffer.append(", ");
            buffer.append(std::to_string(derivative.one.y));
            buffer.append(", ");
            buffer.append(std::to_string(derivative.one.z));
            buffer.append("} two{");
            buffer.append(std::to_string(derivative.two.x));
            buffer.append(", ");
            buffer.append(std::to_string(derivative.two.y));
            buffer.append(", ");
            buffer.append(std::to_string(derivative.two.z));
            buffer.append("}\n\n");
        }
        void Show_CurvesByParameter(
            std::string& buffer, std::vector<std::shared_ptr<Curve>>& curves) {
            int     index = 0;
            Point3D point;
            Point3D derivative;

            std::shared_ptr<Circle>  circle;
            std::shared_ptr<Ellipse> ellipse;
            std::shared_ptr<Spiral>  spiral;

            buffer.append("\nShowing curves by parameter\n\n");

            for (std::shared_ptr<Curve> curve : curves) {
                index++;
                buffer.append(std::to_string(index));
                buffer.append(" curve\nType: ");

                circle = std::dynamic_pointer_cast<Circle>(curve);
                if (circle.get()) {
                    buffer.append("circle\n");

                    buffer.append("Radius: ");
                    buffer.append(std::to_string(circle->Get_Radius()));
                    buffer.push_back('\n');

                    Output_PointAndTangetVectorOfCurve(
                        buffer, circle->Get_Point(t_parameter),
                        circle->Get_TangentVector(t_parameter));
                    continue;
                }

                ellipse = std::dynamic_pointer_cast<Ellipse>(curve);
                if (ellipse.get()) {
                    buffer.append("ellipse\n");

                    buffer.append("Radius by X: ");
                    buffer.append(std::to_string(ellipse->Get_RadiusByX()));
                    buffer.push_back('\n');
                    buffer.append("Radius by Y: ");
                    buffer.append(std::to_string(ellipse->Get_RadiusByY()));
                    buffer.push_back('\n');

                    Output_PointAndTangetVectorOfCurve(
                        buffer, ellipse->Get_Point(t_parameter),
                        ellipse->Get_TangentVector(t_parameter));
                    continue;
                }

                spiral = std::dynamic_pointer_cast<Spiral>(curve);
                if (spiral) {
                    buffer.append("spiral\n");

                    buffer.append("Radius: ");
                    buffer.append(std::to_string(spiral->Get_Radius()));
                    buffer.push_back('\n');
                    buffer.append("Stap: ");
                    buffer.append(std::to_string(spiral->Get_Stap()));
                    buffer.push_back('\n');

                    Output_PointAndTangetVectorOfCurve(
                        buffer, spiral->Get_Point(t_parameter),
                        spiral->Get_TangentVector(t_parameter));
                    continue;
                }
            }
        }

        void Get_CirclesFromCurves(
            std::vector<std::shared_ptr<Curve>>&  curves,
            std::vector<std::shared_ptr<Circle>>& circles) {
            circles.clear();
            circles.reserve(curves.size());
            std::shared_ptr<Circle> circle;
            for (std::shared_ptr<Curve> curve : curves) {
                circle = std::dynamic_pointer_cast<Circle>(curve);
                if (circle.get()) {
                    circles.push_back(circle);
                    continue;
                }
            }
        }

        void Sort_CirclesByParameter(
            std::vector<std::shared_ptr<Circle>>& circles) {
            std::sort(circles.begin(), circles.end(),
                      [](std::shared_ptr<Circle> circle1,
                         std::shared_ptr<Circle> circle2) {
                          return circle1->Get_Radius() < circle2->Get_Radius();
                      });
        }

        void Show_Circles(std::string&                          buffer,
                          std::vector<std::shared_ptr<Circle>>& circles) {
            int index = 0;
            buffer.append("\nShowing circles\n");

            for (std::shared_ptr<Circle> circle : circles) {
                index++;
                buffer.append(std::to_string(index));
                buffer.append(" circle\nRadius: ");
                buffer.append(std::to_string(circle->Get_Radius()));
                buffer.push_back('\n');
            }
            buffer.push_back('\n');
        }

    }  // namespace Natural
}  // namespace ExampleByCurves