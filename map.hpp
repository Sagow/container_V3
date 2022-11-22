/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:22:09 by mdelwaul          #+#    #+#             */
/*   Updated: 2022/11/22 19:01:49 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//based on cppreference.com

#include "ToDo.hpp"
#include <memory>
#include <cstddef>

namespace ft
{
	template <
		class Key,                                     // map::key_type
		class T,                                       // map::mapped_type
		class Compare = ft::less<Key>,                     // map::key_compare
		class Allocator = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
	> class map
	{
		public:
			typedef Key										key_tape;
			typedef T										mapped_type;
			typedef ft::pair<const Key, T>					value_type;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef Allocator::pointer						pointer;
			typedef Allocator::const_pointer				const_pointer;
			typedef ft::iterator							iterator;
			typedef ft::const_iterator						const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			

		protected:
			
	};
};