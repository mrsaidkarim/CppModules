/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:32:03 by skarim            #+#    #+#             */
/*   Updated: 2024/06/11 15:28:16 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_HPP
#define MATERIA_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materias[4];
		void clearMaterias();
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif