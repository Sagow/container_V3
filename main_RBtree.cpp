#include "RBnode.hpp"
#include "RBtree.hpp"
#include "map.hpp"
/*
int main(void)
{
	ft::RBtree<int, int>	tree(5, 7);

	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;
	tree.print();
std::cout << "**************************************************" << std::endl;
	std::cout << "insert 1" << std::endl;
	tree.insertNode(1);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;
	//tree.print();
	//tree.getTrunk()->rightRotate();
	tree.print();
	//ft::RBnode<int> test(*(tree.getTrunk()));
	//std::cout << "Test = " << test.content << std::endl;

std::cout << "**************************************************" << std::endl;


	std::cout << "insert 10" << std::endl;
	tree.insertNode(10);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;
	tree.print();
std::cout << "**************************************************" << std::endl;


	std::cout << "insert 8" << std::endl;
	tree.insertNode(8);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;
	tree.print();
std::cout << "**************************************************" << std::endl;


	std::cout << "insert 9" << std::endl;
	tree.insertNode(9);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;
tree.print();
std::cout << "**************************************************" << std::endl;


	std::cout << "insert 7" << std::endl;
	tree.insertNode(7);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;
tree.print();
std::cout << "**************************************************" << std::endl;
	std::cout << "insert 17" << std::endl;
	tree.insertNode(17);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;
tree.print();
std::cout << "**************************************************" << std::endl;
std::cout << "insert 18" << std::endl;
	tree.insertNode(18);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;
tree.print();
std::cout << "**************************************************" << std::endl;
std::cout << "insert 19" << std::endl;
	tree.insertNode(19);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;
tree.print();
std::cout << "**************************************************" << std::endl;
std::cout << "insert 20" << std::endl;
	tree.insertNode(20);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;
tree.print();
std::cout << "**************************************************" << std::endl;
std::cout << "insert 21" << std::endl;
	tree.insertNode(21);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;
tree.print();
std::cout << "**************************************************" << std::endl;
std::cout << "insert 16" << std::endl;
	tree.insertNode(16);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;

	tree.print();

std::cout << "**************************************************" << std::endl;
std::cout << "remove 10" << std::endl;
	tree.deleteNode(10);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;

	tree.print();
	std::cout << "**************************************************" << std::endl;
std::cout << "remove 17" << std::endl;
	tree.deleteNode(17);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;

	tree.print();
		std::cout << "**************************************************" << std::endl;
std::cout << "remove 9" << std::endl;
	tree.deleteNode(9);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;

	tree.print();
		std::cout << "**************************************************" << std::endl;
std::cout << "remove 1" << std::endl;
	tree.deleteNode(1);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;

	tree.print();
		std::cout << "**************************************************" << std::endl;
std::cout << "remove 5" << std::endl; //7
	tree.deleteNode(5);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;

	tree.print();
		std::cout << "**************************************************" << std::endl;
std::cout << "remove 8" << std::endl;
	tree.deleteNode(8);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;

	tree.print();
	
	std::cout << "**************************************************" << std::endl;
std::cout << "remove 16" << std::endl;
	tree.deleteNode(16);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;

	tree.print();std::cout << "**************************************************" << std::endl;
std::cout << "remove 7" << std::endl;
	tree.deleteNode(7);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;

	tree.print();
	std::cout << "**************************************************" << std::endl;
std::cout << "remove 16" << std::endl;
	tree.deleteNode(16);
	//std::cout << "Trunk = " << tree.getTrunk()->content
	//<< " Leftest = " << tree.getLeftest()->content
	//<< " Rightest = " << tree.getRightest()->content << std::endl;

	tree.print();

	
	ft::map<int, int> truc;

	std::cout << truc.size() << std::endl;
	std::cout << truc.max_size() << std::endl;
	//truc.insert(ft::make_pair(1, 2));
	try
	{
	std::cout << truc.at(5) << std::endl;

	}
	catch (const std::exception &e)
	{
		std::cout << "pouet exception" << std::endl;
	}
	return (0);
}
*/


#include <map>
#include <string>

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


