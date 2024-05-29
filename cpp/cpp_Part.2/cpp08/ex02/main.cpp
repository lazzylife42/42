/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:15:22 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/29 16:33:12 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include "color.hpp"

int main()
{
    std::cout << CLR;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << RED << "Top element: " << mstack.top() << RST << std::endl;
    mstack.pop();
    std::cout << GRN << "Size after pop: " << mstack.size() << RST << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    std::cout << YEL << "Iterating with iterator:" << RST << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << BLU << "Iterating with const_iterator:" << RST << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }

    std::cout << MAG << "Iterating with reverse_iterator:" << RST << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << CYA << "Iterating with const_reverse_iterator:" << RST << std::endl;
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.rend();
    while (crit != crite)
    {
        std::cout << *crit << std::endl;
        ++crit;
    }

    std::stack<int> s(mstack);
    return 0;
}
