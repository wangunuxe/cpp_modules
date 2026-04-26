/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:45:28 by jili              #+#    #+#             */
/*   Updated: 2026/01/15 15:45:31 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <sstream>

class Phonebook
{
private :
	Contact contacts[8];
	int	count;//The present number of concacts
	int	next_index;// The next index of contact to fill or overwrite
public:
	Phonebook();// If a class contains primitive types (int, char, etc.), we should declare a constructor to initialize them. 
	~Phonebook();
	
	void	addContact();
	void	searchContact();

};

#endif
