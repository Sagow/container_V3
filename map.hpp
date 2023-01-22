/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:22:09 by mdelwaul          #+#    #+#             */
/*   Updated: 2023/01/22 17:33:20 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//based on cppreference.com

#include "ToDo.hpp"
#include <memory>
#include <cstddef>
#include "RBtree.hpp"
#include "RBnode.hpp"
#include "algorithm.hpp"

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
			typedef Key										key_type;
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
			RBtree<value_type>	tree;
			Allocator _alloc;
			key_compare	_comp;
			size_type _size;

		public:
			map() : _size(0);
			{}
			explicit	map(const key_compare &comp, const Allocator &alloc = Allocator()) : _alloc(alloc), _comp(comp), _size(0)
			{}
			template <class InputIterator>
				map(InputIterator first, InputIterator last, const key_compare &comp = Compare(), const Allocator &alloc = Allocator()) : _alloc(alloc), _comp(comp)
				{
					while (first != last)
					{
						insert(first);
						first++;
					}
				}
			map(const map &other) : _tree(other.tree), _alloc(other._alloc), _comp(other._comp), _size(other._size)
			{}
			~map()
			{}
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
				return (_size == 0);
			}
			size_type size() const
			{
				return (_size);
			}
			size_type max_size() const
			{
				return (_alloc.max_size());
			}

			//Element access
			mapped_type& operator[] (const key_type& k)
			{
				return ((insert(ft::make_pair(key, data_type())).first)->second);
			}
			mapped_type& at (const key_type& k)
			{
				RBnode<T>	*node = _tree.find(k);
				if (!node)
					throw (std::out_of_range()); //a completer
			}
			const mapped_type& at (const key_type& k) const
			{
				
			}

			//Modifiers
			pair<iterator,bool> insert (const value_type& val)
			{
				
			}
			iterator insert (iterator position, const value_type& val)
			{
				RBnode<value_type>	*node = NULL;
				_tree.insertNode(val);
				node = find(val);
				_size++;
				return ((iterator) &(node.second));
			}
			template <class InputIterator> 
				void insert (InputIterator first, InputIterator last)
				{
					
				}
			void erase (iterator position)
			{
				_tree.removeNode(*position);
				_size--;
			}
			size_type erase (const key_type& k)
			{
				
			}
			void erase (iterator first, iterator last)
			{
				
				
			}
			void swap (map& x)
			{
				map	tmp;

				tmp = *this;
				*this = x;
				x = tmp;
			}
			void clear()
			{
				_tree.destroyRecu(_tree.getTrunk());
			}
			
			//Observers
			key_compare key_comp() const
			{
				return (_comp);
			}
			value_compare value_comp() const
			{
				friend class T;

				return ()
			}

			//Operation
			iterator find (const key_type& k)
			{
			}	
			const_iterator find (const key_type& k) const
			{
				
			}
			size_type count (const key_type& k) const
			{
				if (find(k))
					return (1);
				return (0);
			}
			iterator lower_bound (const key_type& k)
			{
				
			}
			const_iterator lower_bound (const key_type& k) const
			{
				
			}
			iterator upper_bound (const key_type& k)
			{
				
			}
			const_iterator upper_bound (const key_type& k) const
			{
				
			}
			pair<iterator,iterator>             equal_range (const key_type& k)
			{
				
			}
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				
			}

			//Allocator
			allocator_type get_allocator() const
			{
				return (_alloc);
			}
			
	};
};