#pragma once
#include "iterator_traits.hpp"

namespace ft
{
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
				typedef std::bidirectional_iterator_tag	iterator_category;

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
}
