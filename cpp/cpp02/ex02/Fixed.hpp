/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:07:29 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/15 16:24:18 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
public:
    // Public Constructors and Destructor
    Fixed();
    Fixed(const int val);
    Fixed(const float val);
    Fixed(Fixed const& src);
    Fixed& operator=(const Fixed& rhs);
    ~Fixed();
    // Public Methods
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
    /*  Comparaison Operators   */
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;
    /*  Aritmethic Operators    */
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;
    /*  Incre/Decrementation Operators  */
    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);
    /*  Min/Max */
    static			Fixed	&min(Fixed &f1, Fixed &f2);
    static const	Fixed	&min(const Fixed &f1, const Fixed &f2);
    static			Fixed	&max(Fixed &f1, Fixed &f2);
    static const	Fixed	&max(const Fixed &f1, const Fixed &f2);

private:
    // Private members
    int _value;
    static const int _bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &rhs);

#endif