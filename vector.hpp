/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:05:21 by mdelwaul          #+#    #+#             */
/*   Updated: 2022/12/19 16:23:29 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iterator>
#include <memory>
#include <cstring>
#include <vector>
#include "algorithm.hpp"

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
				this->assign(n, value);
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
			const Allocator& alloc= Allocator()) : _ptr(NULL), _alloc(alloc), _size(0), _capacity(0)
			{
				for (InputIterator it = first; it != last; it++)
					_capacity++;
				_ptr = _alloc.allocate(_capacity);
				this->assign(first, last);
			}
			vector(const vector<T,Allocator>& x) : _ptr(NULL), _size(0), _capacity(0)
			{
				assign(x.begin(), x.end());
			}
			~vector()
			{
				clear();
				if (_capacity)
					_alloc.deallocate(_ptr, _capacity);
			};
			vector<T,Allocator>& operator=(const vector<T,Allocator>& x)
			{
				if (&x != this)
					assign(x.begin(), x.end());
				return (*this);
			}
			
			template <class InputIterator>
				typename ft::enable_if<!ft::is_integral<InputIterator>::state>::type
				assign(InputIterator first, InputIterator last)
				{
					erase(begin(), end());
					insert(begin(), first, last);
				}
			
			void assign(size_type n, const T& u)
			{
				erase(begin(), end());
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
				return (reverse_iterator(_ptr + (_size - 1)));
			}
			
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(_ptr + (_size - 1)));
			}
			
			reverse_iterator rend()
			{
				return (reverse_iterator(_ptr - 1));
			}

			const_reverse_iterator rend() const
			{
				return (reverse_iterator(_ptr - 1));
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
				insert(end(), sz-size(), c);
				else if (sz < size())
				erase(begin()+sz, end());
				else
				; // do nothing
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
				pointer ptr;
				
				if (n > max_size() || n < 0)
					throw (std::length_error("vector::reserve")); //aller chercher p 349 du livre pour les classes d'exceptions
				if (!_capacity && !n)
					n = 1;
				if (n > _capacity)
				{
					ptr = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(ptr + i, *(_ptr + i));
						_alloc.destroy(_ptr + i);
					}
					_alloc.deallocate(_ptr, _size);
					_ptr = ptr;	
					_capacity = n;
				}
			}
			// element access:
			reference operator[](size_type n)
			{
				pointer ret = _ptr + n * sizeof(value_type);
				return (*ret);
			}
			
			const_reference operator[](size_type n) const
			{
				pointer ret = _ptr + n * sizeof(value_type);
				return (*ret);
			}

			const_reference at(size_type n) const
			{
				if (!(n < size()))
					throw (std::out_of_range("pouet"));
				pointer ret = _ptr + n * sizeof(value_type);
				return (*ret);
			}
			
			reference at(size_type n)
			{
				if (!(n < size()))
					throw (std::out_of_range("pouet"));
				pointer ret = _ptr + n * sizeof(value_type);
				return (*ret);
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
				insert(end(), x);
			}
			
			void pop_back()
			{
				erase(end()--);
			}
			
			iterator insert(iterator position, const T& x)
			{
				size_type index = position - begin();
				if (_capacity < _size + 1)
				{
					reserve(_capacity * 2);
					position = begin() + index;
				}
				size_type i = _size;
				if (i == index)
					_alloc.construct(_ptr + i, x);
				else
				{
					_alloc.construct(_ptr + i, _ptr[i - 1]);
					i--;
					for(; i > index; i--)
						_ptr[i] = _ptr[i - 1];
					_ptr[i] = x;
				}
				_size++;
				return (position);
			}
			
			void insert(iterator position, size_type n, const T& x)
			{
				if (_capacity < _size + n)
				{
					size_type	index = position - begin();
					if (_size + n <= _capacity * 2)
						reserve(_capacity * 2);
					else
						reserve(_size + n);
					position = begin() + index;
				}
				for (size_type i = 0; i < n; i++)
					position = insert(position, x) + 1;
			}
			
			template <class InputIterator>
				typename ft::enable_if<!ft::is_integral<InputIterator>::state>::type
				insert(iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					position = insert(position, *first) + 1;
					first++;
				}
			}
			
			iterator erase(iterator position)
			{
				size_type	index = position - begin();
				for (size_type i = index; i < _size - 1; i++)
					_ptr[i] = _ptr[i + 1];
				_alloc.destroy(_ptr + index);
				return (iterator(_ptr + index));
			}
			
			iterator erase(iterator first, iterator last)
			{
				int nb = last - first;
				for (int i = 0; i < nb; i++)
					first = erase(first);
				return (first);
			}
			void swap(vector<T,Allocator>& x)
			{
				vector<T,Allocator> tmp(this);
				this = x;
				x = tmp;
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