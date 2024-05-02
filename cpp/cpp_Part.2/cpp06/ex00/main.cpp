/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:48:30 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/02 20:28:32 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	std::cout << std::endl;

	if (argc < 2)
		std::cout << GRN "Usage: ./convert <value_to_cast1> <value_to_cast2> ..." RST << std::endl;
	
	int	i = 1;
	
	while (argv[i])
	{
		std::cout << WHT "=============== OUTPUT " << i << " ===============" RST << std::endl;
		std::cout << BLU "user input:\t\"" << argv[i] << "\"" RST << std::endl;
		
		if (argv[i][0])
			ScalarConverter::convert(argv[i++]);
		else
			std::cout << RED "Argument " << i++ << " is empty." RST << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
