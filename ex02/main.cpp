#include <iostream>
#include "Fixed.h"

int main( void ) 
{
    Fixed       a;
    Fixed const b( Fixed( 5.05f ) *  Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;//(a/256)
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return (0);
}

/*
int main(void) {

    Fixed const a(10);
    Fixed const b(20);
    Fixed const c(30);
    Fixed const d(2);

    std::cout << "Values: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    // 2. 산술 연산자 테스트 (+, -, *, /)
    std::cout << "[Arithmetic Operators]" << std::endl;
    
    // 10 + 20 = 30 (c)
    std::cout << "a + b = " << (a + b) << " (Expected: " << c << ")" << std::endl;

    // 30 - 20 = 10 (a)
    std::cout << "c - b = " << (c - b) << " (Expected: " << a << ")" << std::endl;

    // 10 * 2 = 20 (b)
    std::cout << "a * d = " << (a * d) << " (Expected: " << b << ")" << std::endl;

    // 20 / 2 = 10 (a)
    std::cout << "b / d = " << (b / d) << " (Expected: " << a << ")" << std::endl;
    
    std::cout << "------------------------------------------------" << std::endl;

    // 3. 비교 연산자 테스트
    std::cout << "[Comparison Operators]" << std::endl << std::boolalpha;

    std::cout << "a < b  : " << (a < b) << " (Expected: true)" << std::endl;
    std::cout << "b > c  : " << (b > c) << " (Expected: false)" << std::endl;
    std::cout << "a != d : " << (a != d) << " (Expected: true)" << std::endl;
    std::cout << "a == a : " << (a == a) << " (Expected: true)" << std::endl;

    std::cout << "------------------------------------------------" << std::endl;

    return (0);
}
*/