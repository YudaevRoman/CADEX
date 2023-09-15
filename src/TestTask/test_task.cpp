#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

#define _USE_MATH_DEFINES

#define TEST_TASK_MACRO
#include "../../inc/headers.hpp"

using namespace Curves;
using namespace BasicCurves;

namespace TestTask {

    extern const int    MIN_CONTAINER_SIZE = 1;
    extern const int    MAX_CONTAINER_SIZE = 20;
    extern const double parameter_t        = M_PI_4;

    std::random_device rd;
    std::mt19937       gen(rd());

    void Test_Task() {

        std::vector<Curve*> curves;
        Set_Container(curves);

        std::string buffer;
        Show_Container_By_Parameter(buffer, curves);

        std::vector<Circle*> circles;
        Get_Circle_From_Container(curves, circles);

        std::sort(circles.begin(), circles.end(),
                  [](Circle* circle1, Circle* circle2) {
                      return circle1->Get_Radius() < circle2->Get_Radius();
                  });

        Show_Sum_Radius(buffer, circles);
        std::cout << buffer;
    }

    void Set_Container(std::vector<Curve*>& container) {
        int containerSize =
            Get_Random_Integer(MIN_CONTAINER_SIZE, MAX_CONTAINER_SIZE);

        container.reserve(containerSize);
        for (int i = 0; i < containerSize; i++) {
            switch (Get_Random_Integer(1, 3)) {
                case 1: {
                    container.push_back(new Circle(
                        Get_Random_Real(MIN_RADIUS_FOR_CIRCLE + ACCURACY,
                                        MAX_RADIUS_FOR_CIRCLE - ACCURACY)));
                    break;
                }
                case 2: {
                    container.push_back(new Ellipse(
                        Get_Random_Real(MIN_RADIUS_BY_X_FOR_ELLIPSE + ACCURACY,
                                        MAX_RADIUS_BY_X_FOR_ELLIPSE - ACCURACY),
                        Get_Random_Real(
                            MIN_RADIUS_BY_Y_FOR_ELLIPSE + ACCURACY,
                            MAX_RADIUS_BY_Y_FOR_ELLIPSE - ACCURACY)));
                    break;
                }
                case 3: {
                    container.push_back(new Spiral(
                        Get_Random_Real(MIN_RADIUS_FOR_SPIRAL + ACCURACY,
                                        MAX_RADIUS_FOR_SPIRAL - ACCURACY),
                        Get_Random_Real(MIN_STAP_FOR_SPIRAL + ACCURACY,
                                        MIN_STAP_FOR_SPIRAL - ACCURACY)));
                    break;
                }
            }
        }
    }

    double Get_Random_Real(double min, double max) {
        std::uniform_real_distribution dist(min, max);
        return dist(gen);
    }

    int Get_Random_Integer(int min, int max) {
        std::uniform_int_distribution dist(min, max);
        return dist(gen);
    }

    void Show_Container_By_Parameter(std::string&         buffer,
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
                buffer.append("circle" + '\n');
                Output_Curves(buffer, elem->Get_Point(parameter_t),
                              elem->Get_Derivative(parameter_t));
                circle = nullptr;
                continue;
            }

            ellipse = dynamic_cast<Ellipse*>(elem);
            if (ellipse) {
                buffer.append("ellipse" + '\n');
                Output_Curves(buffer, elem->Get_Point(parameter_t),
                              elem->Get_Derivative(parameter_t));
                ellipse = nullptr;
                continue;
            }

            spiral = dynamic_cast<Spiral*>(elem);
            if (spiral) {
                buffer.append("spiral" + '\n');
                Output_Curves(buffer, elem->Get_Point(parameter_t),
                              elem->Get_Derivative(parameter_t));
                spiral = nullptr;
                continue;
            }
        }
    }

    void Output_Curves(std::string& buffer, Point3D point, Point3D derivative) {

        buffer.append("Point: x = ");
        buffer.append(std::to_string(point.x));
        buffer.append(",y = ");
        buffer.append(std::to_string(point.y));
        buffer.append(",z = ");
        buffer.append(std::to_string(point.z));
        buffer.push_back('\n');

        buffer.append("Derivative: x = ");
        buffer.append(std::to_string(derivative.x));
        buffer.append(",y = ");
        buffer.append(std::to_string(derivative.y));
        buffer.append(",z = ");
        buffer.append(std::to_string(derivative.z));
        buffer.append("\n\n");
    }

    void Get_Circle_From_Container(std::vector<Curve*>&  container,
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

    void Show_Sum_Radius(std::string& buffer, std::vector<Circle*>& circles) {
        double sumRadius = 0;
        for (Circle* circle : circles) {
            sumRadius += circle->Get_Radius();
        }
        buffer.append("Summary radius: ");
        buffer.append(std::to_string(sumRadius) + "\n\n");
    }

}  // namespace TestTask