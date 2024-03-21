#include "projection.h"
#include <iostream>

namespace Projection {

    void Projection::calculateDirectingVector(const Vector& A, const Vector& B) {
        normal = {B.x - A.x, B.y - A.y, B.z - A.z};
    }

    void Projection::findIntersectionPoint(const Vector& point, const Vector& lineDir, const Plane& plane) {
        Vector result = Vector(plane.a, plane.b, plane.c);

        // Проверка, лежит ли прямая на плоскости или параллельна
        if (plane.a * point.x + plane.b * point.y + plane.c * point.z == plane.d) {
            std::cout << "Прямая уже лежит на плоскости.\n";
            return;
        }
        double t = -(plane.d + plane.a * point.x + plane.b * point.y + plane.c * point.z) / (plane.a * lineDir.x + plane.b * lineDir.y + plane.c * lineDir.z);
        intersection = point + lineDir * t;
    }

    void Projection::projectPointOnLine(const Vector& point, const Vector& linePoint) {
        Vector lineToPoint = point - linePoint;
        double t = (lineToPoint.x * normal.x + lineToPoint.y * normal.y + lineToPoint.z * normal.z) /
                (normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
        projection = linePoint + normal * t;
    }

    void Projection::findDistanceBetweenLines(const Line& line1, const Line& line2) {
        Vector crossDir = line1.dir.cross(line2.dir); // векторное произведение направляющих векторов
        Vector diff = line2.point - line1.point; // вектор, соединяющий две точки на прямых

        distanceBetweenLines = std::abs(diff.dot(crossDir)) / crossDir.length();
    }

    Plane calculatePlaneEquation(const Vector& normal, const Vector& point) {
        Plane plane;
        plane.a = normal.x;
        plane.b = normal.y;
        plane.c = normal.z;
        plane.d = -(plane.a * point.x + plane.b * point.y + plane.c * point.z);
        return plane;
    }
}
