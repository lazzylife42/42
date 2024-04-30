/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:07:29 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/13 21:00:00 by smonte-e         ###   ########.fr       */
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
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

private:
    // Private members
    int _value;
    static const int _bits = 8;
};

#endif