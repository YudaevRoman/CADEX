/*
Файл подключения заголовков
*/

#if defined(POINT3D_MACRO)
#    include "Curves/point3d.hpp"
#endif

#if defined(LIMITING_COEFFICIENTS_MACRO)
#    include "Curves/limiting_coefficients_of_curves.hpp"
#endif

#if defined(BASIC_CURVES_MACRO)
#    if defined(CIRCLE_MACRO) || defined(ALL_CURVES_MACRO)
#        include "Curves/BasicCurves/circle.hpp"
#    endif
#    if defined(CURVE_MACRO) || defined(ALL_CURVES_MACRO)
#        include "Curves/BasicCurves/curve.hpp"
#    endif
#    if defined(ELLIPSE_MACRO) || defined(ALL_CURVES_MACRO)
#        include "Curves/BasicCurves/ellipse.hpp"
#    endif
#    if defined(SPIRAL_MACRO) || defined(ALL_CURVES_MACRO)
#        include "Curves/BasicCurves/spiral.hpp"
#    endif
#endif