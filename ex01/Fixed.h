#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath> //pour roundf function

class Fixed {

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8; //8비트는 2^8=256가지를 표현할 수 있다

    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        Fixed(const int intVal);
        Fixed(const float floatVal);

        float   toFloat(void) const;
        int     toInt(void) const;

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif