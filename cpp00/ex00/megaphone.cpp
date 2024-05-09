/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:28:44 by skarim            #+#    #+#             */
/*   Updated: 2024/05/09 16:14:33 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			std::string input = av[i];
			for (size_t j = 0; j < input.size(); j++)
			{
				input[j] = toupper(input[j]);
			}
			std::cout << input;
		}
		std::cout << std::endl;
	}
}
