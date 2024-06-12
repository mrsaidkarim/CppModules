/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:49:43 by skarim            #+#    #+#             */
/*   Updated: 2024/06/09 22:19:56 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "----- Animal Tests -----" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "----- Array of Animals -----" << std::endl;
    const int numAnimals = 4;
    const Animal* animals[numAnimals];

    for (int k = 0; k < numAnimals / 2; ++k)
    {
        animals[k] = new Dog();
    }
    for (int k = numAnimals / 2; k < numAnimals; ++k)
    {
        animals[k] = new Cat();
    }

    for (int k = 0; k < numAnimals; ++k)
    {
        delete animals[k];
    }

    Cat originalCat;
    Cat copiedCat = originalCat;
    std::cout << "Original type: " << originalCat.getType() << ", Copy type: " << copiedCat.getType() << std::endl;

    Dog originalDog;
    Dog copiedDog = originalDog;
    std::cout << "Original type: " << originalDog.getType() << ", Copy type: " << copiedDog.getType() << std::endl;

    return 0;
}
