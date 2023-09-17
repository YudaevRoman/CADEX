#include <chrono>
#include <iostream>

#define EXAMPLE_BY_CURVES_NATURAL
#define EXAMPLE_NOT_OMP
#include "../../../headers.hpp"

namespace ExampleByCurves {
    namespace Natural {

        void Show_SumRadius_NotOMP(
            std::string&                          buffer,
            std::vector<std::shared_ptr<Circle>>& circles) {
            int    i;
            long   time;
            double sumRadius = 0;

            std::chrono::time_point start =
                std::chrono::high_resolution_clock::now();
            for (i = 0; i < circles.size(); i++) {
                sumRadius += circles[i]->Get_Radius();
            }
            std::chrono::time_point stop =
                std::chrono::high_resolution_clock::now();

            buffer.append("\nContainer size: ");
            buffer.append(std::to_string(circles.size()));
            buffer.append("\nSummary radius without OMP: ");
            buffer.append(std::to_string(sumRadius));

            time = std::chrono::duration_cast<std::chrono::microseconds>(stop -
                                                                         start)
                       .count();

            buffer.append("\nExecution time: ");
            buffer.append(std::to_string(time) + " microseconds\n\n");
        }

        void Example_NotOMP() {
            std::vector<std::shared_ptr<Curve>> curves;
            Set_Curves(curves);

            std::string buffer;
            Show_CurvesByParameter(buffer, curves);

            buffer.append("\nSelecting circles from curves\n\n");
            std::vector<std::shared_ptr<Circle>> circles;
            Get_CirclesFromCurves(curves, circles);

            Show_Circles(buffer, circles);

            buffer.append("\nSorting circles\n\n");
            Sort_CirclesByParameter(circles);

            Show_Circles(buffer, circles);

            Show_SumRadius_NotOMP(buffer, circles);
            std::cout << buffer;
        }

    }  // namespace Natural
}  // namespace ExampleByCurves