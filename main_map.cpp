#include <iostream>
#include <string>
#include "map.hpp"
#include <map>
#include <list>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int	main(void)
{
	NAMESPACE::map<int, std::string>	mapDefaut;

	std::cout << "mapDefaut est vide : " << (mapDefaut.empty() ? "oui" : "non") << std::endl;
	std::cout << std::endl << "insertion de 1" << std::endl;
	mapDefaut.insert(NAMESPACE::make_pair(1, "un"));
	std::cout << "mapDefaut est vide : " << (mapDefaut.empty() ? "oui" : "non") << std::endl;
	std::cout << std::endl << "insertion de 2, 3, 5 et 6 (pas 4)" << std::endl;
	mapDefaut.insert(NAMESPACE::make_pair(2, "deux"));
	mapDefaut.insert(NAMESPACE::make_pair(3, "trois"));
	mapDefaut.insert(NAMESPACE::make_pair(5, "cinq"));
	mapDefaut.insert(NAMESPACE::make_pair(6, "six"));
	std::cout << std::endl << "mapDefaut contient 4 : " << (mapDefaut.find(4) == mapDefaut.end() ? "non" : "oui") << std::endl;
	std::cout << std::endl << "mapDefaut contient 5 : " << (mapDefaut.find(5) == mapDefaut.end() ? "non" : "oui") << std::endl;

	std::cout << std::endl << "on modifie 6 et on ajoute 7 avec []" << std::endl;
	mapDefaut[6] = "SIX";
	mapDefaut[7] = "sept";

	std::cout << std::endl << "on tente d'insert une cle deja presente :" << std::endl;
	NAMESPACE::pair<NAMESPACE::map<int, std::string>::iterator, bool> res =  mapDefaut.insert(NAMESPACE::make_pair(2, "doublon"));
	std::cout << std::endl << "a ete insere : " << (res.second ? "oui": "non") << std::endl;

	for (NAMESPACE::map<int, std::string>::iterator it = mapDefaut.begin(); it != mapDefaut.end(); it++)
	{
		std::cout << it->first << " <-> " << it->second << std::endl;
	}
	std::cout << "mapDefaut a une size de " << mapDefaut.size() << " et une max_size de " << mapDefaut.max_size() << std::endl;

	NAMESPACE::map<std::string, std::string>	mapACopier;
	mapACopier.insert(NAMESPACE::make_pair("login", "Prenom Nom"));

	std::cout << std::endl << "construction par copie de mapParCopie" << std::endl;

	NAMESPACE::map<std::string, std::string>	mapParCopie(mapACopier);
	for (NAMESPACE::map<std::string, std::string>::iterator it = mapParCopie.begin(); it != mapParCopie.end(); it++)
	{
		std::cout << it->first << " <-> " << it->second << std::endl;
	}
	return (0);
}