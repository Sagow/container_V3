/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:22:09 by mdelwaul          #+#    #+#             */
/*   Updated: 2023/02/27 19:07:59 by tmoragli         ###   ########.fr       */
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
#include <iterator>
#include "RBtree.hpp"
#include "RBnode.hpp"
#include "algorithm.hpp"
#include "bidirectional_iterator.hpp"

namespace ft
{
	template <
		class Key,                                    			// map::key_type
		class T,                                      			// map::mapped_type
		typename Compare = std::less<Key>,                    			// map::key_compare
		class Allocator = std::allocator<pair<const Key,T> >    // map::allocator_type
	> class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef pair<const Key, T>						value_type;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef bidirectional_iterator< value_type, RBnode<const Key, T> >		iterator;
			typedef bidirectional_iterator< const value_type, RBnode<const Key, T> >	const_iterator;
			typedef reverse_bidirectional_iterator<iterator>			reverse_iterator;
			typedef reverse_bidirectional_iterator<const_iterator>	const_reverse_iterator;

		private:
			class value_compare// : public std::binary_function<value_type,value_type,bool>
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
			typedef typename allocator_type::template rebind<RBnode<const Key, T> >::other	nodeAllocator;
			typedef RBtree<const Key, T, Compare, nodeAllocator> Tree;
			allocator_type _alloc;
			key_compare	_comp;
			Tree	_tree;

		public:
			explicit	map(const key_compare &comp = Compare(), const Allocator &alloc = Allocator()) : _alloc(alloc), _comp(comp), _tree(comp, nodeAllocator())
			{
			}
			template <class InputIterator>
				map(InputIterator first, InputIterator last, const key_compare &comp = Compare(), const Allocator &alloc = Allocator()/*,
					typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr*/)
					: _alloc(alloc), _comp(comp), _tree(comp, nodeAllocator())
				{
					insert(first, last);
				}
			map(const map<Key, T, Compare, Allocator> &other) : _alloc(other._alloc), _comp(other._comp), _tree(Compare(), nodeAllocator())
			{
				insert(other.begin(), other.end());
			}
			~map()
			{
			}

			map<Key, T, Compare, Allocator>	&operator= (const map<Key, T, Compare, Allocator> &x)
			{
				if (&x == this)
					return (*this);
				_tree = x._tree;
				return (*this);
			}

			//iterators
			iterator	begin()
			{
				return (_tree.leftest());
			}
			const_iterator	begin()	const
			{
				return (_tree.leftest());
			}
			iterator end()
			{
				return (iterator(_tree._endNode));
			}
			const_iterator end() const
			{
				return (const_iterator(_tree._endNode));
			}
			//toutes les declinaisons
			reverse_iterator rbegin()
            {
                reverse_iterator tmp = end();
                return (tmp);
            }
			const_reverse_iterator rbegin() const
            {
                const_reverse_iterator tmp = end();
                return (tmp);
            }
			reverse_iterator rend()
            {
                reverse_iterator tmp = begin();
                return (tmp);
            }
			const_reverse_iterator rend() const
            {
                reverse_iterator tmp = begin();
                return (tmp);
            }

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
			mapped_type& operator[] (const key_type &k)
			{
				iterator tmp = find(k);

				if (tmp.base()->isEndNode) {
					insert(ft::make_pair(k, mapped_type()));
				    tmp = find(k);
                }
				return (tmp->second);
			}

			mapped_type& at(key_type k) const
			{
				RBnode<const Key, T>	*node = _tree.find(k);
				if (!node)
				{
					std::ostringstream	oss;

					oss << "map key (which is " << k << ") does not exist";
					throw (std::out_of_range(oss.str()));
				}
				return (node->pair.second);

			}
			
			//Modifiers
			pair<iterator,bool> insert (const value_type& val)
			{
                iterator    it = find(val.first);
                if (it.base()->isEndNode == false)
                    return (ft::make_pair(it, false));
                _tree.insertNode(val);
                it = find(val.first);
                if (it.base()->isEndNode == false)
                    return (ft::make_pair(it, true));
                return (ft::make_pair(it, false));
			}
			
