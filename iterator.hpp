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

	//virer iterator, faire heriter random et bidirectional de iterator_traits

	template<class Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type			difference_type;
			typedef typename Iterator::value_type				value_type;
			typedef typename Iterator::pointer					pointer;
			typedef typename Iterator::reference				reference;
			typedef typename Iterator::iterator_category		iterator_category;
	};

	template<typename T>
	class iterator_traits<T*>
	{
		public:
			typedef std::ptrdiff_t						difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
	};

	template<typename T>
	class iterator_traits<const T*>
	{
		public:
			typedef std::ptrdiff_t								difference_type;
			typedef T											value_type;
			typedef T const*									pointer;
			typedef T const&									reference;
	};
	//rajouter dans le template une classe pour le RBnode, et garder T pour la pair
	template <class T, class p, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
		class bidirectional_iterator : public iterator_traits<T*>
		{
			protected:
				Pointer _elem;


			public:
				typedef typename iterator_traits<T*>::difference_type			difference_type;
				typedef typename iterator_traits<T*>::value_type					value_type;
				typedef typename iterator_traits<T*>::pointer					pointer;
				typedef typename iterator_traits<T*>::reference					reference;
				typedef bidirectional_iterator_tag	iterator_category;

				bidirectional_iterator() : _elem(NULL)
				{}

				bidirectional_iterator(const Pointer ptr) : _elem(ptr)
				{}

				bidirectional_iterator(const bidirectional_iterator &src) : _elem(src._elem)
				{}

				bidirectional_iterator	&operator=(const bidirectional_iterator &src)
				{
					if (&src == this)
						return (*this);
					_elem = src._elem;
				}

				bool	operator==(const bidirectional_iterator &other)
				{
					if (_elem == other._elem)
						return (true);
					return (false);
				}
				bool	operator!=(const bidirectional_iterator &other)
				{
					return (!operator==(other));
				}

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
					if (this->getNext() != this)
						this = this->getNext();
					else
						this = nullptr_t;
					return (save);
				}
				bidirectional_iterator operator--(int)
				{
					bidirectional_iterator save = *this;
					if (this->getPrevious() != this)
						this = this->getPrevious();
					else
						this = nullptr_t;
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

				reference operator* (void)
				{
					return (this->_elem->getPair());
				}
				pointer operator-> (void)
				{
					return (&(this->_elem->getPair()));
				}

		};

	template <class T>
		class random_access_iterator : public iterator_traits<T*>
		{
			public:
				typedef random_access_iterator_tag	iterator_category;

		};
}