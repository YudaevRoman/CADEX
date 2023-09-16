cmake_minimum_required(VERSION 3.5.0)
project(CADEX VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

#SHARED 
add_library(Curves SHARED)
target_include_directories(Curves PRIVATE "${PROJECT_SOURCE_DIR}")

add_subdirectory("Curves_dll")

find_package(OpenMP)
add_executable(
    CADEX
        Apps/main.cpp
        
        Apps/src/TestTask/General/constans.cpp
        Apps/src/TestTask/General/functions.cpp
        
        Apps/src/TestTask/ByBasicCurves/with_omp.cpp
        Apps/src/TestTask/ByBasicCurves/without_omp.cpp
)
target_link_libraries(CADEX PRIVATE Curves)
target_link_libraries(CADEX PRIVATE OpenMP::OpenMP_CXX)

install(TARGETS Curves FILE_SET HEADERS)
add_custom_command(
    TARGET Curves POST_BUILD 
    COMMAND 
    "${CMAKE_COMMAND}" -E copy 
        "$<TARGET_FILE:Curves>"
        "../bin/$<TARGET_FILE_NAME:Curves>"
)

set(EXECUTABLE_OUTPUT_PATH "../bin")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)