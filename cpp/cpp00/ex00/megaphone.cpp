/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:57:21 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/04 17:57:24 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    
    for (int i = 1; i < argc; ++i)
    {
        for (char *p = argv[i]; *p != '\0'; ++p)
            *p = std::toupper(*p);
        std::cout << argv[i];
    }
    std::cout << std::endl;
    
    return 0;
}