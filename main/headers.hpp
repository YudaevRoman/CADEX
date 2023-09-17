/*
Файл подключения заголовков
*/

#ifdef CURVES_ALL
#    include "../curves/headers.hpp"
#endif

#ifdef EXAMPLE_GENERAL_CONSTANS
#    undef EXAMPLE_GENERAL_CONSTANS
#    include "example_by_curves/inc/general/constants.hpp"
#endif

#ifdef EXAMPLE_BY_CURVES_NATURAL
#    undef EXAMPLE_BY_CURVES_NATURAL
#    ifdef EXAMPLE_FUNCTIONS
#        undef EXAMPLE_FUNCTIONS
#        include "example_by_curves/inc/natural/functions.hpp"
#    endif
#    ifdef EXAMPLE_OMP
#        undef EXAMPLE_OMP
#        include "example_by_curves/inc/natural/functions_omp.hpp"
#    endif
#    ifdef EXAMPLE_NOT_OMP
#        undef EXAMPLE_NOT_OMP
#        include "example_by_curves/inc/natural/functions_not_omp.hpp"
#    endif
#endif