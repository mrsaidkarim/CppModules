/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:31:04 by skarim            #+#    #+#             */
/*   Updated: 2024/05/07 20:44:37 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contactsNbr = 0;
}

PhoneBook::~PhoneBook()
{
	
}

int		isValidNumber(std::string number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int		isWhiteSpaces(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 9 || str[i] > 13) && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void PhoneBook::addContact() {
    Contact cnt;
    std::string tmp;

    std::cout << "Enter the first name: ";
    do {
        if (!getline(std::cin, tmp))
			return ;
    } while (tmp.empty() || !isWhiteSpaces(tmp));
    cnt.setFirstName(tmp);

    std::cout << "Enter the last name: ";
    do {
        if (!getline(std::cin, tmp))
			return ;
    } while (tmp.empty() || !isWhiteSpaces(tmp));
    cnt.setLastName(tmp);

    std::cout << "Enter the nickname: ";
    do {
        if (!getline(std::cin, tmp))
			return ;
    } while (tmp.empty() || !isWhiteSpaces(tmp));
    cnt.setNickName(tmp);

    std::cout << "Enter the phone number: ";
    do {
        if (!getline(std::cin, tmp))
			return ;
        if (!isValidNumber(tmp)) {
            std::cout << "Phone number must be fully composed of numbers" << std::endl;
            tmp.clear();
        }
    } while (tmp.empty() || !isWhiteSpaces(tmp));
    cnt.setPhoneNumber(tmp);

    std::cout << "Enter the darkest secret: ";
    do {
        if (!getline(std::cin, tmp))
			return ;
    } while (tmp.empty() || !isWhiteSpaces(tmp));
    cnt.setDarkestSecret(tmp);

    this->contacts[this->contactsNbr % 8] = cnt;
    this->contactsNbr++;
}

void	displayString(std::string s)
{
	if (s.length() > 10) {
		std::cout << std::right << std::setw(10) << s.substr(0, 9) + "." << " | ";
	} else {
		std::cout << std::right << std::setw(10) << s << " | ";
	}
}

void	PhoneBook::display()
{
	std::cout << "   Index   | First Name | Last Name  |   Nickname  " << std::endl;
    std::cout << "-----------|------------|------------|------------" << std::endl;
    for (int i = 0; i < contactsNbr && i < 8; i++) {
        std::cout << std::right << std::setw(10) << i << " | ";
        displayString(contacts[i].getFirstName());
        displayString(contacts[i].getLastName());
        displayString(contacts[i].getNickName());
		std::cout << std::endl;
    }
	std::cout << std::endl;
}

void	PhoneBook::searchContact()
{
	std::string input;
	int			index;
	
	if (this->contactsNbr == 0)
	{
		std::cout << "There are no contacts!" << std::endl;
		return ;
	}
	this->display();
	while (1)
	{
		std::cout << "Enter the index to display its contact: " << std::endl;
		if (!getline(std::cin, input))
			exit(1);
		if (!isValidNumber(input) || input.empty() || !isWhiteSpaces(input))
			std::cout << "Invalid input, ";
		else
			break ;
		input.clear();
	}
	index = stoi(input);
	if (index < 0 || index >= this->contactsNbr)
		std::cout << "The index is out of range!" << std::endl;
	else
	{
		std::cout << std::right << std::setw(10) << index << " | ";
        displayString(contacts[index].getFirstName());
        displayString(contacts[index].getLastName());
        displayString(contacts[index].getNickName());
		std::cout << std::endl;
	}
}
