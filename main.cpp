#include <iostream>
#include <cmath>
#include "projection.h"


int main() {
    Projection::Vector A(-2, 6, -1);
    Projection::Vector B(1, 2, 0);
    Projection::Vector P(0, 1, -1);

    Projection::Vector D(0, 0, 0);
    Projection::Vector dirLine(0, -4, 1);

    Projection::Vector C(0, 0, 5);
    Projection::Vector dir(1, -4, 5);

    Projection::Projection result;
    
    result.calculateDirectingVector(A, B);
   
    auto resultPlane = Projection::Plane();
    resultPlane = Projection::calculatePlaneEquation(result.normal, P);

    std::cout << "Plane: " << "("
                << resultPlane.a << ", " 
                << resultPlane.b << ", "
                << resultPlane.c << ", " 
                << resultPlane.d << ")"
                << std::endl;

    result.findIntersectionPoint(D, dirLine, resultPlane);
    if (result.intersection != Projection::Vector(0.0, 0.0, 0.0)) 
    {
        std::cout << "Intersection point: (" 
              << result.intersection.x << ", " 
              << result.intersection.y << ", " 
              << result.intersection.z << ")"
              << std::endl;
    }
    
    result.projectPointOnLine(P, A);
    std::cout << "Projection: " << "("
                << result.projection.x << ", " 
                << result.projection.y << ", " 
                << result.projection.z << ")"
                << std::endl;
    Projection::Line firstLine = Projection::Line(result.normal, P); 
    Projection::Line secondLine = Projection::Line(dir, C); 

    result.findDistanceBetweenLines(firstLine, secondLine);
    std::cout << "Distance: "
              << result.distanceBetweenLines
              << std::endl;
    return 0;
}