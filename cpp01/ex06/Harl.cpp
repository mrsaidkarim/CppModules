/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:59:39 by skarim            #+#    #+#             */
/*   Updated: 2024/05/18 17:10:16 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{	
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}
void Harl::error( void )
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain( std::string level )
{
	std::string complaintsLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*complainFunctions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	for(int i = 0; i < 4; i++)
	{
		if (level == complaintsLevels[i])
		{
			switch (i)
			{
			case 0:
				(this->*complainFunctions[0])();
				(this->*complainFunctions[1])();
				(this->*complainFunctions[2])();
				(this->*complainFunctions[3])();
				break;
			case 1:
				(this->*complainFunctions[1])();
				(this->*complainFunctions[2])();
				(this->*complainFunctions[3])();
				break;
			case 2:
				(this->*complainFunctions[2])();
				(this->*complainFunctions[3])();
				break;
			case 3:
				(this->*complainFunctions[3])();
				break;
			default:
				break;
			}
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
