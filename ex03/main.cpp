#include <iostream>
#include "Point.h"

int main(void) {
    Point a(0,  0);
    Point b(10, 0);
    Point c(0, 10);

    //1. Point inside of the Triangle
    Point inside(2, 2);
    //2. Point of outside of the Triangle
    Point outside(20, 20);
    //3. Point on the line. It should be outside(all false)
    Point edge (5, 5);
    //4. Point on the peak
    Point peak (0, 0);

    std::cout << "Triangle: (0, 0), (10, 0), (0, 10)" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    
    if(bsp(a, b, c, inside))
        std::cout << "Point(2, 2) is INSIDE" << std::endl;
    else
        std::cout << "Point(2, 2) is OUTSIDE or on the edge or vertex" << std::endl;
    
    if(bsp(a, b, c, outside))
        std::cout << "Point(20, 20) is INSIDE" << std::endl;
    else
        std::cout << "Point(20, 20) is OUTSIDE or on the edge or vertex" << std::endl;

    if(bsp(a, b, c, edge))
        std::cout << "Point(5, 5) is INSIDE" << std::endl;
    else
        std::cout << "Point(5, 5) is OUTSIDE or on the edge or vertex" << std::endl;
    
    if(bsp(a, b, c, peak))
        std::cout << "Point(0, 0) is INSIDE" << std::endl;
    else
        std::cout << "Point(0, 0) is OUTSIDE or on the edge or vertex" << std::endl;

    return (0);
}
