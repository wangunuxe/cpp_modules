/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:59:40 by jili              #+#    #+#             */
/*   Updated: 2026/05/02 17:59:41 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>   // uintptr_t（C++98 兼容）
# include "Data.hpp"

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &src);
    Serializer &operator=(const Serializer &rhs);
    ~Serializer();

public:
    static uintptr_t serialize(Data *ptr);

    static Data *deserialize(uintptr_t raw);
};

#endif
