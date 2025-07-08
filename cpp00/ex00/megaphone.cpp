/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:37:33 by loruzqui          #+#    #+#             */
/*   Updated: 2025/06/11 14:41:52 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	j = 1;
	while(argv && argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			std::cout << (char)std::toupper(argv[j][i]);
			i++;
		}
		j++;
	}
	std::cout << std::endl;
	return (0);
}
