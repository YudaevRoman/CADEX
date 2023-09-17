cmake_minimum_required(VERSION 3.5.0)
project(Curves VERSION 0.1.0 LANGUAGES C CXX)

cmake_policy(SET CMP0076 NEW)

target_sources(
    Curves
    PRIVATE 
        src/natural/curve.cpp
        src/natural/circle.cpp
        src/natural/ellipse.cpp
        src/natural/spiral.cpp
        src/general/limitations.cpp

        inc/natural/curve.hpp
        inc/natural/circle.hpp
        inc/natural/ellipse.hpp
        inc/natural/spiral.hpp
        inc/general/limitations.hpp
        inc/general/point3d.hpp
        inc/general/vector3d.hpp
        
    PUBLIC FILE_SET HEADERS 
    BASE_DIRS ${PROJECT_SOURCE_DIR}
    FILES 
        headers.hpp
)