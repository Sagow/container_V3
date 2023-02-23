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
        std::cout << *it << ' ';
    std::cout << '\n';
}

int main()
{
    pair<int, std::string>			my_pair(8, "salut");
    map<int, std::string>			test;
    map<int, std::string>::iterator	it;

    test.insert(my_pair);
    test.insert(pair<int, std::string>(-4, "bar"));
    test.insert(pair<int, std::string>(2, "machin"));
    test.insert(pair<int, std::string>(3, "foo"));
    test.insert(pair<int, std::string>(746, "Marcel"));
    test.insert(pair<int, std::string>(1, "truc"));
    it = test.begin();
    std::cout << '\n';

    while (it != test.end())
    {
        // std::cout << "start of while\n";
        std::cout << it->first << ", " << it->second << '\n';
        it++;
// 		std::cout << "iterator incremented\n";

// #ifndef STD
// 		std::cout << it.getPointer() << '\n';
// 		std::cout << test.end().getPointer() << '\n';
// #endif

    }
    std::cout << "End of display loop\n";
}
