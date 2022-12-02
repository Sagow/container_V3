/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:31:57 by mdelwaul          #+#    #+#             */
/*   Updated: 2022/12/02 20:34:04 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

size_type ft::vector::size() const;
size_type ft::vector::max_size() const;
void ft::vector::resize(size_type sz, T c = T())
{
	if (sz > size())
	insert(end(), sz-size(), c);
	else if (sz < size())
	erase(begin()+sz, end());
	else
	; // do nothing
}
size_type ft::vector::capacity() const;
bool ft::vector::empty() const;
void ft::vector::reserve(size_type n);