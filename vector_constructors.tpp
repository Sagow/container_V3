/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructors.tpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:17:23 by mdelwaul          #+#    #+#             */
/*   Updated: 2022/12/02 20:24:07 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

// 23.2.4.1 construct/copy/destroy:
explicit ft::vector::vector(const Allocator& = Allocator());
explicit ft::vector::vector(size_type n, const T& value = T(),
const Allocator& = Allocator());
template <class InputIterator>
ft::vector::vector(InputIterator first, InputIterator last,
const Allocator& = Allocator());
ft::vector::vector(const vector<T,Allocator>& x);
ft::vector::~vector();
vector<T,Allocator>& operator=(const vector<T,Allocator>& x);

template <class InputIterator>
void ft::vector::assign(InputIterator first, InputIterator last)
{
	erase(begin(), end());
	insert(begin(), first, last);
}

void ft::vector::assign(size_type n, const T& u)
{
	erase(begin(), end());
	insert(begin(), n, t);
}

allocator_type ft::vector::get_allocator() const;