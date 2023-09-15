#include <cmath>
#include <iostream>
#include <vector>

#include "inc/Curves/BasicCurves/ellipse.hpp"

#define _USE_MATH_DEFINES

using namespace std;
using namespace Curves;
using namespace BasicCurves;

int main() {

    vector<Ellipse *> curves;
    Point3D           point;

    try {
        curves.push_back(new Ellipse(1'000, 1'000));

        point = curves[0]->Get_Point(M_PI_4);
        cout << "Point: x = " << point.x << ", y = " << point.y
             << ", z = " << point.z;
        cout << endl;

        point = curves[0]->Get_Derivative(M_PI_4);
        cout << "Derivative: x = " << point.x << ", y = " << point.y
             << ", z = " << point.z;
        cout << endl;

    } catch (exception &ex) {
        cout << ex.what();
    }

    system("pause");

    return 0;
}
