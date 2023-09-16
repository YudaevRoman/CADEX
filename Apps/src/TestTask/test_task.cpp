
#define TEST_TASK_MACRO
#include "Apps/headers.hpp"

using namespace Curves;
using namespace BasicCurves;

namespace TestTask {

    extern const int    MIN_CONTAINER_SIZE = 1;
    extern const int    MAX_CONTAINER_SIZE = 20;
    extern const double t_parameter        = M_PI_4;

    std::random_device rd;
    std::mt19937       gen(rd());

    void TestTask() {

        std::vector<Curve*> curves;
        Set_Container(curves);

        std::string buffer;
        Show_ContainerByParameter(buffer, curves);

        std::vector<Circle*> circles;
        Get_CircleFromContainer(curves, circles);

        std::sort(circles.begin(), circles.end(),
                  [](Circle* circle1, Circle* circle2) {
                      return circle1->Get_Radius() < circle2->Get_Radius();
                  });

        Show_SumRadius(buffer, circles);
        std::cout << buffer;
    }

    void Set_Container(std::vector<Curve*>& container) {
        int containerSize =
            Get_RandomInteger(MIN_CONTAINER_SIZE, MAX_CONTAINER_SIZE);

        container.reserve(containerSize);
        for (int i = 0; i < containerSize; i++) {
            switch (Get_RandomInteger(1, 3)) {
                case 1: {
                    container.push_back(new Circle(
                        Get_RandomReal(MIN_RADIUS_FOR_CIRCLE + ACCURACY,
                                       MAX_RADIUS_FOR_CIRCLE - ACCURACY)));
                    break;
                }
                case 2: {
                    container.push_back(new Ellipse(
                        Get_RandomReal(MIN_RADIUS_BY_X_FOR_ELLIPSE + ACCURACY,
                                       MAX_RADIUS_BY_X_FOR_ELLIPSE - ACCURACY),
                        Get_RandomReal(
                            MIN_RADIUS_BY_Y_FOR_ELLIPSE + ACCURACY,
                            MAX_RADIUS_BY_Y_FOR_ELLIPSE - ACCURACY)));
                    break;
                }
                case 3: {
                    container.push_back(new Spiral(
                        Get_RandomReal(MIN_RADIUS_FOR_SPIRAL + ACCURACY,
                                       MAX_RADIUS_FOR_SPIRAL - ACCURACY),
                        Get_RandomReal(MIN_STAP_FOR_SPIRAL + ACCURACY,
                                       MAX_STAP_FOR_SPIRAL - ACCURACY)));
                    break;
                }
            }
        }
    }

    double Get_RandomReal(double min, double max) {
        std::uniform_real_distribution dist(min, max);
        return dist(gen);
    }

    int Get_RandomInteger(int min, int max) {
        std::uniform_int_distribution dist(min, max);
        return dist(gen);
    }

    void Show_ContainerByParameter(std::string&         buffer,
                                   std::vector<Curve*>& container) {

        Point3D  point;
        Point3D  derivative;
        Circle*  circle  = nullptr;
        Ellipse* ellipse = nullptr;
        Spiral*  spiral  = nullptr;

        for (Curve* elem : container) {

            buffer.append("Type curve: ");

            circle = dynamic_cast<Circle*>(elem);
            if (circle) {
                buffer.append("circle\n");
                Output_Curves(buffer, elem->Get_Point(t_parameter),
                              elem->Get_TangentVector(t_parameter));
                circle = nullptr;
                continue;
            }

            ellipse = dynamic_cast<Ellipse*>(elem);
            if (ellipse) {
                buffer.append("ellipse\n");
                Output_Curves(buffer, elem->Get_Point(t_parameter),
                              elem->Get_TangentVector(t_parameter));
                ellipse = nullptr;
                continue;
            }

            spiral = dynamic_cast<Spiral*>(elem);
            if (spiral) {
                buffer.append("spiral\n");
                Output_Curves(buffer, elem->Get_Point(t_parameter),
                              elem->Get_TangentVector(t_parameter));
                spiral = nullptr;
                continue;
            }
        }
    }

    void Output_Curves(std::string& buffer, Point3D point,
                       Vector3D derivative) {

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
        buffer.append("\n\n");
    }

    void Get_CircleFromContainer(std::vector<Curve*>&  container,
                                 std::vector<Circle*>& circles) {
        circles.reserve(container.size());
        Circle* circle = nullptr;
        for (Curve* elem : container) {
            circle = dynamic_cast<Circle*>(elem);
            if (circle) {
                circles.push_back(circle);
                circle = nullptr;
                continue;
            }
        }
    }

    void Show_SumRadius(std::string& buffer, std::vector<Circle*>& circles) {
        double sumRadius = 0;
        for (Circle* circle : circles) {
            sumRadius += circle->Get_Radius();
        }
        buffer.append("Summary radius: ");
        buffer.append(std::to_string(sumRadius) + "\n\n");
    }

}  // namespace TestTask