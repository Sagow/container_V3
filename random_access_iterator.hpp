#pragma once
#include "iterator_traits.hpp"

namespace ft
{
		
	template <class T>
		class random_access_iterator : public iterator_traits<T*>
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
				random_access_iterator(void): _ptr(NULL)
				{}

				random_access_iterator(pointer ptr): _ptr(ptr)
				{}

				random_access_iterator(const random_access_iterator &src): _ptr(src._ptr)
				{}

				~random_access_iterator()
				{}

				random_access_iterator	&operator=(const random_access_iterator &src)
				{
					if (&src != this)
						_ptr = src._ptr;
					return (*this);
				}

				bool	operator==(const random_access_iterator &other)
				{
					if (_ptr == other._ptr)
						return (true);
					return (false);
				}
				bool	operator!=(const random_access_iterator &other)
				{
					return (!operator==(other));
				}
				bool	operator<(const random_access_iterator &other)
				{
					return (_ptr < other._ptr);
				}

				bool	operator<=(const random_access_iterator &other)
				{
					return (operator<(other) || operator==(other));
				}

				bool	operator>(const random_access_iterator &other)
				{
					return (!operator<=(other));
				}

				bool	operator>=(const random_access_iterator &other)
				{
					return (!operator<(other));
				}

				random_access_iterator &operator++()
				{
					_ptr++;
					return (*this);
				}
				random_access_iterator &operator--()
				{
					_ptr--;
					return (*this);
				}

				random_access_iterator operator++(int)
				{
					random_access_iterator save = *this;
					_ptr++;;
					return (save);
				}
				random_access_iterator operator--(int)
				{
					random_access_iterator save = *this;
					_ptr--;
					return (save);
				}

				random_access_iterator &operator+=(difference_type n)
				{
					_ptr += n;
					return (*this);
				}
				random_access_iterator &operator-=(difference_type n)
				{
					_ptr -= n;
					return (*this);
				}

				random_access_iterator operator+(difference_type n)
				{
					return (_ptr + n);
				}
				random_access_iterator operator-(difference_type n)
				{
					return (_ptr - n);
				}

				difference_type operator-(const random_access_iterator &other)
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
		class reverse_random_access_iterator
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
				reverse_random_access_iterator(void): _ptr(NULL)
				{}

				reverse_random_access_iterator(pointer ptr): _ptr(ptr)
				{}

				reverse_random_access_iterator(const reverse_random_access_iterator &src): _ptr(src._ptr)
				{}

				reverse_random_access_iterator(const random_access_iterator<value_type> &src): _ptr(src.operator->() - 1)
				{}

				~reverse_random_access_iterator()
				{}

				reverse_random_access_iterator	&operator=(const reverse_random_access_iterator &src)
				{
					if (&src != this)
						_ptr = src._ptr;
					return (*this);
				}

				bool	operator==(const reverse_random_access_iterator &other)
				{
					if (_ptr == other._ptr)
						return (true);
					return (false);
				}
				bool	operator!=(const reverse_random_access_iterator &other)
				{
					return (!operator==(other));
				}
				bool	operator<(const reverse_random_access_iterator &other)
				{
					return (_ptr < other._ptr);
				}

				bool	operator<=(const reverse_random_access_iterator &other)
				{
					return (operator<(other) || operator==(other));
				}

				bool	operator>(const reverse_random_access_iterator &other)
				{
					return (!operator<=(other));
				}

				bool	operator>=(const reverse_random_access_iterator &other)
				{
					return (!operator<(other));
				}

				reverse_random_access_iterator &operator++()
				{
					_ptr--;
					return (*this);
				}
				reverse_random_access_iterator &operator--()
				{
					_ptr++;
					return (*this);
				}

				reverse_random_access_iterator operator++(int)
				{
					reverse_random_access_iterator save = *this;
					_ptr--;;
					return (save);
				}
				reverse_random_access_iterator operator--(int)
				{
					reverse_random_access_iterator save = *this;
					_ptr++;
					return (save);
				}

				reverse_random_access_iterator &operator+=(difference_type n)
				{
					_ptr -= n;
					return (*this);
				}
				reverse_random_access_iterator &operator-=(difference_type n)
				{
					_ptr += n;
					return (*this);
				}

				reverse_random_access_iterator operator+(difference_type n)
				{
					return (_ptr - n);
				}
				reverse_random_access_iterator operator-(difference_type n)
				{
					return (_ptr + n);
				}

				difference_type operator-(const reverse_random_access_iterator &other)
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