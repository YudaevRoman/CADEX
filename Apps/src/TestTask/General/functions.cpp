
#define TEST_TASK_GENERAL_FUNCTION
#include "../../../headers.hpp"

namespace TestTask {
    namespace ByBasicCurves {

        double Get_RandomReal(double min, double max) {
            std::uniform_real_distribution dist(min, max);
            return dist(Get_Generator());
        }

        int Get_RandomInteger(int min, int max) {
            std::uniform_int_distribution dist(min, max);
            return dist(Get_Generator());
        }

        void Set_Curves(std::vector<Curve*>& curves) {
            int containerSize = Get_RandomInteger(Get_MinContainerSize(),
                                                  Get_MaxContainerSize());

            curves.reserve(containerSize);
            for (int i = 0; i < containerSize; i++) {
                switch (Get_RandomInteger(1, 3)) {
                    case 1: {
                        curves.push_back(new Circle(
                            Get_RandomReal(MIN_RADIUS_FOR_CIRCLE + ACCURACY,
                                           MAX_RADIUS_FOR_CIRCLE - ACCURACY)));
                        break;
                    }
                    case 2: {
                        curves.push_back(new Ellipse(
                            Get_RandomReal(
                                MIN_RADIUS_BY_X_FOR_ELLIPSE + ACCURACY,
                                MAX_RADIUS_BY_X_FOR_ELLIPSE - ACCURACY),
                            Get_RandomReal(
                                MIN_RADIUS_BY_Y_FOR_ELLIPSE + ACCURACY,
                                MAX_RADIUS_BY_Y_FOR_ELLIPSE - ACCURACY)));
                        break;
                    }
                    case 3: {
                        curves.push_back(new Spiral(
                            Get_RandomReal(MIN_RADIUS_FOR_SPIRAL + ACCURACY,
                                           MAX_RADIUS_FOR_SPIRAL - ACCURACY),
                            Get_RandomReal(MIN_STAP_FOR_SPIRAL + ACCURACY,
                                           MAX_STAP_FOR_SPIRAL - ACCURACY)));
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

        void Show_CurvesByParameter(std::string&         buffer,
                                    std::vector<Curve*>& curves) {
            int      index = 0;
            Point3D  point;
            Point3D  derivative;
            Circle*  circle  = nullptr;
            Ellipse* ellipse = nullptr;
            Spiral*  spiral  = nullptr;

            buffer.append("\nShowing curves by parameter\n\n");

            for (Curve* curve : curves) {

                index++;
                buffer.append(std::to_string(index));
                buffer.append(" curve\nType: ");

                circle = dynamic_cast<Circle*>(curve);
                if (circle) {
                    buffer.append("circle\n");

                    buffer.append("Radius: ");
                    buffer.append(std::to_string(circle->Get_Radius()));
                    buffer.push_back('\n');

                    Output_PointAndTangetVectorOfCurve(
                        buffer, curve->Get_Point(t_parameter),
                        curve->Get_TangentVector(t_parameter));
                    circle = nullptr;
                    continue;
                }

                ellipse = dynamic_cast<Ellipse*>(curve);
                if (ellipse) {
                    buffer.append("ellipse\n");

                    buffer.append("Radius by X: ");
                    buffer.append(std::to_string(ellipse->Get_RadiusByX()));
                    buffer.push_back('\n');
                    buffer.append("Radius by Y: ");
                    buffer.append(std::to_string(ellipse->Get_RadiusByY()));
                    buffer.push_back('\n');

                    Output_PointAndTangetVectorOfCurve(
                        buffer, curve->Get_Point(t_parameter),
                        curve->Get_TangentVector(t_parameter));
                    ellipse = nullptr;
                    continue;
                }

                spiral = dynamic_cast<Spiral*>(curve);
                if (spiral) {
                    buffer.append("spiral\n");

                    buffer.append("Radius: ");
                    buffer.append(std::to_string(spiral->Get_Radius()));
                    buffer.push_back('\n');
                    buffer.append("Stap: ");
                    buffer.append(std::to_string(spiral->Get_Stap()));
                    buffer.push_back('\n');

                    Output_PointAndTangetVectorOfCurve(
                        buffer, curve->Get_Point(t_parameter),
                        curve->Get_TangentVector(t_parameter));
                    spiral = nullptr;
                    continue;
                }
            }
        }


        void Get_CirclesFromCurves(std::vector<Curve*>&  curves,
                                   std::vector<Circle*>& circles) {
            circles.reserve(curves.size());
            Circle* circle = nullptr;
            for (Curve* curve : curves) {
                circle = dynamic_cast<Circle*>(curve);
                if (circle) {
                    circles.push_back(circle);
                    circle = nullptr;
                    continue;
                }
            }
        }

        void Show_Circles(std::string& buffer, std::vector<Circle*>& circles) {
            int index = 0;
            buffer.append("\nShowing circles\n");

            for (Circle* circle : circles) {

                index++;
                buffer.append(std::to_string(index));
                buffer.append(" curve\nRadius: ");
                buffer.append(std::to_string(circle->Get_Radius()));
                buffer.push_back('\n');
            }
            buffer.push_back('\n');
        }

    }  // namespace ByBasicCurves
}  // namespace TestTask