/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:12:33 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/30 22:58:43 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::stack<int> st;
    std::string input = argv[1];
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
        {
            int number;
            std::istringstream(token) >> number;
            st.push(number);
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (st.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int result = 0;
            if (token == "+")
                result = b + a;
            else if (token == "-")
                result = b - a;
            else if (token == "*")
                result = b * a;
            else if (token == "/")
            {
                if (a == 0)
                {
                    std::cerr << "Error: Division by zero" << std::endl;
                    return 1;
                }
                result = b / a;
            }
            st.push(result);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }

    if (st.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << st.top() << std::endl;
    return 0;
}
