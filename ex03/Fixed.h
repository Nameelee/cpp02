#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed {

    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8; 

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

        bool    operator>(const Fixed& other) const;
        bool    operator<(const Fixed& other) const;
        bool    operator>=(const Fixed& other) const;
        bool    operator<=(const Fixed& other) const;
        bool    operator==(const Fixed& other) const;
        bool    operator!=(const Fixed& other) const;

        Fixed   operator+(const Fixed& other) const;
        Fixed   operator-(const Fixed& other) const;
        Fixed   operator*(const Fixed& other) const;
        Fixed   operator/(const Fixed& other) const;

        //++a
        Fixed&  operator++(void);
        Fixed&  operator--(void);

        //a++
        Fixed operator++(int);
        Fixed operator--(int);

        //static means you can use these function without calling obejct
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif