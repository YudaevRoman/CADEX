/*
Файл подключения заголовков
*/

#ifdef ALL_CURVES_MACRO
#    include "../Curves_dll/headers.hpp"
#    undef ALL_CURVES_MACRO
#endif

#ifdef TEST_TASK_GENERAL_CONSTANS
#    undef TEST_TASK_GENERAL_CONSTANS
#    include "inc/TestTask/General/constants.hpp"
#endif

#ifdef TEST_TASK_GENERAL_FUNCTION
#    undef TEST_TASK_GENERAL_FUNCTION
#    include "inc/TestTask/General/functions.hpp"
#endif

#ifdef TEST_TASK_GENERAL
#    undef TEST_TASK_GENERAL
#    define TEST_TASK_GENERAL_FUNCTION
#    include "headers.hpp"
#endif

#ifdef TEST_TASK_BY_BASIC_CURVES
#    undef TEST_TASK_BY_BASIC_CURVES
#    ifdef TEST_TASK_WITH_OMP
#        undef TEST_TASK_WITH_OMP
#        include "inc/TestTask/ByBasicCurves/with_omp.hpp"
#    endif
#    ifdef TEST_TASK_WITHOUT_OMP
#        undef TEST_TASK_WITHOUT_OMP
#        include "inc/TestTask/ByBasicCurves/with_omp.hpp"
#    endif
#endif