/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:47:07 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/25 15:03:34 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"

#include <string>

class Contact
{
public:
    // Public members
    Contact();
    ~Contact();
    const std::string& getStringRef(const std::string& target) const ;
    void setStringRef(const std::string& target, const std::string& newString);
    
private:
    // Private members
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNum;
    std::string darkSecret;
};

#endif