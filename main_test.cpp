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
	ft::vector<ft::vector<int> >	vec2;

	for (int i = 0; i < 20; i++)
	{
		ft::vector<int>	j(3, i);
		//std::cout << j.size() << ' ';
	//std::cout << "boucle" << std::endl;
		vec2.push_back(j);
		std::cout << vec2.back().size() << " contre " << j.size() << " sur " << vec2.size() << " elements(" << vec2[i].capacity() << std::endl;
	}
	std::cout << std::endl;
	for (size_t i = 0; i < vec2.size(); i++)
		std::cout << vec2[i].front() << ' ';
	std::cout << std::endl;
	std::cout << "--------------" << std::endl;

	/*ft::vector<int> vec;
	for (int i = 0; i < 20; i++)
	{
		vec.push_back(i + 5);
	}
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';*/
	return 0;
}