#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class Key, class T>
void	print(std::map<Key, T>& lst)
{
    std::cout << "printing a map : \n";
    for (typename std::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << it->first << " => " << it->second << '\n';
}

int main()
{
    std::cout << _WHITE << "# test_map" << _END << std::endl;
    std::cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
    std::cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
    std::cout << "/* ********************************************************************** */" << _END << std::endl;
    std::cout << std::endl;


    std::map<std::string, int> mymap;
    print(mymap);


    std::cout << "mystd::map<" << _PURPLE << "std::string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap;" << std::endl;

    std::cout << std::endl;
    std::cout << "mymap.max_size(): " << (mymap.max_size() > 10000) << std::endl;
    print(mymap);
    std::cout << std::endl;


    print(mymap);
    mymap.insert(pair<std::string, int>("ft", 42));

    print(mymap);
    mymap.insert(pair<std::string, int>("one", 1));


    std::cout << _WHITE << "# testing upper/lower_bound" << _END << std::endl;
    std::map<std::string, int>::iterator mit;
    std::map<std::string, int>::iterator it;
    print(mymap);
    it = mymap.lower_bound("aaa");
    print(mymap);
    std::cout << std::setw(40) << "mymap.lower_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;
    std::cout << std::endl;
    print(mymap);
    it = mymap.lower_bound("one");
    print(mymap);
    std::cout << std::setw(40) << "mymap.lower_bound(\"one\"): " << it->first << ":" << it->second << std::endl;
    std::cout << std::endl;
    print(mymap);
    it = mymap.lower_bound("oae");
    print(mymap);
    std::cout << std::setw(40) << "mymap.lower_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;
    std::cout << std::endl;
    print(mymap);
    it = mymap.lower_bound("ft");
    print(mymap);
    std::cout << std::setw(40) << "mymap.lower_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;
    std::cout << std::endl;
    print(mymap);
    it = mymap.lower_bound("zzz");
    print(mymap);

    if (it == mymap.end())
        std::cout << std::setw(40) << "mymap.lower_bound(\"zzz\"): mymap.end()" << std::endl;
    std::cout << std::endl;
    print(mymap);
    it = mymap.upper_bound("aaa");

    print(mymap);
    std::cout << std::setw(40) << "mymap.upper_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;;
    std::cout << std::endl;
    print(mymap);
    it = mymap.upper_bound("oae");
    print(mymap);
    std::cout << std::setw(40) << "mymap.upper_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;;
    std::cout << std::endl;
    print(mymap);
    it = mymap.upper_bound("one");

    if (it == mymap.end())
        std::cout << std::setw(40) << "mymap.upper_bound(\"one\"): mymap.end()" << std::endl;
    print(mymap);
    std::cout << std::endl;
    it = mymap.upper_bound("ft");
    print(mymap);
    std::cout << std::setw(40) << "mymap.upper_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;;
    std::cout << std::endl;
    print(mymap);
    it = mymap.upper_bound("zzz");

    if (it == mymap.end())
        std::cout << std::setw(40) << "mymap.upper_bound(\"zzz\"): mymap.end()" << std::endl;
    print(mymap);
    std::cout << std::endl;

    print(mymap);
    mymap.erase("undefined");
    print(mymap);
    mymap.erase("ft");
    print(mymap);
    std::cout << _WHITE << "# double clear" << _END << std::endl;
    mymap.clear();
    print(mymap);
    mymap.clear();
    print(mymap);
    mymap["lol"];
    print(mymap);
    mymap.insert(pair<std::string, int>("xD", 123));
    print(mymap);
    mymap.insert(mymap.end(), pair<std::string, int>("uch", 442));
    print(mymap);
    mymap.insert(mymap.begin(), pair<std::string, int>("uch", 22));
    print(mymap);
    mymap.insert(mymap.end(), pair<std::string, int>("uch", 23));
    print(mymap);
    mymap.insert(pair<std::string, int>("uch", 23));
    print(mymap);
    mymap["lol"] = 8;


    print(mymap);
    std::map<std::string, int> map2;

    print(mymap);
    print(map2);
    std::cout << "mystd::map<" << _PURPLE << "string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap2;" << std::endl;
    print(mymap);
    std::cout << "empty line\n";
    print(map2);
    std::cout << "empty line2\n";

    swap(mymap, map2);
    std::cout << "empty line3\n";
    print(mymap);
    std::cout << "empty line4\n";
    print(map2);
    std::cout << "empty line5\n";

    mymap = map2;
    print(mymap);
    print(map2);

    std::cout << std::setw(40) << "map == map2: " << (mymap == map2) << std::endl;
    print(mymap);
    print(map2);
    std::cout << std::endl;

    mymap.clear();
    print(mymap);
    print(map2);

    mymap["satan"] = 666;
    print(mymap);
    print(map2);
    std::cout << std::setw(40) << "mymap == map2: " << (mymap == map2) << std::endl;
    print(mymap);
    print(map2);
    std::cout << std::endl;
    std::cout << std::setw(40) << "mymap <= map2: " << (mymap <= map2) << std::endl;
    print(mymap);
    print(map2);
    std::cout << std::endl;
    std::cout << std::setw(40) << "mymap >= map2: " << (mymap >= map2) << std::endl;
    print(mymap);
    print(map2);
    std::cout << std::endl;
    std::cout << std::setw(40) << "mymap > map2: " << (mymap > map2) << std::endl;
    print(mymap);
    print(map2);
    std::cout << std::endl;
    std::cout << std::setw(40) << "mymap < map2: " << (mymap > map2) << std::endl;
    print(mymap);
    print(map2);
    std::cout << std::endl;

    return 0;
}
