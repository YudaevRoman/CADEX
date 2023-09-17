/*
Файл подключения заголовков
*/

#ifdef CURVES_POINT3D
#    undef CURVES_POINT3D
#    include "inc/general/point3d.hpp"
#endif

#ifdef CURVES_VECTOR3D
#    undef CURVES_VECTOR3D
#    include "inc/general/vector3d.hpp"
#endif

#ifdef CURVES_LIMITATIONS
#    undef CURVES_LIMITATIONS
#    include "inc/general/limitations.hpp"
#endif

#ifdef CURVES_NATURAL
#    undef CURVES_NATURAL

#    ifdef CURVES_ALL
#        undef CURVES_ALL

#        define CURVES_LIMITATIONS
#        include "headers.hpp"

#        define CURVES_NATURAL
#        define CURVES_CIRCLE
#        include "headers.hpp"

#        define CURVES_NATURAL
#        define CURVES_ELLIPSE
#        include "headers.hpp"

#        define CURVES_NATURAL
#        define CURVES_SPIRAL
#        include "headers.hpp"
#    endif

#    ifdef CURVES_CURVE
#        undef CURVES_CURVE
#        include "inc/natural/curve.hpp"
#    endif

#    ifdef CURVES_CIRCLE
#        undef CURVES_CIRCLE
#        include "inc/natural/circle.hpp"
#    endif

#    ifdef CURVES_ELLIPSE
#        undef CURVES_ELLIPSE
#        include "inc/natural/ellipse.hpp"
#    endif

#    ifdef CURVES_SPIRAL
#        undef CURVES_SPIRAL
#        include "inc/natural/spiral.hpp"
#    endif
#endif

// упрощённые
#ifdef CURVES_SIMPLIFIED
#    undef CURVES_SIMPLIFIED

#    ifdef CURVES_ALL
#        undef CURVES_ALL

#        define CURVES_LIMITATIONS
#        include "headers.hpp"

#        define CURVES_SIMPLIFIED
#        define CURVES_CIRCLE
#        include "headers.hpp"

#        define CURVES_SIMPLIFIED
#        define CURVES_ELLIPSE
#        include "headers.hpp"

#        define CURVES_SIMPLIFIED
#        define CURVES_SPIRAL
#        include "headers.hpp"
#    endif

#    ifdef CURVES_CURVE
#        undef CURVES_CURVE
#        include "inc/simplified/curve.hpp"
#    endif

#    ifdef CURVES_CIRCLE
#        undef CURVES_CIRCLE
#        include "inc/simplified/circle.hpp"
#    endif

#    ifdef CURVES_ELLIPSE
#        undef CURVES_ELLIPSE
#        include "inc/simplified/ellipse.hpp"
#    endif

#    ifdef CURVES_SPIRAL
#        undef CURVES_SPIRAL
#        include "inc/simplified/spiral.hpp"
#    endif
#endif

// усложнённые
#ifdef CURVES_COMPLICATED
#    undef CURVES_COMPLICATED

#    ifdef CURVES_ALL
#        undef CURVES_ALL

#        define CURVES_LIMITATIONS
#        include "headers.hpp"

#        define CURVES_COMPLICATED
#        define CURVES_CIRCLE
#        include "headers.hpp"

#        define CURVES_COMPLICATED
#        define CURVES_ELLIPSE
#        include "headers.hpp"

#        define CURVES_COMPLICATED
#        define CURVES_SPIRAL
#        include "headers.hpp"
#    endif

#    ifdef CURVES_CURVE
#        undef CURVES_CURVE
#        include "inc/complicated/curve.hpp"
#    endif

#    ifdef CURVES_CIRCLE
#        undef CURVES_CIRCLE
#        include "inc/complicated/circle.hpp"
#    endif

#    ifdef CURVES_ELLIPSE
#        undef CURVES_ELLIPSE
#        include "inc/complicated/ellipse.hpp"
#    endif

#    ifdef CURVES_SPIRAL
#        undef CURVES_SPIRAL
#        include "inc/complicated/spiral.hpp"
#    endif
#endif