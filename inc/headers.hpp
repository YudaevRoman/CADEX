/*
Файл подключения заголовков
*/

#ifdef POINT3D_MACRO
#    undef POINT3D_MACRO
#    include "Curves/Structes/point3d.hpp"
#endif

#ifdef LIMITING_COEFFICIENTS_MACRO
#    undef LIMITING_COEFFICIENTS_MACRO
#    include "Curves/Structes/limiting_coefficients_of_curves.hpp"
#endif

#ifdef TEST_TASK_MACRO
#    undef TEST_TASK_MACRO
#    include "TestTask/test_task.hpp"
#endif

#ifdef ALL_CURVES_MACRO
#    undef ALL_CURVES_MACRO

#    define LIMITING_COEFFICIENTS_MACRO
#    include "headers.hpp"

#    define BASIC_CURVES_MACRO
#    define CIRCLE_MACRO
#    include "headers.hpp"

#    define BASIC_CURVES_MACRO
#    define ELLIPSE_MACRO
#    include "headers.hpp"

#    define BASIC_CURVES_MACRO
#    define SPIRAL_MACRO
#    include "headers.hpp"

#    define BASIC_CURVES_MACRO
#    define CURVE_MACRO
#    include "headers.hpp"

#endif

#ifdef BASIC_CURVES_MACRO
#    undef BASIC_CURVES_MACRO
#    ifdef CIRCLE_MACRO
#        undef CIRCLE_MACRO
#        include "Curves/BasicCurves/circle.hpp"
#    endif
#    ifdef CURVE_MACRO
#        undef CURVE_MACRO
#        include "Curves/BasicCurves/curve.hpp"
#    endif
#    ifdef ELLIPSE_MACRO
#        undef ELLIPSE_MACRO
#        include "Curves/BasicCurves/ellipse.hpp"
#    endif
#    ifdef SPIRAL_MACRO
#        undef SPIRAL_MACRO
#        include "Curves/BasicCurves/spiral.hpp"
#    endif
#endif