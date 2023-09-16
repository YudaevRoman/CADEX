
cmake_policy(SET CMP0076 NEW)

target_sources(
    Curves
    PRIVATE 
        ../Curves_dll/src/Curves/BasicCurves/curve.cpp
        ../Curves_dll/src/Curves/BasicCurves/circle.cpp
        ../Curves_dll/src/Curves/BasicCurves/ellipse.cpp
        ../Curves_dll/src/Curves/BasicCurves/spiral.cpp
        ../Curves_dll/src/Curves/Structes/limiting_coefficients_of_curves.cpp
        ../Curves_dll/inc/Curves/BasicCurves/curve.hpp
        ../Curves_dll/inc/Curves/BasicCurves/circle.hpp
        ../Curves_dll/inc/Curves/BasicCurves/ellipse.hpp
        ../Curves_dll/inc/Curves/BasicCurves/spiral.hpp
        ../Curves_dll/inc/Curves/Structes/limiting_coefficients_of_curves.hpp
        ../Curves_dll/inc/Curves/Structes/point3d.hpp
        ../Curves_dll/inc/Curves/Structes/vector3d.hpp
        
    PUBLIC FILE_SET HEADERS 
    BASE_DIRS ${PROJECT_SOURCE_DIR}
    FILES 
        ../Curves_dll/headers.hpp
)