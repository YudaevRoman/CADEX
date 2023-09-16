
#define TEST_TASK_BY_BASIC_CURVES
#define TEST_TASK_WITHOUT_OMP
#include "../../../headers.hpp"

namespace TestTask {
    namespace ByBasicCurves {

        void Show_SumRadius_WithoutOMP(std::string&          buffer,
                                       std::vector<Circle*>& circles) {
            double sumRadius = 0;
            for (Circle* circle : circles) {
                sumRadius += circle->Get_Radius();
            }
            buffer.append("\nSummary radius: ");
            buffer.append(std::to_string(sumRadius) + "\n\n");
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