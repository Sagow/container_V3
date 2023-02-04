/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:22:09 by mdelwaul          #+#    #+#             */
/*   Updated: 2023/02/04 15:23:13 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//based on cppreference.com

//#include "ToDo.hpp"
#pragma once
#include <memory>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <functional>
#include "RBtree.hpp"
#include "RBnode.hpp"
#include "../algorithm.hpp"
#include "../iterator.hpp"

namespace ft
{
	template <
		class Key,                                    			// map::key_type
		class T,                                      			// map::mapped_type
		class Compare = less<Key>,                    			// map::key_compare
		class Allocator = std::allocator<pair<const Key,T> >    // map::allocator_type
	> class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef pair<const Key, T>					value_type;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef bidirectional_iterator< RBnode<const Key, T> >		iterator;
			typedef bidirectional_iterator< RBnode<const Key, T> >	const_iterator;
			typedef std::reverse_iterator<iterator>			reverse_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			class value_compare : public std::binary_function<value_type,value_type,bool>
			{
				friend class map;
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public:
					bool operator()(const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		protected:
			RBtree<Key, T>	_tree;
			allocator_type _alloc;
			key_compare	_comp;

		public:
			map()
			{}
			explicit	map(key_compare &comp, const Allocator &alloc = Allocator()) : _alloc(alloc), _comp(comp)
			{}
			template <class InputIterator>
				map(InputIterator first, InputIterator last, key_compare &comp = Compare(), const Allocator &alloc = Allocator(),
					typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr)
				{
					insert(first, last);
				}
			map(const map &other) : _tree(other.tree), _alloc(other._alloc), _comp(other._comp)
			{}
			~map()
			{
				clear();
			}
			map	&operator= (const map &x)
			{
				if (&x == this)
					return (*this);
				clear();
				insert(x.begin(), x.end());
				return (*this);
			}
			
			//iterators
			iterator	begin()
			{
				return (iterator(_tree.leftest()));
			}
			const_iterator	begin()	const
			{
				return (const_iterator(_tree.leftest()));
			}
			iterator end()
			{
				return (iterator(NULL)); //pas bon
			}
			const_iterator end() const
			{
				return (const_iterator(NULL)); //pas bon
			}
			//toutes les declinaisons

			//Capacity
			bool empty() const
			{
				return (_tree.getSize() == 0);
			}
			size_type size() const
			{
				return (_tree.getSize());
			}
			size_type max_size() const
			{
				return (_alloc.max_size());
			}

			//Element access
			mapped_type& operator[] (key_type &k) const
			{
				iterator tmp = find(k);

				if (tmp == end())
					insert(make_pair(k, mapped_type()));
				tmp = find(k);
				return (tmp->pair.second);
			}
			mapped_type& at (key_type k) const
			{
				RBnode<Key, T>	*node = _tree.find(k);
				if (!node)
				{
					std::ostringstream	oss;

					oss << "map key (which is " << k << ") does not exist";
					throw (std::out_of_range(oss.str()));
				}
				return (node->pair.second);

			}
			/*const mapped_type& at(key_type& k) const
			{
				RBnode<Key, T>	*node = _tree.find(k);
				if (!node)
				{
					std::ostringstream	oss;

					oss << "map key (which is " << k << ") does not exist";
					throw (std::out_of_range(oss.str()));
				}
				return (node->pair.second);
			}*/

			//Modifiers
			pair<iterator,bool> insert (const value_type& val)
			{
				pair<iterator,bool>	res = ft::make_pair(find(val.first), false);
				if (res.first != end())
					res.second = false;
				else
					res.second = true;
				return (res);
			}
			
			iterator insert (iterator position, const value_type& val)
			{
				RBnode<key_type, mapped_type>	*node = NULL;
				(void)position;
				_tree.insertNode(val);
				node = find(val);
				return ((iterator) node);
			}
			template <class InputIterator>
				void insert (InputIterator first, InputIterator last)
				{
					for (InputIterator it = first; it != last; it++)
						_tree.insertNode(*it);
					
				}
			void erase (iterator position)
			{
				_tree.removeNode(*position);
			}
			size_type erase (key_type k)
			{
				RBnode<Key, T>	*toRemove = find(k);
				if (toRemove)
				{
					_tree.removeNode(toRemove);
					return (1);
				}
				return (0);
			}
			template <class InputIterator>
			void erase (InputIterator first, InputIterator last)
			{
				for (InputIterator it = first; it != last; it++)
					_tree.removeNode(it->pair.first);				
			}
			void swap (map& x)
			{
				map	tmp;

				if (_alloc == x._alloc)
				{
					tmp._tree = _tree;
					tmp._comp = _comp;
					_tree = x._tree;
					_comp = x._comp;
					x._tree = tmp._tree;
					x._comp = tmp.c_comp;
				}
				else
				{
					tmp = *this;
					*this = x;
					x = tmp;
				}
			}
			void clear()
			{
				_tree.destroyRecu(_tree.getTrunk());
			}
			
			//Observers
			key_compare key_comp() const
			{
				return (key_compare());

			}
			value_compare value_comp() const
			{
				return (value_compare());
			}

			//Operation
			iterator find (key_type& k) const
			{
				return (iterator(*_tree.find(k)));
			}
			size_type count (key_type k) const
			{
				if (_tree.find(k))
					return (1);
				return (0);
			}
			iterator lower_bound (key_type k)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (it->pair.first >= k)
						return (it);
				}
			}
			const_iterator lower_bound (key_type k) const
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (it->pair.first >= k)
						return ((const_iterator)it);
				}
			}
			iterator upper_bound (key_type& k)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (it->pair.first > k)
						return (it);
				}
			}
			const_iterator upper_bound (key_type& k) const
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (it->pair.first > k)
						return ((const_iterator)it);
				}
			}
			pair<iterator,iterator>             equal_range (key_type& k)
			{
				return (make_pair(lower_bound(k), upper_bound(k)));
			}
			pair<const_iterator,const_iterator> equal_range (key_type& k) const
			{
				return (make_pair(lower_bound(k), upper_bound(k)));
			}

			//Allocator
			allocator_type get_allocator() const
			{
				return (_alloc);
			}
			
	};
};