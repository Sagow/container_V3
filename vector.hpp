/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:05:21 by mdelwaul          #+#    #+#             */
/*   Updated: 2022/12/26 18:42:13 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iterator>
#include <memory>
#include <cstring>
#include <vector>
#include "algorithm.hpp"
#include <iostream>
#include <sstream>

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
		// types:
			typedef 			T										value_type;
			typedef typename 	Allocator::reference					reference;
			typedef typename 	Allocator::const_reference				const_reference;
			typedef typename	std::vector<T>::iterator				iterator; // See 23.1
			typedef typename	std::vector<T>::const_iterator			const_iterator; // See 23.1
			typedef 			std::size_t								size_type; // See 23.1
			typedef 			std::ptrdiff_t							difference_type;// See 23.1
			typedef 			Allocator								allocator_type;
			typedef typename 	Allocator::pointer						pointer;
			typedef typename 	Allocator::const_pointer				const_pointer;
			typedef 			std::reverse_iterator<iterator>			reverse_iterator;
			typedef 			std::reverse_iterator<const_iterator>	const_reverse_iterator;
		private:
			size_type	next_size(size_type n)
			{
				//std::cout << "next_size va se lancer" << std::endl;
				
				size_type res = n > max_size() / 2 ? max_size() : _capacity * 2;
				if (!res)
					res = 1;
				/*while (res < n && res != max_size())
				//{
					res = res > max_size() / 2 ? max_size() : res * 2;
					//std::cout << "res = " << res << " n = " << n << " max = " << max_size() << std::endl;
				//}*/
				if (res < n)
					return (n);
				return (res);
			}
			template <typename Integral>
			void	_init_vec(Integral n, Integral val, true_type)
			{
				assign(n, val);
			}

			template <typename InputIterator>
			void	_init_vec(InputIterator first, InputIterator last, false_type)
			{
				size_type n = 0;
				InputIterator tmp = first;
				while (tmp != last)
				{
					n++;
					tmp++;
				}
				reserve(n);
				assign(first, last);
			}
			
			void	check_index(size_type index)
			{
				if (!(index < size()))
				{
					std::ostringstream	print;
					
					print << "vector::_M_range_check: __n (which is " << index << ") >= this->size() (which is " << _size << ")";
					throw (std::out_of_range(print.str()));
				}
			}
			
		protected:
			pointer _ptr;
			Allocator _alloc;
			size_type _size;
			size_type _capacity;
			
		public:
			// 23.2.4.1 construct/copy/destroy:
			explicit vector(const Allocator& alloc = Allocator()): _ptr(NULL), _alloc(alloc), _size(0), _capacity(0){}
			explicit vector(size_type n, const T& value = T(),
			const Allocator& alloc = Allocator()) : _ptr(NULL), _alloc(alloc), _size(0), _capacity(0)
			{
				reserve(n);
				this->assign(n, value);
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
			const Allocator& alloc= Allocator()) : _ptr(NULL), _alloc(alloc), _size(0), _capacity(0)
			{
				//std::cout << "Vector assign " << std::endl;
				/*for (InputIterator it = first; it != last; it++)
					_capacity++;
				_ptr = _alloc.allocate(_capacity);
				this->assign(first, last);*/
				typedef typename ft::is_integral<InputIterator>	_Integral;

				_init_vec(first, last, _Integral());
			}
			vector(const vector<T,Allocator>& x) : _ptr(NULL), _alloc(x._alloc), _size(0), _capacity(0)
			{
				//std::cout << "Copy constr " << std::endl;
				reserve(x._size);
				assign(x.begin(), x.end());
				//std::cout << "res : " << *(begin()) << " a +" << end() - begin() << " size = " << _size << std::endl;

			}
			~vector()
			{
				clear();
				if (_capacity)
					_alloc.deallocate(_ptr, _capacity);
			};
			vector<T,Allocator>& operator=(const vector<T,Allocator>& x)
			{
				//std::cout << "=" << std::endl;
				_alloc = x._alloc;
				if (&x != this)
					assign(x.begin(), x.end());
				return (*this);
			}
			
			template <class InputIterator>
				typename ft::enable_if<!ft::is_integral<InputIterator>::state>::type
				assign(InputIterator first, InputIterator last)
				{
					clear();
					//std::cout << "assign de " << *first << " a +" << last - first << std::endl;
					insert(begin(), first, last);
				}
			
			void assign(size_type n, const T& u)
			{

				clear();
				//std::cout << "assign va se lancer" << std::endl;
				insert(begin(), n, u);
			}
			
			allocator_type get_allocator() const
			{
				return (_alloc);
			}
			
			// iterators:
			iterator begin()
			{
				return (iterator(_ptr));
			}
			
			const_iterator begin() const
			{
				return(const_iterator(_ptr));
			}
			
			iterator end()
			{
				return (iterator(_ptr + _size));
			}
			
			const_iterator end() const
			{
				return(const_iterator(_ptr + _size));
			}
			
			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}
			
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}
			
			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}
			// 23.2.4.2 capacity:
			size_type size() const
			{
				return (_size);
			}
			size_type max_size() const
			{
				return (_alloc.max_size());
			}
			void resize(size_type sz, T c = T())
			{
				if (sz > size())
				{
					reserve(next_size(sz));
					insert(end(), sz-size(), c);
				}
				else if (sz < size())
				erase(begin()+sz, end());
			}
			size_type capacity() const
			{
				return (_capacity);
			}
			
			bool empty() const
			{
				return (_size == 0);
			}
			
			void reserve(size_type n)
			{
				pointer ptr = _ptr;
				size_t	capacity = _capacity;
				//std::cout << "reserve va se lancer" << std::endl;

				
				if (n > max_size())
					throw (std::length_error("vector::reserve")); //aller chercher p 349 du livre pour les classes d'exceptions
				if (!_capacity && !n)
					n = 1;
				if (n > _capacity)
				{
					_capacity = n;
					_ptr = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(_ptr + i, *(ptr + i));
						_alloc.destroy(ptr + i);
					}
					_alloc.deallocate(ptr, capacity);
				}
			}
			// element access:
			reference operator[](size_type n)
			{
				/*pointer ret = _ptr + n;
				return (*ret);*/
				return (_ptr[n]);
			}
			
			const_reference operator[](size_type n) const
			{
				/*pointer ret = _ptr + n;
				return (*ret);*/
				return (_ptr[n]);
			}

			const_reference at(size_type n) const
			{
				check_index(n);
				/*pointer ret = _ptr + n;
				return (*ret);*/
				return (_ptr[n]);
				
			}
			
			
			reference at(size_type n)
			{
				check_index(n);
				/*pointer ret = _ptr + n;
				return (*ret);*/
				return (_ptr[n]);
			}
			
			reference front()
			{
				return (*_ptr);
			}
			
			const_reference front() const
			{
				return (*_ptr);
			}
			
			reference back()
			{
				pointer	ret = _ptr + (_size - 1);
				return (*ret);
			}
			
			const_reference back() const
			{
				pointer	ret = _ptr + (_size - 1);
				return (*ret);
			}
			
			// 23.2.4.3 modifiers:
			void push_back(const T& x)
			{
				//std::cout << "dans push_back" << std::endl;
				insert(end(), x);
				/*reserve(_size + 1);
				_alloc.construct(_ptr + _size, x);
				_size++;*/
			}
			
			void pop_back()
			{
				if (_size)
				{
					_alloc.destroy(_ptr + _size - 1);
					_size--;
				}
			}
			
			iterator insert(iterator position, const T& x)
			{
					//std::cout << "insert a " << &position << std::endl;
			
				size_type index = position - begin();
				if (_capacity < _size + 1)
				{
					reserve(next_size(_size + 1));
					//std::cout << "on a reserve " << _capacity << " pour " << _size + 1 << std::endl;
					position = begin() + index;
				}
				size_type i = _size;
				if (i == index)
					_alloc.construct(_ptr + i, x);
				else
				{
					//std::cout << "le else" << std::endl;
					
					_alloc.construct(_ptr + i, _ptr[i - 1]);
					i--;
					for(; i > index; i--)
						_ptr[i] = _ptr[i - 1];
					_ptr[i] = x;
				}
				_size++;
				//std::cout << "a inse a " << &position << std::endl;

					//std::cout << "derniere val" << _ptr[i] << std::endl;
				return (position);
			}
			
			void insert(iterator position, size_type n, const T& x)
			{

				if (_capacity < _size + n)
				{
					size_type	index = position - begin();
				//std::cout << "insert va se lancer" << std::endl;
					reserve(next_size(_size + n));
					position = begin() + index;
				}
				for (size_type i = 0; i < n; i++)
					position = insert(position, x) + 1;
			}
			
			template <class InputIterator>
				typename ft::enable_if<!ft::is_integral<InputIterator>::state>::type
				insert(iterator position, InputIterator first, InputIterator last)
			{
				//std::cout << "c est le bon" << std::endl;
				for (; first != last; first++)
				{
					position = insert(position, *first);
					position++;
					//std::cout << &position << std::endl;
				}
			}
			
			iterator erase(iterator position)
			{
				return (erase(position, position + 1));
			}
			
			iterator erase(iterator first, iterator last)
			{
				size_type	dist = last - first;
				if (!dist)
					return (first);
				size_type	start = first - begin();
				
				size_type	i = start;
				while (i < _size - dist)
				{
					_alloc.destroy(_ptr + i);
					_alloc.construct(_ptr + i, *(_ptr + i + dist));
					i++;
				}
				while (i < _size)
				{
					_alloc.destroy(_ptr + i);
					i++;
				}
				_size -= dist;
				return (first);
			}
			void swap(vector<T,Allocator>& x)
			{
				pointer	tmp_ptr = _ptr;
				allocator_type	tmp_alloc = _alloc;
				size_type	tmp_size = _size;
				size_type	tmp_capacity = _capacity;
				
				_ptr = x._ptr;
				_alloc = x._alloc;
				_size = x._size;
				_capacity = x._capacity;
				x._ptr = tmp_ptr;
				x._alloc = tmp_alloc;
				x._size = tmp_size;
				x._capacity = tmp_capacity;
			}
			void clear()
			{
				difference_type i = 0;
				for (iterator it = begin(); it != end(); it++)
					_alloc.destroy(_ptr + i++);
				_size = 0;
			}
	};
	
	template <class T, class Allocator>
	bool operator==(const vector<T,Allocator>& x,
	const vector<T,Allocator>& y)
	{
		return (ft::equal(x.begin(), x.end(), y.begin(), y.end()));
	}
	
	template <class T, class Allocator>
	bool operator< (const vector<T,Allocator>& x,
	const vector<T,Allocator>& y)
	{
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}
	
	template <class T, class Allocator>
	bool operator!=(const vector<T,Allocator>& x,
	const vector<T,Allocator>& y)
	{
		return (!(x==y));
	}
	
	template <class T, class Allocator>
	bool operator> (const vector<T,Allocator>& x,
	const vector<T,Allocator>& y)
	{
		return (y < x);
	}
	
	template <class T, class Allocator>
	bool operator>=(const vector<T,Allocator>& x,
	const vector<T,Allocator>& y)
	{
		return (!(x < y));
	}
	
	template <class T, class Allocator>
	bool operator<=(const vector<T,Allocator>& x,
	const vector<T,Allocator>& y)
	{
		return (!(y < x));
	}
	
	// specialized algorithms:
	template <class T, class Allocator>
	void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
	{
		x.swap(y);
	}
};