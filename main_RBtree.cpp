#include "map/RBnode.hpp"
#include "map/RBtree.hpp"
#include "map/map.hpp"

int main(void)
{
	/*ft::RBtree<int, int>	tree(5, 7);

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

	*/
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