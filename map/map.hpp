/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:22:09 by mdelwaul          #+#    #+#             */
/*   Updated: 2023/01/26 22:03:11 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//based on cppreference.com

//#include "ToDo.hpp"
#include <memory>
#include <cstddef>
#include <iostream>
#include <sstream>
#include "RBtree.hpp"
#include "RBnode.hpp"
#include "../algorithm.hpp"

namespace ft
{
	template <
		class Key,                                     // map::key_type
		class T,                                       // map::mapped_type
		class Compare = ft::less<Key>,                    // map::key_compare
		class Allocator = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
	> class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const Key, T>					value_type;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef typename  std::map<const Key, T>::iterator		iterator;
			typedef typename  std::map<const Key, T>::const_iterator	const_iterator;
			typedef std::reverse_iterator<iterator>			reverse_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;


		private:
			class value_compare
			{
				private:
					key_compare	_comp;
				
				public:
					typedef bool		result_type;
					typedef value_type	first_arg;
					typedef value_type	second_arg;
				
				value_compare(key_compare c): _comp(c)
				{
				}

				bool operator()(value_type const &x, value_type const &y) const
				{
					return (_comp(x.first, y.first));
				}
			};

		protected:
			RBtree<const Key, T>	_tree;
			Allocator _alloc;
			key_compare	_comp;

		public:
			map()
			{}
			explicit	map(const key_compare &comp, const Allocator &alloc = Allocator()) : _alloc(alloc), _comp(comp)
			{}
			template <class InputIterator>
				map(InputIterator first, InputIterator last, const key_compare &comp = Compare(), const Allocator &alloc = Allocator(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr)
				{	_alloc(alloc);
					 _comp(comp);
					while (first != last)
					{
						insert(first);
						first++;
					}
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
				return (iterator(_tree.rightest())); //pas bon
			}
			const_iterator end() const
			{
				return (const_iterator(_tree.rightest())); //pas bon
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
			mapped_type& operator[] (const key_type& k)
			{
				return ((insert(ft::make_pair(k, mapped_type())).first)->second);
			}
			mapped_type& at (const key_type& k)
			{
				RBnode<Key, T>	*node = _tree.find(k);
				if (!node)
				{
					std::ostringstream	oss;

					oss << "map key (which is " << k << ") does not exist";
					throw (std::out_of_range(oss.str()));
				}
				return (*node);
			}
			const mapped_type& at(const key_type& k) const
			{
				RBnode<Key, T>	*node = _tree.find(k);
				if (!node)
				{
					std::ostringstream	oss;

					oss << "map key (which is " << k << ") does not exist";
					throw (std::out_of_range(oss.str()));
				}
				return (*node);
			}

			//Modifiers
			pair<iterator,bool> insert (const value_type& val)
			{
				pair<iterator,bool>	res;

				res.first = find(val.first);
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
			size_type erase (const key_type& k)
			{
				RBnode<const Key, T>	*toRemove = find(k);
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
				return (value_compare(key_compare()));
			}

			//Operation
			iterator find (const key_type& k)
			{
				return (reinterpret_cast<iterator>(_tree.find(k)));
			}	
			const_iterator find (const key_type& k) const
			{
				return (const_iterator(_tree.find(k)));
			}
			size_type count (const key_type& k) const
			{
				if (_tree.find(k))
					return (1);
				return (0);
			}
			iterator lower_bound (const key_type& k)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (it->pair.first >= k)
						return (it);
				}
			}
			const_iterator lower_bound (const key_type& k) const
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (it->pair.first >= k)
						return ((const_iterator)it);
				}
			}
			iterator upper_bound (const key_type& k)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (it->pair.first > k)
						return (it);
				}
			}
			const_iterator upper_bound (const key_type& k) const
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (it->pair.first > k)
						return ((const_iterator)it);
				}
			}
			pair<iterator,iterator>             equal_range (const key_type& k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			//Allocator
			allocator_type get_allocator() const
			{
				return (_alloc);
			}
			
	};
};