#include <iostream>

#define TEST_TASK_BY_BASIC_CURVES
#define TEST_TASK_WITHOUT_OMP
#define TEST_TASK_WITH_OMP
#include "headers.hpp"

using namespace TestTask::ByBasicCurves;

int main() {

    char        key;
    std::string buffer;

    std::vector<Curve*>  curves;
    std::vector<Circle*> circles;

    Set_MaxContainerSize(20);

    do {
        curves.clear();
        circles.clear();

        Set_Curves(curves);

        Show_CurvesByParameter(buffer, curves);

        buffer.append("\nSelecting circles from container\n\n");
        Get_CirclesFromCurves(curves, circles);

        Show_Circles(buffer, circles);

        buffer.append("\nSorting circles\n\n");
        std::sort(circles.begin(), circles.end(),
                  [](Circle* circle1, Circle* circle2) {
                      return circle1->Get_Radius() < circle2->Get_Radius();
                  });

        Show_Circles(buffer, circles);

        Show_SumRadius_WithoutOMP(buffer, circles);
        Show_SumRadius_WithOMP(buffer, circles);
        std::cout << buffer;

        std::cout << "If you want to finish, press 'n'\n";
        std::cin >> key;
        std::cout << std::endl << std::endl;
    } while (key != 'n');

    return 0;
}
