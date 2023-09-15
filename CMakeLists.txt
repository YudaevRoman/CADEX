cmake_minimum_required(VERSION 3.5.0)
project(CADEX VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(
    CADEX 
        main.cpp

        src/Curves/limiting_coefficients_of_curves.cpp

        src/Curves/BasicCurves/circle.cpp 
        src/Curves/BasicCurves/ellipse.cpp 
        src/Curves/BasicCurves/spiral.cpp 

        src/TestTask/test_task.cpp
    )

set(EXECUTABLE_OUTPUT_PATH "../bin")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
