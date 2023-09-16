
#define TEST_TASK_GENERAL_CONSTANS
#include "../../../headers.hpp"

namespace TestTask {
    namespace ByBasicCurves {

        extern const int    MIN_CONTAINER_SIZE = 1;
        extern const int    MAX_CONTAINER_SIZE = 20;
        extern const double t_parameter        = M_PI_4;

        std::random_device rd;
        std::mt19937       gen(rd());

    }  // namespace ByBasicCurves
}  // namespace TestTask