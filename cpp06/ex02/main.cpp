/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <skarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:25:53 by skarim            #+#    #+#             */
/*   Updated: 2025/03/12 00:39:14 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

int main(void)
{
    Base *base = generate();

    identify(base);
    identify(*base);
    delete base;
    return (0);
}
