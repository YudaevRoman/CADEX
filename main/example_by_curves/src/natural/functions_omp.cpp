#include <omp.h>

#include <chrono>
#include <iostream>

#define EXAMPLE_BY_CURVES_NATURAL
#define EXAMPLE_OMP
#include "../../../headers.hpp"

namespace ExampleByCurves {
    namespace Natural {

        void Show_SumRadius_OMP(std::string&                          buffer,
                                std::vector<std::shared_ptr<Circle>>& circles) {
            int    i;
            long   time;
            double allSum = 0, sumRadius = 0;

            std::chrono::time_point start =
                std::chrono::high_resolution_clock::now();
#pragma omp parallel private(i, sumRadius) shared(allSum)
            {
#pragma omp for private(i)
                for (i = 0; i < circles.size(); i++) {
                    sumRadius += circles[i]->Get_Radius();
                }
#pragma omp critical
                {
                    allSum += sumRadius;
                    /*текст, чтобы автоформатирование не ломало блок*/
                }
            }
            std::chrono::time_point stop =
                std::chrono::high_resolution_clock::now();

            buffer.append("\nContainer size: ");
            buffer.append(std::to_string(circles.size()));
            buffer.append("\nSummary radius with OMP: ");
            buffer.append(std::to_string(allSum));

            time = std::chrono::duration_cast<std::chrono::microseconds>(stop -
                                                                         start)
                       .count();

            buffer.append("\nExecution time: ");
            buffer.append(std::to_string(time) + " microseconds\n\n");
        }

        void Example_OMP() {

            std::vector<std::shared_ptr<Curve>> curves;
            Set_Curves(curves);

            std::string buffer;
            Show_CurvesByParameter(buffer, curves);

            buffer.append("\nSelecting circles from curvers\n\n");
            std::vector<std::shared_ptr<Circle>> circles;
            Get_CirclesFromCurves(curves, circles);

            Show_Circles(buffer, circles);

            buffer.append("\nSorting circles\n\n");
            Sort_CirclesByParameter(circles);

            Show_Circles(buffer, circles);

            Show_SumRadius_OMP(buffer, circles);
            std::cout << buffer;
        }

    }  // namespace Natural
}  // namespace ExampleByCurves