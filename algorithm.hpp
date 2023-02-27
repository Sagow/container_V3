#pragma once

namespace ft
{
	template<typename T>
	void	__swap(T& lhs, T& rhs)
	{
		T&	tmp = lhs;

		lhs = rhs;
		rhs = tmp;
	}

	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2 )
	{
		while (first1!=last1 && first2 != last2) {
			if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
				return false;
			++first1; ++first2;
		}
		if (first1 != last1 || first2 != last2)
			return (false);
		return true;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2, class Comparator>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2,
										Comparator comp)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (comp(*first1,*first2)) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template <class T> struct remove_cv						{typedef T type;};
	template <class T> struct remove_cv<const T>			{typedef T type;};
	template <class T> struct remove_cv<volatile T>			{typedef T type;};
	template <class T> struct remove_cv<const volatile T>	{typedef T type;};

	template <class T> struct remove_const					{typedef T type;};
	template <class T> struct remove_const<const T>			{typedef T type;};
	
	template <class T> struct remove_volatile				{typedef T type;};
	template <class T> struct remove_volatile<volatile T>	{typedef T type;};

	//Enable if
	template <bool Cond, typename Result=void>
	struct enable_if {};

	template <typename Result>
	struct enable_if<true, Result> {
		typedef Result type;
	};

	template < class T, T v >
	struct	integral_constant
	{
		static const T value = v;
	};

	typedef	integral_constant<bool, true>	true_type; 
	typedef	integral_constant<bool, false>	false_type;


    template <typename>
        struct is_integral_type : public false_type {};

    template <>
        struct is_integral_type<bool> : public true_type {};

    template <>
        struct is_integral_type<char> : public true_type {};

    template <>
        struct is_integral_type<signed char> : public true_type {};

    template <>
        struct is_integral_type<short int> : public true_type {};
    
    template <>
        struct is_integral_type<int> : public true_type {};

    template <>
        struct is_integral_type<long int> : public true_type {};

    template <>
        struct is_integral_type<long long int> : public true_type {};

    template <>
        struct is_integral_type<unsigned char> : public true_type {};

    template <>
        struct is_integral_type<unsigned short int> : public true_type {};

    template <>
        struct is_integral_type<unsigned int> : public true_type {};

    template <>
        struct is_integral_type<unsigned long int> : public true_type {};
    
    template <>
        struct is_integral_type<unsigned long long int> : public true_type {};

    template <typename T>
        struct is_integral : public is_integral_type<T> { };

	template< class T1, class T2>
		struct pair
		{
			public:
				T1	first;
				T2	second;

				pair(): first(), second()
				{}
				pair(T1 const &f, T2 const &s) : first(f), second(s)
				{}
				template <class U, class V>
					pair(pair<U, V> const &p) : first(p.first), second(p.second)
					{}
				
				template <class U, class V>
					pair	&operator=(pair<U,V> const &p)
					{
						if (*this == p)
                        	return (*this);
						first = p.first;
						second = p.second;
						return (*this);
					}
		};

	template< class T1, class T2 >
		pair<T1, T2> make_pair( T1 t, T2 u )
		{
			return(pair<T1, T2>(t, u));
		};
	
	template< class T1, class T2 >
		bool	operator==(pair<T1, T2> const &p1, pair<T1, T2> const &p2)
		{
			return (p1.first == p2.first && p1.second == p2.second);
		}

	template< class T1, class T2 >
		bool	operator!=(pair<T1, T2> const &p1, pair<T1, T2> const &p2)
		{
			return (!(p1 == p2));
		}

	template< class T1, class T2 >
		bool	operator<(pair<T1, T2> const &p1, pair<T1, T2> const &p2)
		{
			return (p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second));
		}

	template< class T1, class T2 >
		bool	operator>(pair<T1, T2> const &p1, pair<T1, T2> const &p2)
		{
			return (p2 < p1);
		}

	template< class T1, class T2 >
		bool	operator<=(pair<T1, T2> const &p1, pair<T1, T2> const &p2)
		{
			return (!(p1 > p2));
		}

	template< class T1, class T2 >
		bool	operator>=(pair<T1, T2> const &p1, pair<T1, T2> const &p2)
		{
			return (!(p1 < p2));
		}
}