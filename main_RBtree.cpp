#include "RBnode.hpp"
#include "RBtree.hpp"

int main(void)
{
	ft::RBtree<int>	tree(5);

	std::cout << "Trunk = " << tree.getTrunk()->content
	<< " Leftest = " << tree.getLeftest()->content
	<< " Rightest = " << tree.getRightest()->content << std::endl;

	std::cout << "insert 1" << std::endl;
	tree.insertNode(1);
	std::cout << "Trunk = " << tree.getTrunk()->content
	<< " Leftest = " << tree.getLeftest()->content
	<< " Rightest = " << tree.getRightest()->content << std::endl;

	std::cout << "insert 10" << std::endl;
	tree.insertNode(10);
	std::cout << "Trunk = " << tree.getTrunk()->content
	<< " Leftest = " << tree.getLeftest()->content
	<< " Rightest = " << tree.getRightest()->content << std::endl;

	std::cout << "insert 8" << std::endl;
	tree.insertNode(8);
	std::cout << "Trunk = " << tree.getTrunk()->content
	<< " Leftest = " << tree.getLeftest()->content
	<< " Rightest = " << tree.getRightest()->content << std::endl;

	std::cout << "insert 9" << std::endl;
	tree.insertNode(9);
	std::cout << "Trunk = " << tree.getTrunk()->content
	<< " Leftest = " << tree.getLeftest()->content
	<< " Rightest = " << tree.getRightest()->content << std::endl;


	std::cout << "insert 7" << std::endl;
	tree.insertNode(7);
	std::cout << "Trunk = " << tree.getTrunk()->content
	<< " Leftest = " << tree.getLeftest()->content
	<< " Rightest = " << tree.getRightest()->content << std::endl;

	std::cout << "insert 17" << std::endl;
	tree.insertNode(17);
	std::cout << "Trunk = " << tree.getTrunk()->content
	<< " Leftest = " << tree.getLeftest()->content
	<< " Rightest = " << tree.getRightest()->content << std::endl;

std::cout << "insert 18" << std::endl;
	tree.insertNode(18);
	std::cout << "Trunk = " << tree.getTrunk()->content
	<< " Leftest = " << tree.getLeftest()->content
	<< " Rightest = " << tree.getRightest()->content << std::endl;

std::cout << "insert 19" << std::endl;
	tree.insertNode(19);
	std::cout << "Trunk = " << tree.getTrunk()->content
	<< " Leftest = " << tree.getLeftest()->content
	<< " Rightest = " << tree.getRightest()->content << std::endl;

std::cout << "insert 20" << std::endl;
	tree.insertNode(20);
	std::cout << "Trunk = " << tree.getTrunk()->content
	<< " Leftest = " << tree.getLeftest()->content
	<< " Rightest = " << tree.getRightest()->content << std::endl;

std::cout << "insert 21" << std::endl;
	tree.insertNode(21);
	std::cout << "Trunk = " << tree.getTrunk()->content
	<< " Leftest = " << tree.getLeftest()->content
	<< " Rightest = " << tree.getRightest()->content << std::endl;

std::cout << "insert 16" << std::endl;
	tree.insertNode(16);
	std::cout << "Trunk = " << tree.getTrunk()->content
	<< " Leftest = " << tree.getLeftest()->content
	<< " Rightest = " << tree.getRightest()->content << std::endl;

	tree.print();

	return 0;
}