/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:05:21 by mdelwaul          #+#    #+#             */
/*   Updated: 2022/12/05 21:52:45 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iterator>
#include <memory>
#include <cstring>


namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
		// types:
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef std::iterator iterator; // See 23.1
			typedef std::const_iterator const_iterator; // See 23.1
			typedef std::size_t size_type; // See 23.1
			typedef std::ptrdiff_t difference_type;// See 23.1
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef std::reverse_iterator<iterator> reverse_iterator;
			typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
			
		protected:
			pointer _ptr;
			Allocator _alloc;
			difference_type _size;
			difference_type _capacity;
			
		public:
			// 23.2.4.1 construct/copy/destroy:
			explicit vector(const Allocator& = Allocator());
			explicit vector(size_type n, const T& value = T(),
			const Allocator& = Allocator()) : _ptr(NULL), _size(0), _capacity(0)
			{
				this->assign(n, value);
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
			const Allocator& = Allocator()) : _ptr(NULL), _size(0), _capacity(0)
			{
				for (InputIterator it = first; it != last; it++)
					_capacity++;
				_ptr = _alloc.allocate(_capacity * sizeof(value_type));
				this->assign(first, last);
			}
			vector(const vector<T,Allocator>& x) : _ptr(NULL), _size(0), _capacity(0);
			~vector()
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					_alloc.destroy(it);
				if (_capacity)
					_alloc.deallocate(_ptr, _capacity * sizeof(value_type))
			};
			vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				erase(begin(), end());
				insert(begin(), first, last);
			};
			void assign(size_type n, const T& u)
			{
				erase(begin(), end());
				insert(begin(), n, t);
			}
			allocator_type get_allocator() const
			{
				return (_alloc);
			}
			// iterators:
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;
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
				return (_size == 0)
			}
			void reserve(size_type n)
			{
				pointer ptr;
				
				if (n > max_size())
					throw (length_error); //aller chercher p 349 du livre pour les classes d'exceptions
				if (n > _capacity)
				{
					ptr = _alloc.allocate_at_least(n * sizeof(value_type));
					std::memcpy(ptr, _ptr, _size * sizeof(value_type));
					_alloc.deallocate(_ptr, _size * sizeof(value_type));
					_ptr = ptr;	
				}
			}
			// element access:
			reference operator[](size_type n)
			{
				return (_ptr + n * sizeof(value_type));
			}
			
			const_reference operator[](size_type n) const
			{
				return (_ptr + n * sizeof(value_type));
			}

			const_reference at(size_type n) const
			{
				if (!(n < size))
					throw (out_of_range);
				return (_ptr + n * sizeof(value_type));
			}
			
			reference at(size_type n)
			{
				if (!(n < size))
					throw (out_of_range);
				return (_ptr + n * sizeof(value_type));
			}
			
			reference front()
			{
				return (_ptr);
			}
			
			const_reference front() const
			{
				return (_ptr);
			}
			
			reference back()
			{
				return (_ptr + (_size - 1));
			}
			
			const_reference back() const
			{
				return (_ptr + (_size - 1));
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
				difference_type toMove = 0;
				if (_capacity == _size)
					reserve(_capacity + 1);
				for (iterator it = position; it != end(); it++)
					toMove++;
				memmove(position + 1, position, toMove * sizeof(value_type));
				*position = x;
				_size++;
				return (position);
			}
			
			void insert(iterator position, size_type n, const T& x)
			{
				difference_type toMove = 0;
				if (_size + n < _capacity)
					reserve(_capacity + 1);
				for (iterator it = position; it != end(); it++)
					toMove++;
				memmove(position + n, position, toMove * sizeof(value_type));
				for (difference_type i = 0; i < n ; i++)
				{
					*position = x;
					position++;
				}
				_size += n;
			}
			
			template <class InputIterator>
			void insert(iterator position,
			InputIterator first, InputIterator last)
			{
				difference_type toAdd = 0;
				difference_type toMove = 0;
				
				for (InputIterator it = first; it != last; it++)
					toAdd++;
				if (_capacity == _size)
					reserve(_capacity + 1);
				for (iterator it = position; it != end(); it++)
					toMove++;
				memmove(position + toAdd, position, toMove * sizeof(value_type));
				while (first != last)
				{
					*position = *first;
					position++;
					first++;
				}
				_size += toAdd;
			}
			
			iterator erase(iterator position)
			{
				difference_type toMove;
				if (_size > 0)
				{
					for (iterator it = position; it != end(); it++)
						toMove++;
					_alloc.destroy(position);
					memmove(position, position + 1, toMove * sizeof(value_type));
					_size--;
				}
				return (position);
			}
			
			iterator erase(iterator first, iterator last)
			{
				difference_type toMove = 0;
				for (iterator rm = first; rm != last; rm++)
				{
					_alloc.destroy(rm);
					_size--;
				}
				for (iterator it = last; it != end(); it++)
					toMove++;
				memmove(first, last, toMove * sizeof(value_type));
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
				for (iterator it = begin(); it != end(); it++)
					_alloc.destroy(it);
				_size = 0;
			}
	};
	template <class T, class Allocator>
	bool operator==(const vector<T,Allocator>& x,
	const vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator< (const vector<T,Allocator>& x,
	const vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator!=(const vector<T,Allocator>& x,
	const vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator> (const vector<T,Allocator>& x,
	const vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator>=(const vector<T,Allocator>& x,
	const vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator<=(const vector<T,Allocator>& x,
	const vector<T,Allocator>& y);
	// specialized algorithms:
	template <class T, class Allocator>
	void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
	{
		x.swap(y);
	}
}

#include "vector_constructors.tpp"
#include "vector_iterators.tpp"
#include "vector_capacity.tpp"