			iterator insert (iterator position, const value_type& val)
			{
                iterator    it = find(val.first);
                if (it != end())
                    return (it);
				RBnode<const key_type, mapped_type>	*node = NULL;
				(void)position;
				_tree.insertNode(val);
				node = _tree.find(val.first);
				return (iterator(node));
			}
			template <class InputIterator>
				void insert (InputIterator first, InputIterator last)
				{
					for (InputIterator it = first; it != last; it++)
						insert(*it);
					
				}
			void erase (iterator position)
			{
				_tree.deleteNode(position->first);
			}
			size_type erase (const key_type k)
			{
				if (find(k) != end())
				{
                    _tree.deleteNode(k);
                    return (1);
				}
				return (0);
			}
			template <class InputIterator>
			void erase (InputIterator first, InputIterator last)
			{
                if (first == begin() && last == end())
                {
                    clear();
                    return ;
                }
                InputIterator   tmp;
                RBnode<const Key, T>    *nextPtr = NULL;
                RBnode<const Key, T>    *lastPtr = last.base();
				for (RBnode<const Key, T> *currentPtr = first.base(); currentPtr != lastPtr; currentPtr = nextPtr)
                {
                    tmp = InputIterator(currentPtr);
                    tmp++;
                    nextPtr = tmp.base();
                    _tree.deleteNode(currentPtr->getPair().first);
                }
			}

			void swap (map<Key, T, Compare, Allocator>& x)
			{
				_tree.swap(x._tree);
			}
			
			void clear()
			{
				_tree.destroyRecu(_tree.getTrunk());
				_tree._trunk = NULL;
				_tree._endNode->parent = NULL;
				_tree._startNode->parent = NULL;
			}
			
			//Observers
			key_compare key_comp() const
			{
				return (_comp);

			}
			value_compare value_comp() const
			{
				return (value_compare(_comp));
			}

			//Operation
			iterator find (const key_type& k)
			{
				return (iterator(_tree.find(k)));
			}

			const_iterator find(const key_type& k) const
			{
				return (const_iterator(_tree.find(k)));
			}
			
			size_type count (const key_type k) const
			{
                RBnode<const Key, T>    *found = _tree.find(k);
				if (!found->isEndNode)
					return (1);
				return (0);
			}
			iterator lower_bound (const key_type& k)
			{
				iterator it;
				for (it = begin(); it != end(); it++)
				{
					if (!_comp(it->first, k))
						break ;
				}
				return (it);
			}
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it = begin();
				for (; it != end(); it++)
				{
					if (!_comp(it->first, k))
						break ;
				}
				return (it);
			}
			iterator upper_bound (const key_type& k)
			{
				iterator it;
				for (it = begin(); it != end(); it++)
				{
					if (_comp(k, it->first))
						break ;
				}
				return (it);
			}
			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator it;
				for (it = begin(); it != end(); it++)
				{
					if (_comp(k, it->first))
						break ;
				}
				return (it);
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
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator==(const map<Key,T,Compare,Allocator>& x,
	const map<Key,T,Compare,Allocator>& y)
	{
		return !(x < y || y < x);
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator< (const map<Key,T,Compare,Allocator>& x,
	const map<Key,T,Compare,Allocator>& y)
	{
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator!=(const map<Key,T,Compare,Allocator>& x,
	const map<Key,T,Compare,Allocator>& y)
	{
		return (!(x == y));
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator> (const map<Key,T,Compare,Allocator>& x,
	const map<Key,T,Compare,Allocator>& y)
	{
		return (y < x);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator>=(const map<Key,T,Compare,Allocator>& x,
	const map<Key,T,Compare,Allocator>& y)
	{
		return(!(x < y));
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<=(const map<Key,T,Compare,Allocator>& x,
	const map<Key,T,Compare,Allocator>& y)
	{
		return (!(x > y));
	}

	// specialized algorithms:
	template <class Key, class T, class Compare, class Allocator>
	void swap(map<Key,T,Compare,Allocator>& x,
	map<Key,T,Compare,Allocator>& y)
	{
		x.swap(y);
	}
};