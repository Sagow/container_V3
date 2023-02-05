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
#include "common.hpp"
#include <list>

#define T1 int
#define T2 foo<int>
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator ft_iterator;
typedef TESTED_NAMESPACE::map<T1, T2>::const_iterator ft_const_iterator;

static int iter = 0;

template <typename MAP>
void	ft_bound(MAP &mp, const T1 &param)
{
	ft_iterator ite = mp.end(), it[2];
	_pair<ft_iterator, ft_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename MAP>
void	ft_const_bound(const MAP &mp, const T1 &param)
{
	ft_const_iterator ite = mp.end(), it[2];
	_pair<ft_const_iterator, ft_const_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i + 1, (i + 1) * 3));
	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);

	ft_const_bound(mp, -10);
	ft_const_bound(mp, 1);
	ft_const_bound(mp, 5);
	ft_const_bound(mp, 10);
	ft_const_bound(mp, 50);

	printSize(mp);

	mp.lower_bound(3)->second = 404;
	mp.upper_bound(7)->second = 842;
	ft_bound(mp, 5);
	ft_bound(mp, 7);

	printSize(mp);
	return (0);
}