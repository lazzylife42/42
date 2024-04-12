/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:07:29 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/12 18:08:20 by smonte-e         ###   ########.fr       */
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


class Fixed
{
public:
    // Public Constructors and Destructor
    Fixed();
    Fixed(Fixed const &src);
    Fixed& operator=(const Fixed &rhs);
    ~Fixed();
    // Public Methods
    void setValue(int value);
    int getValue() const;
    int getRawBits(void) const;

private:
    // Private members
    int _value;
    static const int _fractionalBits = 8;
};

#endif