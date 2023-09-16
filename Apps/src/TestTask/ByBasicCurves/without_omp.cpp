
#define TEST_TASK_BY_BASIC_CURVES
#define TEST_TASK_WITHOUT_OMP
#include "../../../headers.hpp"

namespace TestTask {
    namespace ByBasicCurves {

        void Show_SumRadius_WithoutOMP(std::string&          buffer,
                                       std::vector<Circle*>& circles) {

            int    i;
            double time;
            double sumRadius = 0;

            time_point start = high_resolution_clock::now();
            for (i = 0; i < circles.size(); i++) {
                sumRadius += circles[i]->Get_Radius();
            }
            time_point stop = high_resolution_clock::now();

            buffer.append("\nContainer size: ");
            buffer.append(std::to_string(circles.size()));
            buffer.append("\nSummary radius without OMP: ");
            buffer.append(std::to_string(sumRadius));

            time = duration_cast<microseconds>(stop - start).count();
            buffer.append("\nExecution time: ");
            buffer.append(std::to_string(time) + " microseconds\n\n");
        }

        void TestTask_WithoutOMP() {

            std::vector<Curve*> curves;
            Set_Curves(curves);

            std::string buffer;
            Show_CurvesByParameter(buffer, curves);

            buffer.append("\nSelecting circles from container\n\n");
            std::vector<Circle*> circles;
            Get_CirclesFromCurves(curves, circles);

            Show_Circles(buffer, circles);

            buffer.append("\nSorting circles\n\n");
            std::sort(circles.begin(), circles.end(),
                      [](Circle* circle1, Circle* circle2) {
                          return circle1->Get_Radius() < circle2->Get_Radius();
                      });

            Show_Circles(buffer, circles);

            Show_SumRadius_WithoutOMP(buffer, circles);
            std::cout << buffer;
        }

    }  // namespace ByBasicCurves
}  // namespace TestTask