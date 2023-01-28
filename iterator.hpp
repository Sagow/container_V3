#pragma once
#include <cstddef>
#include "algorithm.hpp"

namespace ft
{
	//tags
	class input_iterator_tag {};
	class output_iterator_tag {};
    class forward_iterator_tag {};
	class bidirectional_iterator_tag {};
	class random_access_iterator_tag {};

	template <class Tag, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
		class iterator
		{
			public:
				typedef	T			value_type;
				typedef	Distance	difference_type;
				typedef	Pointer		pointer;
				typedef	Reference	reference;
				typedef	Tag			iterator_category;

				iterator() : _elem(nullptr_t())
				{
				}

				iterator(const Pointer &ptr) : _elem(ptr)
				{
				}

				iterator(const iterator &src) : _elem(src._elem)
				{
				}

				iterator	&operator=(const iterator &src)
				{
					if (&src == this)
						return (*this);
					_elem = src._elem;
				}


				bool	operator==(const iterator &other)
				{
					if (_elem == other._elem)
						return (true);
					return (false);
				}
				bool	operator!=(const iterator &other)
				{
					return (!operator==(other));
				}
				reference operator* (void)
				{
					return (_elem->pair);
				}
				pointer operator-> (void)
				{
					return ((_elem->pair));
				}

			protected:
				pointer	_elem;
		};

	template <class T>
		class bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
		{
			public:
				typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category		iterator_category;			
				typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type			value_type;
				typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type		difference_type;
				typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer				pointer;			
				typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference				reference;
			
				bidirectional_iterator &operator++()
				{
					if (this->right)
					{
						this = this->right;
						while (this->left)
							this = this->leftt;
						return (this);
					}
					if (this->getNext() != this)
						return (this->getNext());
					return (this + 1);
				}
				bidirectional_iterator &operator--()
				{
					if (this->left)
					{
						this = this->left;
						while (this->right)
							this = this->right;
						return (this);
					}
					if (this->getPrevious() != this)
						return (this->getPrevious());
					return (this + 1);
				}

				bidirectional_iterator operator++(int)
				{
					bidirectional_iterator save = *this;
					if (this->right)
					{
						this = this->right;
						while (this->left)
							this = this->leftt;
					}
					else if (this->getNext() != this)
						this = this->getNext();
					else
						this = this + 1;
					return (save);
				}
				bidirectional_iterator operator--(int)
				{
					bidirectional_iterator save = *this;
					if (this->left)
					{
						this = this->left;
						while (this->right)
							this = this->right;
					}
					if (this->getPrevious() != this)
						this = this->getPrevious();
					this = this + 1;
					return (save);
				}

				bidirectional_iterator &operator+=(difference_type n)
				{
					for (difference_type i = 0; i < n - 1; i++)
						operator++();
					return (operator++());
				}
				bidirectional_iterator &operator-=(difference_type n)
				{
					for (difference_type i = 0; i < n - 1; i++)
						operator--();
					return (operator--());
				}

		};

	template <class T>
		class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
		{
			public:
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category		iterator_category;			
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer				pointer;			
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference				reference;
			
		};
}