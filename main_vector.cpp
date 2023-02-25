#include <iostream>
#include <string>
#include "vector.hpp"
#include <vector>
#include <list>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int	main(void)
{
	NAMESPACE::vector<std::string>	stringDefaut;

	std::cout << std::endl << "assigning to stringDefaut" << std::endl;
	stringDefaut.assign(5, "defaut");
	for (NAMESPACE::vector<std::string>::iterator it = stringDefaut.begin(); it != stringDefaut.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl << "inserting 2 after begin in stringDefaut" << std::endl;
	stringDefaut.insert(stringDefaut.begin() + 2, "Coucou c'est l'insertion");
	for (NAMESPACE::vector<std::string>::iterator it = stringDefaut.begin(); it != stringDefaut.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl << "erasing element in first position in stringDefaut" << std::endl;
	stringDefaut.erase(stringDefaut.begin());
	for (NAMESPACE::vector<std::string>::iterator it = stringDefaut.begin(); it != stringDefaut.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl << "inserting a range in last position in stringDefaut" << std::endl;
	std::list<std::string> myList;
	std::string	str = "strin";
	for (int i = 0; i < 10; i++)
	{
		str += 'g';
		myList.push_back(str);
	}
	stringDefaut.insert(stringDefaut.end(), myList.begin(), myList.end());
	for (NAMESPACE::vector<std::string>::iterator it = stringDefaut.begin(); it != stringDefaut.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cout << std::endl << "New vector<string> stringIni" << std::endl; 
	NAMESPACE::vector<std::string>	stringIni(6, "Initialisation in constructor");
	for (NAMESPACE::vector<std::string>::iterator it = stringIni.begin(); it != stringIni.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "stringIni has size = " << stringIni.size() << ", current capacity = " << stringIni.capacity() << " and maxsize = " << stringIni.max_size() << std::endl;
	std::cout << std::endl << "pushing back in stringIni" << std::endl;
	stringIni.push_back("coucou c'est le push_back");
	for (NAMESPACE::vector<std::string>::iterator it = stringIni.begin(); it != stringIni.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "stringIni has size = " << stringIni.size() << ", current capacity = " << stringIni.capacity() << " and maxsize = " << stringIni.max_size() << std::endl;
	std::cout << std::endl << "reserve 100 in stringIni" << std::endl;
	stringIni.reserve(100);
	std::cout << "stringIni has size = " << stringIni.size() << ", current capacity = " << stringIni.capacity() << " and maxsize = " << stringIni.max_size() << std::endl;
	for (int j = 0; j < stringIni.size(); j++)
	{
		std::cout << "obtained with [] " << stringIni[j] << std::endl;
	}
	std::cout << std::endl << "swap of stringDefaut and stringIni" << std::endl;
	NAMESPACE::swap(stringDefaut, stringIni);
	std::cout << "stringDefaut has size = " << stringDefaut.size() << ", current capacity = " << stringDefaut.capacity() << " and maxsize = " << stringDefaut.max_size() << std::endl;
	std::cout << "stringIni has size = " << stringIni.size() << ", current capacity = " << stringIni.capacity() << " and maxsize = " << stringIni.max_size() << std::endl;

	std::cout << "stringDefaut < stringIni " << (stringDefaut < stringIni ? "true" : "false") << std::endl;
	std::cout << "stringDefaut <= stringIni " << (stringDefaut <= stringIni ? "true" : "false") << std::endl;
	std::cout << "stringDefaut > stringIni " << (stringDefaut > stringIni ? "true" : "false") << std::endl;
	std::cout << "stringDefaut >= stringIni " << (stringDefaut >= stringIni ? "true" : "false") << std::endl;
	std::cout << "stringDefaut == stringIni " << (stringDefaut == stringIni ? "true" : "false") << std::endl;
	std::cout << "stringDefaut != stringIni " << (stringDefaut != stringIni ? "true" : "false") << std::endl;

	std::cout << std::endl << "clear of stringDefaut" << std::endl;
	stringDefaut.clear();
	std::cout << "stringDefaut has size = " << stringDefaut.size() << ", current capacity = " << stringDefaut.capacity() << " and maxsize = " << stringDefaut.max_size() << std::endl;
	
	std::cout << std::endl << "stringDefaut = stringIni" << std::endl;
	stringDefaut = stringIni;
	std::cout << "stringDefaut has size = " << stringDefaut.size() << ", current capacity = " << stringDefaut.capacity() << " and maxsize = " << stringDefaut.max_size() << std::endl;
	std::cout << "stringDefaut < stringIni " << (stringDefaut < stringIni ? "true" : "false") << std::endl;
	std::cout << "stringDefaut <= stringIni " << (stringDefaut <= stringIni ? "true" : "false") << std::endl;
	std::cout << "stringDefaut > stringIni " << (stringDefaut > stringIni ? "true" : "false") << std::endl;
	std::cout << "stringDefaut >= stringIni " << (stringDefaut >= stringIni ? "true" : "false") << std::endl;
	std::cout << "stringDefaut == stringIni " << (stringDefaut == stringIni ? "true" : "false") << std::endl;
	std::cout << "stringDefaut != stringIni " << (stringDefaut != stringIni ? "true" : "false") << std::endl;

	std::cout << std::endl << "resize smaller of stringDefaut" << std::endl;
	stringDefaut.reserve(5, "remplissage");
	std::cout << "stringDefaut has size = " << stringDefaut.size() << ", current capacity = " << stringDefaut.capacity() << " and maxsize = " << stringDefaut.max_size() << std::endl;

	std::cout << std::endl << "resize bigger of stringDefaut" << std::endl;
	stringDefaut.resize(25, "remplissage");
	std::cout << "stringDefaut has size = " << stringDefaut.size() << ", current capacity = " << stringDefaut.capacity() << " and maxsize = " << stringDefaut.max_size() << std::endl;
	for (NAMESPACE::vector<std::string>::iterator it = stringDefaut.begin(); it != stringDefaut.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	return (0);
}