/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:11:07 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/12 14:11:51 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl harl;
    // Should work
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    // Should not work
    harl.complain("UNKNOWN");
    harl.complain("");
    harl.complain("DEBUGa");
    harl.complain("aDEBUG");
    harl.complain("ERRORERROR");

    return 0;
}