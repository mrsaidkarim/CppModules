/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-05 16:31:15 by skarim            #+#    #+#             */
/*   Updated: 2025-05-05 16:31:15 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PmergeMe.hpp"


const char *PmergeMe::ParsingException::what() const throw()
{
        return ("Invalid input (invalid positive integer sequence).");
}

PmergeMe::PmergeMe()
{
        vec.clear();
        lst.clear();
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
        *this = other;
}


PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
        if (this != &other)
        {
                vec = other.vec;
                lst = other.lst;
        }
        return (*this);
}

PmergeMe::~PmergeMe()
{
        
}

void PmergeMe::display(bool before)
{
        if (before)
                std::cout << "before:\t";
        else
                std::cout << "after:\t";
        for (size_t i = 0; i < vec.size(); i++)
        {
                std::cout << vec[i];
                if (i != vec.size() - 1)
                        std::cout << " ";
        }
        std::cout << std::endl;
}


void PmergeMe::loadSequence(int ac, char *av[])
{
        for (int i = 1; i < ac; i++)
        {
                int tmp = std::atoi(av[i]);
                vec.push_back(tmp);
                lst.push_back(tmp);
        }
}

void makePairs(const std::vector<int> &arr, std::vector<std::pair<int, int> > &pairs)
{
        for (size_t i = 0; i < arr.size() - 1; i += 2)
        {
                if (arr[i] > arr[i + 1])
                        pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
                else
                        pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
}

void    output(std::vector<int> &vec, std::string name)
{
        std::cout << "----------------" << name << "-------------\n";
        for (size_t i = 0; i < vec.size(); i++)
        {
                std::cout << vec[i];
                if (i != vec.size() - 1)
                        std::cout << " ";
        }
        std::cout << "\n----------------------------------------\n";
}

std::vector<int> generateJacobsthalSeq(int n)
{
        std::vector<int> jacobsthal(n);
        std::vector<int> res(n);
        jacobsthal[0] = 0;
        res[0] = 0;
        if (n > 1)
        {
                jacobsthal[1] = 1;
                res[1] = 1;
        }
        for (int i = 2; i < n; i++)
                jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        int prev = 1;
        int resIndex = 2;
        int jacobIndex = 2;
        while (resIndex < n)
        {
                
                if (res[prev] == jacobsthal[jacobIndex])
                        jacobIndex++;
                else if (res[prev] + 1 < jacobsthal[jacobIndex])
                {
                        res[resIndex++] = jacobsthal[jacobIndex];
                        for (int missed = res[prev] + 1; missed < jacobsthal[jacobIndex] && resIndex < n; missed++)
                        {
                                res[resIndex++] = missed;
                        }
                        prev = resIndex;
                }
                else
                {
                        res[resIndex++] = jacobsthal[jacobIndex]; 
                        prev = resIndex;
                }                
        }
        return (res);
}

void    binarySearch(std::vector<int> &mainChain, int ele, int left, int right)
{
        if (right == left)
                mainChain.insert(mainChain.begin() + left, ele);
        else
        {
                int mid = (left + right) / 2;
                if (ele > mainChain[mid])
                        binarySearch(mainChain, ele, mid + 1, right);
                else
                        binarySearch(mainChain, ele, 0, mid);
        }
}


void    PmergeMe::sortVector(std::vector<int>   &vec)
{
        std::vector<std::pair<int, int> > pairs;

        makePairs(vec, pairs);
        std::vector<int> bigNumbers;
        std::vector<int> smallNumbers;
        for (size_t i = 0; i < pairs.size(); i++)
        {
                bigNumbers.push_back(pairs[i].first);
                smallNumbers.push_back(pairs[i].second);
        }
        if (bigNumbers.size() > 1)
                sortVector(bigNumbers);
        std::vector<int> mainChain = bigNumbers;
        std::vector<int> pendChain;

        binarySearch(mainChain, smallNumbers[0], 0, mainChain.size());
        size_t  jacobsthalSeqLength = smallNumbers.size();
        if (jacobsthalSeqLength > 0)
        {
                std::vector<int> jacobsthalSeq = generateJacobsthalSeq(smallNumbers.size());
                for (size_t i = 1; i < jacobsthalSeq.size(); i++)
                        binarySearch(mainChain, smallNumbers[jacobsthalSeq[i]], 0, mainChain.size());
        }
        if (vec.size() & 1)
                binarySearch(mainChain, vec[vec.size() - 1], 0, mainChain.size());
        vec = mainChain;
}

void PmergeMe::parseInput(int ac, char *av[])
{
        std::string tmp;

        for (int i = 1; i < ac; i++)
        {
                tmp = av[i];
                for (size_t i = 0; i < tmp.size(); i++)
                {
                        if (!isdigit(tmp[i]) && !(i == 0 && tmp[i] == '+'))
                                throw ParsingException();
                }
                long long nbr = std::atoll(tmp.c_str());
                if (nbr > INT_MAX)
                        throw ParsingException();
        }
}

void    displayTimeTaken(clock_t time, std::string container)
{
        std::cout << "Time to process a range of 5 elements with std::" << container << " : " << time * 1000000 << " us\n";
}

void    PmergeMe::run(int ac, char *av[])
{
        try
        {
                clock_t timeVec;
                parseInput(ac, av);
                loadSequence(ac, av);
                display(1);
                if (ac > 2)
                {
                        timeVec = clock();
                        sortVector(vec);
                        timeVec = clock() - timeVec;
                        display(0);
                        displayTimeTaken(timeVec, "vector");
                }
                else
                        std::cout << "already sorted\n";
        }
        catch(const ParsingException& e)
        {
                std::cerr << e.what() << '\n';
        }
}
