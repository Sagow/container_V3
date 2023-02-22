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
				typedef std::random_access_iterator_tag							iterator_category;

			protected:
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

				operator random_access_iterator<T const>() const
				{
					return (random_access_iterator<T const>(this->_ptr));
				}

				random_access_iterator	&operator=(const random_access_iterator &src)
				{
					if (&src != this)
						_ptr = src._ptr;
					return (*this);
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

	template<typename Iterator1, typename Iterator2>
		bool	operator==(random_access_iterator<Iterator1> const& it1, random_access_iterator<Iterator2> const& it2)
		{
			return (it1.base() == it2.base());
		}

	template<typename Iterator1, typename Iterator2>
		bool	operator!=(random_access_iterator<Iterator1> const& it1, random_access_iterator<Iterator2> const& it2)
		{
			return (it1.base() != it2.base());
		}

	template<typename Iterator1, typename Iterator2>
		bool	operator<(random_access_iterator<Iterator1> const& it1, random_access_iterator<Iterator2> const& it2)
		{
			return (it1.base() < it2.base());
		}

	template<typename Iterator1, typename Iterator2>
		bool	operator>(random_access_iterator<Iterator1> const& it1, random_access_iterator<Iterator2> const& it2)
		{
			return (it2 < it1);
		}

	template<typename Iterator1, typename Iterator2>
		bool	operator>=(random_access_iterator<Iterator1> const& it1, random_access_iterator<Iterator2> const& it2)
		{
			return (!(it1 < it2));
		}

	template<typename Iterator1, typename Iterator2>
		bool	operator<=(random_access_iterator<Iterator1> const& it1, random_access_iterator<Iterator2> const& it2)
		{
			return (!(it2 < it1));
		}

	template<typename Iterator>
		random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type nb, random_access_iterator<Iterator> const& it)
		{
			return (random_access_iterator<Iterator>(it.base() + nb));
		};

	template<typename Iterator1, typename Iterator2>
		typename random_access_iterator<Iterator1>::difference_type operator-(random_access_iterator<Iterator1> const& it1, random_access_iterator<Iterator2> const& it2)
		{
			return (it1.base() - it2.base());
		}

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
				iterator		_ptr;
			
			public:
				reverse_random_access_iterator(void) : _ptr(NULL)
				{}

				reverse_random_access_iterator(pointer ptr): _ptr(ptr)
				{
				}

				reverse_random_access_iterator(const reverse_random_access_iterator &src):_ptr(src.base())
				{
				}

				reverse_random_access_iterator(const iterator &src): _ptr(src.base())
				{
				}

				template<typename iter>
					reverse_random_access_iterator(const iter &src): _ptr(src.base())
					{
					}

				~reverse_random_access_iterator()
				{}

				operator reverse_random_access_iterator<iterator const>() const
				{
					return (reverse_random_access_iterator<iterator const>(this->_ptr));
				}

				reverse_random_access_iterator	&operator=(const reverse_random_access_iterator &src)
				{
					if (&src != this)
						this->_ptr = src._ptr;
					return (*this);
				}

				reverse_random_access_iterator &operator++()
				{
					this->_ptr--;
					return (*this);
				}
				reverse_random_access_iterator &operator--()
				{
					this->_ptr++;
					return (*this);
				}

				reverse_random_access_iterator operator++(int)
				{
					reverse_random_access_iterator save = *this;
					this->_ptr--;
					return (save);
				}
				reverse_random_access_iterator operator--(int)
				{
					reverse_random_access_iterator save = *this;
					this->_ptr++;
					return (save);
				}

				reverse_random_access_iterator &operator+=(difference_type n)
				{
					this->_ptr -= n;
					return (*this);
				}
				reverse_random_access_iterator &operator-=(difference_type n)
				{
					this->_ptr += n;
					return (*this);
				}

				reverse_random_access_iterator operator+(difference_type n)
				{
					return (this->_ptr - n);
				}
				reverse_random_access_iterator operator-(difference_type n)
				{
					return (this->_ptr + n);
				}

				reference operator* (void)
				{
					return(*(this->_ptr - 1));
				}

				pointer operator-> (void)
				{
					return (_ptr.base() - 1);
				}

				reference operator[](difference_type n)
				{
					return (*(_ptr - 1 - n));
				}

				iterator	base() const
				{
					return (this->_ptr);
				}
		};

	template<typename Iterator1, typename Iterator2>
		bool	operator==(reverse_random_access_iterator<Iterator1> const& it1, reverse_random_access_iterator<Iterator2> const& it2)
		{
			return (it2.base() == it1.base());
		}

	template<typename Iterator1, typename Iterator2>
		bool	operator!=(reverse_random_access_iterator<Iterator1> const& it1, reverse_random_access_iterator<Iterator2> const& it2)
		{
			return (it2.base() != it1.base());
		}
	
	template<typename Iterator1, typename Iterator2>
		bool	operator<(reverse_random_access_iterator<Iterator1> const& it1, reverse_random_access_iterator<Iterator2> const& it2)
		{
			return (it2.base() < it1.base());
		}

	template<typename Iterator1, typename Iterator2>
		bool	operator>(reverse_random_access_iterator<Iterator1> const& it1, reverse_random_access_iterator<Iterator2> const& it2)
		{
			return (it2 < it1);
		}

	template<typename Iterator1, typename Iterator2>
		bool	operator>=(reverse_random_access_iterator<Iterator1> const& it1, reverse_random_access_iterator<Iterator2> const& it2)
		{
			return (!(it1 < it2));
		}

	template<typename Iterator1, typename Iterator2>
		bool	operator<=(reverse_random_access_iterator<Iterator1> const& it1, reverse_random_access_iterator<Iterator2> const& it2)
		{
			return (!(it2 < it1));
		}


	template<typename Iterator>
		reverse_random_access_iterator<Iterator> operator+(typename reverse_random_access_iterator<Iterator>::difference_type nb, reverse_random_access_iterator<Iterator> const& it)
		{
			return (it.base() - nb);
		};
	
	template<typename Iterator>
		reverse_random_access_iterator<Iterator> operator-(typename reverse_random_access_iterator<Iterator>::difference_type nb, reverse_random_access_iterator<Iterator> const& it)
		{
			return (it.base() + nb);
		};

	template<typename Iterator1, typename Iterator2>
		typename reverse_random_access_iterator<Iterator1>::difference_type operator-(reverse_random_access_iterator<Iterator1> const& it1, reverse_random_access_iterator<Iterator2> const& it2)
		{
			return (it2.base() - it1.base());
		}
}