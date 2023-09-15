#include <cmath>
#include <iostream>
#include <vector>

#include "inc/Curves/BasicCurves/circle.hpp"

#define _USE_MATH_DEFINES

using namespace std;
using namespace Curves;
using namespace BasicCurves;

int main() {

    vector<Circle *> curves;

    try {
        curves.push_back(new Circle(3));
    } catch (exception &ex) {
        cout << ex.what();
    }

    Point3D point = curves[0]->Get_Point(M_PI_4);
    cout << "Point: x = " << point.x << ", y = " << point.y
         << ", z = " << point.z;
    cout << endl;

    point = curves[0]->Get_Derivative(M_PI_4);
    cout << "Derivative: x = " << point.x << ", y = " << point.y
         << ", z = " << point.z;
    cout << endl;

    return 0;
}
