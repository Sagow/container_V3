#pragma once
#include "iterator_traits.hpp"

namespace ft
{
		
	template <class T>
		class const_random_access_iterator : public iterator_traits<T*>
		{
			public:
				typedef typename iterator_traits<T*>::difference_type			difference_type;
				typedef typename iterator_traits<T*>::value_type				value_type;
				typedef typename iterator_traits<T*>::pointer					pointer;
				typedef typename iterator_traits<T*>::reference					reference;
				typedef std::random_access_iterator_tag	iterator_category;

			private:
				pointer		_ptr;

			public:
				const_random_access_iterator(void): _ptr(NULL)
				{}

				const_random_access_iterator(pointer ptr): _ptr(ptr)
				{}

				const_random_access_iterator(const random_access_iterator<T> &src): _ptr(src.operator->())
				{}

				const_random_access_iterator(const const_random_access_iterator &src): _ptr(src._ptr)
				{}

				~const_random_access_iterator()
				{}

				const_random_access_iterator	&operator=(const const_random_access_iterator &src)
				{
					if (&src != this)
						_ptr = src._ptr;
					return (*this);
				}

				bool	operator==(const const_random_access_iterator &other)
				{
					if (_ptr == other._ptr)
						return (true);
					return (false);
				}
				bool	operator!=(const const_random_access_iterator &other)
				{
					return (!operator==(other));
				}
				bool	operator<(const const_random_access_iterator &other)
				{
					return (_ptr < other._ptr);
				}

				bool	operator<=(const const_random_access_iterator &other)
				{
					return (operator<(other) || operator==(other));
				}

				bool	operator>(const const_random_access_iterator &other)
				{
					return (!operator<=(other));
				}

				bool	operator>=(const const_random_access_iterator &other)
				{
					return (!operator<(other));
				}

				const_random_access_iterator &operator++()
				{
					_ptr++;
					return (*this);
				}
				const_random_access_iterator &operator--()
				{
					_ptr--;
					return (*this);
				}

				const_random_access_iterator operator++(int)
				{
					const_random_access_iterator save = *this;
					_ptr++;;
					return (save);
				}
				const_random_access_iterator operator--(int)
				{
					const_random_access_iterator save = *this;
					_ptr--;
					return (save);
				}

				const_random_access_iterator &operator+=(difference_type n)
				{
					_ptr += n;
					return (*this);
				}
				const_random_access_iterator &operator-=(difference_type n)
				{
					_ptr -= n;
					return (*this);
				}

				const_random_access_iterator operator+(difference_type n)
				{
					return (_ptr + n);
				}
				const_random_access_iterator operator-(difference_type n)
				{
					return (_ptr - n);
				}

				difference_type operator-(const const_random_access_iterator &other)
				{
					return (_ptr - other._ptr);
				}

				reference operator* (void)
				{
					return(*_ptr);
				}

				pointer operator-> (void) const
				{
					return (_ptr);
				}

				reference operator[](difference_type n)
				{
					return (*(_ptr + n));
				}

				pointer	base() const
				{
					return (_ptr);
				}
		};

	template <typename iterator>
		class reverse_const_random_access_iterator
		{
			public:
				typedef typename iterator::difference_type		difference_type;
				typedef typename iterator::value_type			value_type;
				typedef typename iterator::pointer				pointer;
				typedef typename iterator::reference			reference;
				typedef typename iterator::iterator_category	iterator_category;

			private:
				pointer		_ptr;

			public:
				reverse_const_random_access_iterator(void): _ptr(NULL)
				{}

				reverse_const_random_access_iterator(pointer ptr): _ptr(ptr)
				{}

				reverse_const_random_access_iterator(const reverse_const_random_access_iterator &src): _ptr(src._ptr)
				{}

				reverse_const_random_access_iterator(const const_random_access_iterator<value_type> &src): _ptr(src.operator->() - 1)
				{}

				~reverse_const_random_access_iterator()
				{}

				reverse_const_random_access_iterator	&operator=(const reverse_const_random_access_iterator &src)
				{
					if (&src != this)
						_ptr = src._ptr;
					return (*this);
				}

				bool	operator==(const reverse_const_random_access_iterator &other)
				{
					if (_ptr == other._ptr)
						return (true);
					return (false);
				}
				bool	operator!=(const reverse_const_random_access_iterator &other)
				{
					return (!operator==(other));
				}
				bool	operator<(const reverse_const_random_access_iterator &other)
				{
					return (_ptr < other._ptr);
				}

				bool	operator<=(const reverse_const_random_access_iterator &other)
				{
					return (operator<(other) || operator==(other));
				}

				bool	operator>(const reverse_const_random_access_iterator &other)
				{
					return (!operator<=(other));
				}

				bool	operator>=(const reverse_const_random_access_iterator &other)
				{
					return (!operator<(other));
				}

				reverse_const_random_access_iterator &operator++()
				{
					_ptr--;
					return (*this);
				}
				reverse_const_random_access_iterator &operator--()
				{
					_ptr++;
					return (*this);
				}

				reverse_const_random_access_iterator operator++(int)
				{
					reverse_const_random_access_iterator save = *this;
					_ptr--;;
					return (save);
				}
				reverse_const_random_access_iterator operator--(int)
				{
					reverse_const_random_access_iterator save = *this;
					_ptr++;
					return (save);
				}

				reverse_const_random_access_iterator &operator+=(difference_type n)
				{
					_ptr -= n;
					return (*this);
				}
				reverse_const_random_access_iterator &operator-=(difference_type n)
				{
					_ptr += n;
					return (*this);
				}

				reverse_const_random_access_iterator operator+(difference_type n)
				{
					return (_ptr - n);
				}
				reverse_const_random_access_iterator operator-(difference_type n)
				{
					return (_ptr + n);
				}

				difference_type operator-(const reverse_const_random_access_iterator &other)
				{
					return (_ptr + other._ptr);
				}

				reference operator* (void)
				{
					return(*_ptr);
				}

				pointer operator-> (void) const
				{
					return (_ptr);
				}

				reference operator[](difference_type n)
				{
					return (*(_ptr + n));
				}

				pointer	base() const
				{
					return (_ptr);
				}
		};
}