/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:59:49 by jili              #+#    #+#             */
/*   Updated: 2026/05/02 17:59:50 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

// Base：只有公有虚析构函数
// 虚析构函数使 Base 成为多态类型，dynamic_cast 才能工作
class Base
{
public:
    virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

// 全局函数声明
Base *generate(void);
void  identify(Base *p);
void  identify(Base &p);

#endif
