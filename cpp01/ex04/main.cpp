/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:44:06 by skarim            #+#    #+#             */
/*   Updated: 2024/05/18 18:13:53 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int ac, char **av)
{
    std::string s1;
    std::string s2;
    std::string file;

    if (ac != 4)
    {
        std::cout << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    file = av[1];
    s1 = av[2];
    s2 = av[3];
    stdinputFile::ifstream ;
    std::ofstream outputFile;

    inputFile.open(file);
    if (!inputFile.is_open())
    {
        std::cout << "Error: Failed to open input file: " << av[1] << std::endl;
        return (1);
    }
    std::string content;
    std::string line;
    while (getline(inputFile, line))
    {
        content += line;
        if (!inputFile.eof())
            content += "\n";
        line.clear();
    }
    outputFile.open(file + ".replace");
    if (!outputFile.is_open())
    {
        std::cout << "Error: Failed to open output file: " << file + ".replace" << std::endl;
        inputFile.close();
        return (1);
    }
    outputFile << replaceSubstring(content, s1, s2);
    outputFile.close();
    inputFile.close();
    return (0);
}