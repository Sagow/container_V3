#pragma once

namespace ft
{
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

	struct false_type {static const bool state = false;};
	struct true_type {static const bool state = true;};

	template<typename> struct is_integral_base: false_type {};

	template<> struct is_integral_base<bool>: true_type {};
	template<> struct is_integral_base<char>: true_type {};
	template<> struct is_integral_base<wchar_t>: true_type {};
	template<> struct is_integral_base<short>: true_type {};
	template<> struct is_integral_base<int>: true_type {};
	template<> struct is_integral_base<long>: true_type {};
	template<> struct is_integral_base<long long>: true_type {};
	template<> struct is_integral_base<unsigned char>: true_type {};
	template<> struct is_integral_base<unsigned short>: true_type {};
	template<> struct is_integral_base<unsigned int>: true_type {};
	template<> struct is_integral_base<unsigned long>: true_type {};
	template<> struct is_integral_base<unsigned long long>: true_type {};

	template<typename T> struct is_integral: is_integral_base<typename ft::remove_cv<T>::type>
	{
		typedef bool												value_type;
		typedef is_integral_base<typename ft::remove_cv<T>::type>	type;
	
		operator value_type() {return (this->value_type);}
	};

	template <class Key>
	struct	less
	{
		bool	operator()(Key const &a, Key const &b) const
		{
			return (a < b);
		}
	};

	template<
		class T1,
		class T2
	> struct pair
	{
		T1	first;
		T2	second;

		pair()
		{}
		pair(T1 const &f, T2 const &s) : first(f), second(s)
		{}
		template <class U, class V>
			pair(pair<U,V> const &p) : first(p.first), second(p.second)
			{}
		
		template <class U, class V>
			pair	&operator=(pair<U,V> const &p)
			{
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