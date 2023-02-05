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

	template <bool is_integral, typename T>
        struct is_integral_res {
            typedef T type;
            static const bool value = is_integral;
            };

    template <typename>
        struct is_integral_type : public is_integral_res<false, bool> {};

    template <>
        struct is_integral_type<bool> : public is_integral_res<true, bool> {};

    template <>
        struct is_integral_type<char> : public is_integral_res<true, char> {};

    template <>
        struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};

    template <>
        struct is_integral_type<short int> : public is_integral_res<true, short int> {};
    
    template <>
        struct is_integral_type<int> : public is_integral_res<true, int> {};

    template <>
        struct is_integral_type<long int> : public is_integral_res<true, long int> {};

    template <>
        struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};

    template <>
        struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};

    template <>
        struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};

    template <>
        struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};

    template <>
        struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
    
    template <>
        struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

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

	static class nullptr_t
	{
		public:
			template<class T>
			operator T*() const { return (0); }

			template<class C, class T>
			operator T C::*() const { return (0); }

		private:
			
			void operator&() const;

	} u_nullptr = {};
}