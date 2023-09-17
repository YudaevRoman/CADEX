#include <cmath>
#include <stdexcept>

#define _USE_MATH_DEFINES

#define EXAMPLE_GENERAL_CONSTANS
#include "../../../headers.hpp"

namespace ExampleByCurves {
    namespace Natural {

        /*VARIABLES*/
        int MIN_CONTAINER_SIZE = 1;
        int MAX_CONTAINER_SIZE = 10;

        const int VECTOR_SIZE_LIMIT = 500'000;

        const double t_parameter = M_PI_4;

        std::random_device rd;
        std::mt19937       gen(rd());
        /*VARIABLES*/

        /*ACCESS METHODS*/
        std::mt19937& Get_Generator() {
            return gen;
        }

        int Get_MinContainerSize() {
            return MIN_CONTAINER_SIZE;
        }
        int Get_MaxContainerSize() {
            return MAX_CONTAINER_SIZE;
        }
        void Set_MinContainerSize(int min) {
            if (min > MAX_CONTAINER_SIZE) {
                throw std::invalid_argument("Min > max\n");
            }
            if (min < 1) {
                throw std::invalid_argument("Min <= 0\n");
            }

            MIN_CONTAINER_SIZE = min;
        }
        void Set_MaxContainerSize(int max) {
            if (max < MIN_CONTAINER_SIZE) {
                throw std::invalid_argument("Max < min\n");
            }
            if (max > VECTOR_SIZE_LIMIT) {
                throw std::invalid_argument("Max <= 0\n");
            }

            MAX_CONTAINER_SIZE = max;
        }
        /*ACCESS METHODS*/

    }  // namespace Natural
}  // namespace ExampleByCurves