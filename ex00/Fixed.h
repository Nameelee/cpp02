#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8; 

    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits(void) const;//returns the raw value of the fixed-point value
        void setRawBits(int const raw);//sets the raw value of the fixed-point number
};

#endif