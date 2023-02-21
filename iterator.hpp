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
				p		*_node;


			public:
				typedef typename iterator_traits<T*>::difference_type			difference_type;
				typedef typename iterator_traits<T*>::value_type					value_type;
				typedef typename iterator_traits<T*>::pointer					pointer;
				typedef typename iterator_traits<T*>::reference					reference;
				typedef bidirectional_iterator_tag	iterator_category;

				bidirectional_iterator() : _node(NULL)
				{}

				bidirectional_iterator(p *linkedNode) : _node(linkedNode)
				{}

				bidirectional_iterator(const bidirectional_iterator &src) : _node(src._node)
				{}

				bidirectional_iterator	&operator=(const bidirectional_iterator &src)
				{
					if (&src != this)
						_node = src._node;
					return (*this);
				}

				bool	operator==(const bidirectional_iterator &other)
				{
					if (_node->getPair() == other._node->getPair())
						return (true);
					return (false);
				}
				bool	operator!=(const bidirectional_iterator &other)
				{
					return (!operator==(other));
				}

				bidirectional_iterator &operator++()
				{
					_node = _node->getNext();
					return (*this);
				}
				bidirectional_iterator &operator--()
				{
					_node = _node->getPrevious();
					return (*this);
				}

				bidirectional_iterator operator++(int)
				{
					bidirectional_iterator save = *this;
					_node = _node->getNext();
					return (save);
				}
				bidirectional_iterator operator--(int)
				{
					bidirectional_iterator save = *this;
					_node = _node->getPrevious();
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
					return (*(_node->getPair()));
				}
				pointer operator-> (void) const
				{
					return (_node->getPair());
				}

		};

	template <class T>
		class random_access_iterator : public iterator_traits<T*>
		{
			public:
				typedef random_access_iterator_tag	iterator_category;

			private:
				pointer		_ptr;

			public:
				random_access_iterator(void): _ptr(NULL)
				{}

				random_access_iterator(pointer ptr): _ptr(ptr)
				{}

				random_access_iterator(random_access_iterator src): _ptr(src._ptr)
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

				reference operator* (void)
				{
					return(*_ptr);
				}

				pointer operator-> (void) const
				{
					return (_ptr);
				}
		};
}