#pragma once
#include "algorithm.hpp"
#include "vector.hpp"

namespace ft
{
	template< class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference 		reference;
			typedef typename Container::const_reference	const_reference;

		protected:
			container_type	_vec;

		public:
			explicit stack( const Container& cont = Container() ): _vec(cont)
			{}
			stack( const stack& other ): _vec(other._vec)
			{}
			~stack()
			{}

			stack& operator=( const stack& other )
			{
				_vec = other._vec;
				return (*this);
			}

			reference top()
			{
				return (_vec.back());
			}
			const_reference top() const
			{
				return (_vec.back());
			}

			bool empty() const
			{
				return (_vec.empty());
			}

			size_type size() const
			{
				return (_vec.size());
			}

			void push( const value_type& value )
			{
				_vec.push_back(value);
			}
			void pop()
			{
				_vec.pop_back();
			}

			template< class fill, class Ctnr >
				friend bool operator==( const ft::stack<fill, Ctnr>& lhs, const ft::stack<fill, Ctnr>& rhs );
			template< class fill, class Ctnr >
				friend bool operator!=( const ft::stack<fill, Ctnr>& lhs, const ft::stack<fill, Ctnr>& rhs );
			template< class fill, class Ctnr >
				friend bool operator<( const ft::stack<fill, Ctnr>& lhs, const ft::stack<fill, Ctnr>& rhs );
			template< class fill, class Ctnr >
				friend bool operator<=( const ft::stack<fill, Ctnr>& lhs, const ft::stack<fill, Ctnr>& rhs );
			template< class fill, class Ctnr >
				friend bool operator>( const ft::stack<fill, Ctnr>& lhs, const ft::stack<fill, Ctnr>& rhs );
			template< class fill, class Ctnr >
				friend bool operator>=( const ft::stack<fill, Ctnr>& lhs, const ft::stack<fill, Ctnr>& rhs );
	};

	template< class T, class Container >
	bool operator==( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
	{
		return (lhs._vec == rhs._vec);
	};
	template< class T, class Container >
	bool operator!=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
	{
		return (lhs._vec != rhs._vec);
	};
	template< class T, class Container >
	bool operator<( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
	{
		return (lhs._vec < rhs._vec);
	};
	template< class T, class Container >
	bool operator<=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
	{
		return (lhs._vec <= rhs._vec);
	};
	template< class T, class Container >
	bool operator>( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
	{
		return (lhs._vec > rhs._vec);
	};
	template< class T, class Container >
	bool operator>=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs )
	{
		return (lhs._vec >= rhs._vec);
	};
}