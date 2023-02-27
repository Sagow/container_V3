#include "common.hpp"

#define T1 int
#define T2 std::string

#define cout std::cout

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
    for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
        cout << it->first << " => " << it->second << '\n';
}

int main ()
{
    map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        cout << it->first << " => " << it->second << '\n';

    cout << "\n\n========\n\n";


    map<char,int>::iterator it = mymap.end();
    it--;
    cout << "end - 1 " << it->first << '\n';
    for (it = --mymap.end(); it!=mymap.begin(); --it)
        cout << it->first << " => " << it->second << '\n';
    cout << it->first << " => " << it->second << '\n';

    return 0;
}
