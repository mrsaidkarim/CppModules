/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-05 16:31:11 by skarim            #+#    #+#             */
/*   Updated: 2025-05-05 16:31:11 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <limits.h>

class PmergeMe
{
    private:
        std::vector<int>    vec;
        std::list<int>      lst;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        class ParsingException: public std::exception
        {
            public:
                const char *what() const throw();
        };

        void    run(int ac, char *av[]);
        void    loadSequence(int ac, char *av[]);
        void    display(bool before);
        void    sortVector(std::vector<int> &vec);
        void parseInput(int ac, char *av[]);
        
};