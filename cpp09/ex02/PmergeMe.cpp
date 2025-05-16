/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:31:15 by skarim            #+#    #+#             */
/*   Updated: 2025/05/15 21:46:37 by skarim           ###   ########.fr       */
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
        dq.clear();
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
                dq = other.dq;
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
                dq.push_back(tmp);
        }
}

void    makePairsVec(const std::vector<int> &arr, std::vector<std::pair<int, int> > &pairs)
{
        for (size_t i = 0; i < arr.size() - 1; i += 2)
        {
                if (arr[i] > arr[i + 1])
                        pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
                else
                        pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
}

void    makePairsDeque(const std::deque<int> &arr, std::deque<std::pair<int, int> > &pairs)
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

void    outputdeq(std::deque<int> &dq, std::string name)
{
        std::cout << "----------------" << name << "-------------\n";
        for (size_t i = 0; i < dq.size(); i++)
        {
                std::cout << dq[i];
                if (i != dq.size() - 1)
                        std::cout << " ";
        }
        std::cout << "\n----------------------------------------\n";
}

int sequence(int k)
{
        if (k == 0)
                return 1;
        if (k == 1)
                return 1;
        return (int)pow(2, k) - sequence(k - 1);
}

// int jacobsthal( int n) {
//         if (n == 0) return 0;
//         if (n == 1) return 1;
//         return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
// }

std::vector<int> generateSeq(int n)
{
        std::vector<int> seq;
        // std::cout << "call for " << n << std::endl;
        seq.push_back(0);
        if (n == 1)
                return seq;
        seq.push_back(1);
        int index = 2;
        int val = 0;
        while (val < n + 1)
        {       
                val = sequence(index);
                seq.push_back(val);
                int prev = sequence(index - 1);
                for (int missed = val - 1; missed > prev; missed--)
                        seq.push_back(missed);
                index++;
        }
        // output(seq, "seq");
        return seq;
}

std::deque<int> generateSeqDeq(int n)
{
        std::deque<int> seq;
        // std::cout << "call for " << n << std::endl;
        seq.push_back(0);
        if (n == 1)
                return seq;
        seq.push_back(1);
        int index = 2;
        int val = 0;
        while (val < n + 1)
        {       
                val = sequence(index);
                seq.push_back(val);
                int prev = sequence(index - 1);
                for (int missed = val - 1; missed > prev; missed--)
                        seq.push_back(missed);
                index++;
        }
        // output(seq, "seq");
        return seq;
}


void    binaryInsertVec(std::vector<int> &mainChain, int ele, int left, int right)
{
        if (right == left)
        {
                mainChain.insert(mainChain.begin() + left, ele);
        }
        else
        {
                int mid = (left + right) / 2;
                if (ele > mainChain[mid])
                        binaryInsertVec(mainChain, ele, mid + 1, right);
                else
                        binaryInsertVec(mainChain, ele, 0, mid);
        }
}

void    binaryInsertDeq(std::deque<int> &mainChain, int ele, int left, int right)
{
        if (right == left)
                mainChain.insert(mainChain.begin() + left, ele);
        else
        {
                int mid = (left + right) / 2;
                if (ele > mainChain[mid])
                        binaryInsertDeq(mainChain, ele, mid + 1, right);
                else
                        binaryInsertDeq(mainChain, ele, 0, mid);
        }
}

void    PmergeMe::sortVector(std::vector<int>   &vec)
{
        std::vector<std::pair<int, int> > pairs;

        makePairsVec(vec, pairs);
        std::vector<int> bigNumbers;
        std::vector<int> smallNumbers;
        for (size_t i = 0; i < pairs.size(); i++)
        {
                bigNumbers.push_back(pairs[i].first);
                smallNumbers.push_back(pairs[i].second);
        }
        // output(bigNumbers, "bigNumbers");
        // output(smallNumbers, "smallNumbers");
        if (bigNumbers.size() > 1)
                sortVector(bigNumbers);
        std::vector<int> mainChain = bigNumbers;

        binaryInsertVec(mainChain, smallNumbers[0], 0, mainChain.size());
        size_t  sequenceLength = smallNumbers.size();
        // if (sequenceLength > 0)
        // {
                std::vector<int> sequence = generateSeq(smallNumbers.size());
                // output(sequence, "jacob");
                for (size_t i = 1; i < sequence.size(); i++)
                        if (sequence[i] < smallNumbers.size())
                                binaryInsertVec(mainChain, smallNumbers[sequence[i]], 0, mainChain.size());
        // }
        if (vec.size() & 1)
                binaryInsertVec(mainChain, vec[vec.size() - 1], 0, mainChain.size());
        vec = mainChain;
}

void    PmergeMe::sortDeque(std::deque<int> &dq)
{
        std::deque<std::pair<int, int> > pairs;

        makePairsDeque(dq, pairs);
        // for (auto it = pairs.begin(); it != pairs.end(); it++)
        // {
        //         std::cout << "(" << it->first << ", " << it->second << ") ";
        // }
        std::deque<int> bigNumbers;
        std::deque<int> smallNumbers;
        for (size_t i = 0; i < pairs.size(); i++)
        {
                bigNumbers.push_back(pairs[i].first);
                smallNumbers.push_back(pairs[i].second);
        }
        // outputdeq(bigNumbers, "bigNumbers");
        // outputdeq(smallNumbers, "smallNumbers");
        if (bigNumbers.size() > 1)
                sortDeque(bigNumbers);
        std::deque<int> mainChain = bigNumbers;
        binaryInsertDeq(mainChain, smallNumbers[0], 0, mainChain.size());
        size_t  sequenceLength = smallNumbers.size();
        // if (sequenceLength > 0) // ymken ghir zeyda
        // {
                std::deque<int> sequence = generateSeqDeq(smallNumbers.size());
                // outputdeq(sequence, "jacob");
                for (size_t i = 1; i < smallNumbers.size(); i++)
                        binaryInsertDeq(mainChain, smallNumbers[sequence[i]], 0, mainChain.size());
        // }
        if (dq.size() & 1)
                binaryInsertDeq(mainChain, dq[dq.size() - 1], 0, mainChain.size());
        dq = mainChain;
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
                clock_t timeVec, timeDq;
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
                        timeDq = clock();
                        sortDeque(dq);
                        timeDq = clock() - timeDq;
                        display(0);
                        displayTimeTaken(timeDq, "deque");
                }
                else
                        std::cout << "already sorted\n";
        }
        catch(const ParsingException& e)
        {
                std::cerr << e.what() << '\n';
        }
}
