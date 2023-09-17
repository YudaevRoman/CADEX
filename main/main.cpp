#include <iostream>

#define EXAMPLE_BY_CURVES_NATURAL
#define EXAMPLE_NOT_OMP
#define EXAMPLE_OMP
#include "headers.hpp"

using namespace ExampleByCurves::Natural;

int main() {

    char        key;
    std::string buffer;

    std::vector<std::shared_ptr<Curve>>  curves;
    std::vector<std::shared_ptr<Circle>> circles;

    Set_MaxContainerSize(20);

    do {
        Set_Curves(curves);

        Show_CurvesByParameter(buffer, curves);

        buffer.append("\nSelecting circles from curves\n\n");
        Get_CirclesFromCurves(curves, circles);

        Show_Circles(buffer, circles);

        buffer.append("\nSorting circles\n\n");
        Sort_CirclesByParameter(circles);

        Show_Circles(buffer, circles);

        Show_SumRadius_NotOMP(buffer, circles);
        Show_SumRadius_OMP(buffer, circles);
        std::cout << buffer;

        std::cout << "If you want to finish, press 'n'\n";
        std::cin >> key;
        std::cout << std::endl << std::endl;
    } while (key != 'n');

    return 0;
}
