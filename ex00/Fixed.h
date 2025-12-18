#ifdef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {

    private:
        int -fixedPointValue;
        static const int _fractionalBits = 8; 

    public:
        Fixed();
        Fixed(const Fixed& copyCat);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif