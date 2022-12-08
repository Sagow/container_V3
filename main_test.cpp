#include "vector.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <time.h>

#define FILE_TO_READ "./Makefile"

		// for (; it != end; it++)
		// 	std::cout << *it;
		// std::cout << std::endl;

template <typename T_vector, typename T_iter>
void	exec_test(std::string msg)
{
	typedef std::istream_iterator<char>	is_iterator;
	std::ifstream		file;
	is_iterator			my_it;

	std::cout << msg << std::endl;
	file.open(FILE_TO_READ);
	my_it = is_iterator(file);

	T_vector vec(my_it, is_iterator());
	T_iter it(vec.begin());
	T_iter end(vec.end());

	size_t x = end - it;
	std::cout << msg << " len = " << x << " : " << std::endl;
	it += (x/2);
	std::cout << "split in half : " << it - vec.begin() << std::endl << std::endl;
	file.close();
}

template <typename T_vector, typename T_iter>
void	exec_rev_test(std::string msg)
{
	typedef std::istream_iterator<char>	is_iterator;
	std::ifstream		file;
	is_iterator			my_it;

	std::cout << msg << std::endl;
	file.open(FILE_TO_READ);
	my_it = is_iterator(file);

	T_vector vec(my_it, is_iterator());
	T_iter it(vec.rbegin());
	T_iter end(vec.rend());

	size_t x = end - it;
	std::cout << msg << " len = " << x << " : " << std::endl;
/*
	for (; it != end; it++)
		std::cout << *it;
	std::cout << std::endl;
*/
	it += (x / 2);
	std::cout << "split in half : " << it - vec.rbegin() << std::endl << std::endl;
	file.close();
}

template <typename t_vec>
void	exec_compare(std::string msg)
{
	typedef std::istream_iterator<char>	is_iterator;
	std::ifstream		file;
	is_iterator			my_it;

	file.open(FILE_TO_READ);
	my_it = is_iterator(file);

	std::cout << msg << std::endl;
	t_vec ref(my_it, is_iterator());
	std::cout << "Pass 1" << std::endl;
	t_vec vec(ref);
	std::cout << "Pass 2" << std::endl;
	if (ref == vec)
		std::cout << "PASS ref == vec" << std::endl;
	if (ref <= vec)
		std::cout << "PASS ref <= vec" << std::endl;
	if (ref >= vec)
		std::cout << "PASS ref >= vec" << std::endl;
	vec.pop_back();
	if (ref != vec)
		std::cout << "PASS ref != vec" << std::endl;
	if (!(ref < vec))
		std::cout << "PASS !(ref < vec)" << std::endl;
	
	file.close();
}

int main()
{
	// typedef	std::string												T;

	// typedef ft::vector<T>::iterator									ft_it;
	// typedef std::vector<T>::iterator								std_it;
	// typedef ft::vector<T>::reverse_iterator							ft_rev_it;
	// typedef ft::vector<T>::const_reverse_iterator					ft_const_rev_it;
	// typedef std::vector<T>::reverse_iterator			std_rev_it;

	// exec_test<ft::vector<T>, ft_it>		("ft::vector");
	// exec_test<std::vector<T>, std_it>	("std::vector");

	// exec_rev_test<ft::vector<T>, ft_rev_it>				("ft::rev_vector");
	// exec_rev_test<ft::vector<T>, ft_const_rev_it>		("ft::const_rev_vector");
	// exec_rev_test<std::vector<T>, std_rev_it>	("std::rev_vector");

	// exec_compare<ft::vector<T> >					("VECTOR");
	// tests();
	ft::vector<ft::vector<int> >	vec2;
	for (int i = 0; i < 20; i++)
	{
		ft::vector<int>	j(2, i);
		vec2.push_back(j);
	}
	for (size_t i = 0; i < vec2.size(); i++)
		std::cout << vec2[i].back() << ' ';
	std::cout << std::endl;

	/* CE TEST EST CENSE ECHOUER ET FAIRE UN INVALID READ
	ft::vector<std::string>    v2(8);
    ft::vector<std::string>::iterator    it2 = v2.begin();

    v2.push_back("AAAAAAAAAA");
    std::cout << (*it2) << std::endl;
	*/
	return 0;
}
