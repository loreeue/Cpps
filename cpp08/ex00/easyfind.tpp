/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loruzqui <loruzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:12:13 by loruzqui          #+#    #+#             */
/*   Updated: 2026/01/08 14:40:47 by loruzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	easyfind(const T &cont, const int &n)
{
	if (cont.size() == 0)
		throw EmptyContainerException();

	typename T::const_iterator	i = std::find(cont.begin(), cont.end(), n); //algorithm STL
	if (i != cont.end())
		std::cout << GREEN << "The number" << n << " was found in the container!! :)" << RESET << std::endl;
	else
		throw NotFoundException();
}

const char* EmptyContainerException::what() const throw()
{
	return "The container is empty :(";
}

const char* NotFoundException::what() const throw()
{
	return "The number was not found in the container :(";
}
