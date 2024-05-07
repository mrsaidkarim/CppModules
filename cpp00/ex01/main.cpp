/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:06:42 by skarim            #+#    #+#             */
/*   Updated: 2024/05/07 11:36:09 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string input;
	PhoneBook	pb;

	std::cout << "Welcome to your phonebook. You type ADD to add a contact,";
	std::cout << "SEARCH to find a contact or EXIT." << std::endl;
	while (true)
	{
		std::cout << "> ";
		if (!getline(std::cin, input))
			break ;
		if (input == "ADD")
			pb.addContact();
		else if (input == "SEARCH")
			pb.searchContact();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "invalid option!" << std::endl;
	}

}