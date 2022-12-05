/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructors.tpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:17:23 by mdelwaul          #+#    #+#             */
/*   Updated: 2022/12/04 20:40:42 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "vector.hpp"

// 23.2.4.1 construct/copy/destroy:
namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	explicit ft::vector::vector(const Allocator& = Allocator());

	template <class T, class Allocator = std::allocator<T> >
	explicit ft::vector::vector(size_type n, const T& value = T(),
	const Allocator& = Allocator());
	
	template <class InputIterator, class T, class Allocator = std::allocator<T> >
	ft::vector::vector(InputIterator first, InputIterator last,
	const Allocator& = Allocator());
	
	template <class T, class Allocator = std::allocator<T> >
	ft::vector::vector(const vector<T,Allocator>& x);
	
	ft::vector::~vector();

	template <class T, class Allocator = std::allocator<T> >
	vector<T,Allocator>& operator=(const vector<T,Allocator>& x);

	template <class InputIterator>
	void ft::vector::assign(InputIterator first, InputIterator last)
	{
		erase(begin(), end());
		insert(begin(), first, last);
	};

	template <class T, class Allocator = std::allocator<T> >
	void ft::vector::assign(size_type n, const T& u)
	{
		erase(begin(), end());
		insert(begin(), n, t);
	}

	allocator_type ft::vector::get_allocator() const;
}