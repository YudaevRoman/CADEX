cmake_minimum_required(VERSION 3.5.0)
project(Curves VERSION 0.1.0 LANGUAGES C CXX)

cmake_policy(SET CMP0076 NEW)

target_sources(
    Curves
    PRIVATE 
        src/curve.cpp
        src/circle.cpp
        src/ellipse.cpp
        src/spiral.cpp
        src/limitations.cpp
        
    PUBLIC FILE_SET HEADERS 
    BASE_DIRS ${PROJECT_SOURCE_DIR}
    FILES 
        inc/curve.hpp
        inc/circle.hpp
        inc/ellipse.hpp
        inc/spiral.hpp
        inc/limitations.hpp
        inc/point3d.hpp
        inc/vector3d.hpp
)