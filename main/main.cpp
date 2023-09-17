#include <iostream>

#include "inc/constants.hpp"
#include "inc/functions.hpp"
#include "inc/functions_not_omp.hpp"
#include "inc/functions_omp.hpp"

using namespace Curves;

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
        buffer.clear();

        std::cout << "If you want to finish, press 'n'\n";
        std::cin >> key;
        std::cout << std::endl << std::endl;
    } while (key != 'n');

    return 0;
}
