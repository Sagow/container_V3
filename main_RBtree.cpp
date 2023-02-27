#include <list>
#include "map.hpp"

#define cout std::cout
#define string std::string

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

/*
** This is a minimal set of ANSI/VT100 color codes
*/
# define _END			"\x1b[0m"
# define _BOLD			"\x1b[1m"
# define _UNDER			"\x1b[4m"
# define _REV			"\x1b[7m"

/*
** Colors
*/
# define _GREY			"\x1b[30m"
# define _RED			"\x1b[31m"
# define _GREEN			"\x1b[32m"
# define _YELLOW		"\x1b[33m"
# define _BLUE			"\x1b[34m"
# define _PURPLE		"\x1b[35m"
# define _CYAN			"\x1b[36m"
# define _WHITE			"\x1b[37m"

/*
** Inverted, i.e. colored backgrounds
*/
# define _IGREY			"\x1b[40m"
# define _IRED			"\x1b[41m"
# define _IGREEN		"\x1b[42m"
# define _IYELLOW		"\x1b[43m"
# define _IBLUE			"\x1b[44m"
# define _IPURPLE		"\x1b[45m"
# define _ICYAN			"\x1b[46m"
# define _IWHITE		"\x1b[47m"



template<typename T1, typename T2>
std::ostream	&operator<<(std::ostream &os, ft::pair<T1, T2> const& p)
{
    std::map<int, int> t;
    auto it = t.rbegin();

	os << "[" << p.first << ", " << p.second << "]";
	return (os);
}

template <class Key, class T>
void	print(map<Key, T>& lst)
{
    for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
        cout << *it << ' ';
    cout << '\n';
}

int		main(void)
{
	ft::map<int, string> mp, mp2;

	cout << "hee hee" << std::endl;
	mp.insert(make_pair(5, "hey"));
	cout << "hee hee" << std::endl;
	return (0);
}