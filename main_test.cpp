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

void	display_my_vector(ft::vector<int> v)
{
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << "[" << (*it) << "]" << std::endl;
}
void	display_vector(std::vector<int> v)
{
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << "[" << (*it) << "]" << std::endl;
}
int main()
{
	
	//AT
	ft::vector<std::string> MIKE(8, "pouet");
	std::vector<std::string> BOB(8, "pouet");
	std::cout << "\nAT\n";
	try
	{
		std::cout << MIKE.at(2) << '\n';
		std::cout << MIKE.at(87) << '\n';
	}
	catch (std::out_of_range& oor)
	{
		(void)oor;
		std::cout << "OOR error caught\n" << oor.what();
	}
	return 0;
}
