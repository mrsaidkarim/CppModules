/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:12:28 by skarim            #+#    #+#             */
/*   Updated: 2024/06/08 21:18:25 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &);
		virtual ~Animal();
		
		Animal	&operator=(const Animal &);

		void	setType(const std::string &);
		const std::string& getType(void) const;

		virtual void makeSound() const;
};

#endif