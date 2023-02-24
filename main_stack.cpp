#include <iostream>
#include "stack.hpp"
#include <stack>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int	main(void)
{
	NAMESPACE::stack<char> stackDefaut;

	std::cout << "stackDefaut est vide : " << (stackDefaut.empty() ? "oui" : "non") << std::endl;
	std::cout << "Push de a, b, c" << std::endl;
	stackDefaut.push('a');
	stackDefaut.push('b');
	stackDefaut.push('c');
	std::cout << "Dessus de la pile stackDefaut : " << stackDefaut.top() << std::endl;
	std::cout << "stackDefaut est vide : " << (stackDefaut.empty() ? "oui" : "non") << std::endl;
	std::cout << "taille de stackDefaut : " << stackDefaut.size()<< std::endl;
	std::cout << "creation de stackCopie : " << std::endl;

	NAMESPACE::stack<char> stackCopie(stackDefaut);
	std::cout << "Dessus de la pile stackCopie : " << stackCopie.top() << std::endl;
	std::cout << "taille de stackcopie : " << stackCopie.size()<< std::endl;
	std::cout << "Pop du haut de stackDefaut" << std::endl;
	stackDefaut.pop();
	std::cout << "Dessus de la pile stackDefaut : " << stackDefaut.top() << std::endl;
	std::cout << "taille de stackDefaut : " << stackDefaut.size()<< std::endl;
	return (0);
}