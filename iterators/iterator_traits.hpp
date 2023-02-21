#pragma once
#include <cstddef>
#include <iterator>
#include "algorithm.hpp"

namespace ft
{
	/*
	class input_iterator_tag {};
	class output_iterator_tag {};
    class forward_iterator_tag {};
	class bidirectional_iterator_tag {};
	class random_access_iterator_tag {};
	*/

	template<class Iter>
	class iterator_traits
	{
		public:
			typedef typename Iter::difference_type			difference_type;
			typedef typename Iter::value_type				value_type;
			typedef typename Iter::pointer					pointer;
			typedef typename Iter::reference				reference;
			typedef typename Iter::iterator_category		iterator_category;
	};

	template<typename T>
	class iterator_traits<T*>
	{
		public:
			typedef std::ptrdiff_t						difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef std::random_access_iterator_tag				iterator_category;
	};

	template<typename T>
	class iterator_traits<const T*>
	{
		public:
			typedef std::ptrdiff_t								difference_type;
			typedef T											value_type;
			typedef T const*									pointer;
			typedef T const&									reference;
			typedef std::random_access_iterator_tag						iterator_category;
	};
}