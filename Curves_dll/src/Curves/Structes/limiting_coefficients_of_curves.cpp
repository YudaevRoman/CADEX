#define LIMITING_COEFFICIENTS_MACRO
#include "../../../headers.hpp"

namespace Curves {

    double ACCURACY = 0.0001;

    double MIN_RADIUS_FOR_CIRCLE = 0;
    double MAX_RADIUS_FOR_CIRCLE = 50;

    double MIN_RADIUS_BY_X_FOR_ELLIPSE = 0;
    double MAX_RADIUS_BY_X_FOR_ELLIPSE = 50;
    double MIN_RADIUS_BY_Y_FOR_ELLIPSE = 0;
    double MAX_RADIUS_BY_Y_FOR_ELLIPSE = 50;

    double MIN_RADIUS_FOR_SPIRAL = 0;
    double MAX_RADIUS_FOR_SPIRAL = 50;
    double MIN_STAP_FOR_SPIRAL   = 0;
    double MAX_STAP_FOR_SPIRAL   = 50;

}  // namespace Curves