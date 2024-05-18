/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:47:50 by skarim            #+#    #+#             */
/*   Updated: 2024/05/18 16:48:10 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string replaceSubstring(std::string content, std::string s1, std::string s2)
{
    std::string result;
    size_t      pos;
    size_t      prev_pos;

    pos = 0;
    prev_pos = 0;
    if (s1.empty())
        return (content);
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(prev_pos, pos - prev_pos);
        result += s2;
        pos += s1.length();
        prev_pos = pos;
    }
    result += content.substr(prev_pos);
    return (result);
}