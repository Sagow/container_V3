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
				typedef typename iterator_traits<T*>::value_type				value_type;
				typedef typename iterator_traits<T*>::pointer					pointer;
				typedef typename iterator_traits<T*>::reference					reference;
				typedef std::bidirectional_iterator_tag	                        iterator_category;

				bidirectional_iterator() : _node(NULL)
				{}

				bidirectional_iterator(p *linkedNode) : _node(linkedNode)
				{}

				bidirectional_iterator(const bidirectional_iterator &src) : _node(src._node)
				{}

                operator bidirectional_iterator<T const, p>() const
                {
                    return (bidirectional_iterator<T const, p>(this->_node));
                }

				bidirectional_iterator	&operator=(const bidirectional_iterator &src)
				{
					if (&src != this)
						_node = src._node;
					return (*this);
				}

                p*  base(void) const
                {
                    return (_node);
                }
//
//				bool	operator==(const bidirectional_iterator &other)
//				{
//					if (_node->getPair() == other._node->getPair())
//						return (true);
//					return (false);
//				}
//				bool	operator!=(const bidirectional_iterator &other)
//				{
//					return (!operator==(other));
//				}

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

    template<typename pair1, typename node1, typename pair2, typename node2>
    bool	operator==(bidirectional_iterator<pair1, node1> const& it1, bidirectional_iterator<pair2, node2> const& it2)
        {
            return (it1.base()->getPair() == it2.base()->getPair());
        }

    template<typename pair1, typename node1, typename pair2, typename node2>
        bool	operator!=(bidirectional_iterator<pair1, node1> const& it1, bidirectional_iterator<pair2, node2> const& it2)
        {
            return (it1.base()->getPair() != it2.base()->getPair());
        }

    template<typename iterator>
        class reverse_bidirectional_iterator
        {
        public:
            typedef typename iterator::difference_type			            difference_type;
            typedef typename iterator::value_type				            value_type;
            typedef typename iterator::pointer				            	pointer;
            typedef typename iterator::reference				        	reference;
            typedef typename iterator::iterator_category                    iterator_category;

        private:
            iterator    _ptr;

        public:

            reverse_bidirectional_iterator(void) : _ptr(NULL)
            {}

            reverse_bidirectional_iterator(pointer ptr): _ptr(ptr)
            {}

            reverse_bidirectional_iterator(const iterator &src): _ptr(src)
            {}

            template<typename iter>
            reverse_bidirectional_iterator(const iter &src): _ptr(src.base())
            {}

            ~reverse_bidirectional_iterator()
            {}

            iterator	base() const
            {
                return (this->_ptr);
            }

            reverse_bidirectional_iterator &operator++()
            {
                this->_ptr--;
                return (*this);
            }
            reverse_bidirectional_iterator &operator--()
            {
                this->_ptr++;
                return (*this);
            }

            reverse_bidirectional_iterator operator++(int)
            {
                reverse_bidirectional_iterator save = *this;
                this->_ptr--;
                return (save);
            }
            reverse_bidirectional_iterator operator--(int)
            {
                reverse_bidirectional_iterator save = *this;
                this->_ptr++;
                return (save);
            }

            reverse_bidirectional_iterator &operator+=(difference_type n)
            {
                this->_ptr -= n;
                return (*this);
            }
            reverse_bidirectional_iterator &operator-=(difference_type n)
            {
                this->_ptr += n;
                return (*this);
            }

            reference operator* (void)
            {
                return (*(_ptr.base()->getPair()));
            }
            pointer operator-> (void) const
            {
                return (_ptr.base()->getPair());
            }
        };

    template<typename Iterator1, typename Iterator2>
    bool	operator==(reverse_bidirectional_iterator<Iterator1> const& it1, reverse_bidirectional_iterator<Iterator2> const& it2)
    {
        return (it2.base() == it1.base());
    }

    template<typename Iterator1, typename Iterator2>
    bool	operator!=(reverse_bidirectional_iterator<Iterator1> const& it1, reverse_bidirectional_iterator<Iterator2> const& it2)
    {
        return (it2.base() != it1.base());
    }
}
