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
    for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end();)
    {
        std::cout << it->first << " => " << it->second << '\n';
        it++;
    }
}

int main ()
{
    map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;


    map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
    map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

    foo.swap(bar); //tmp iterates through bar
    //tmp2 iterates through foo


    map<char, int>	other;

    other['1'] = 73;
    other['2'] = 173;
    other['3'] = 763;
    other['4'] = 73854;
    other['5'] = 74683;
    other['6'] = 753;

    map<char, int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

    std::cout << "foo contains:\n";
    for (map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "bar contains:\n";
    for (map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    map<char, int>::const_iterator tmpend = bar.end();

    while(tmp != tmpend)
    {
        std::cout << tmp->first << " => " << tmp->second << '\n';
        tmp++;
    }
    tmp--;

    while(tmp2 != foo.end())
    {
        std::cout << tmp2->first << " => " << tmp2->second << '\n';
        tmp2++;
    }
    tmp2--;

    other.swap(foo); //tmp2 iterates through other
    //tmp3 iterates throught foo
    print(other);
    print(foo);
    print(bar);
    while(tmp != bar.begin())
    {
        std::cout << tmp->first << " => " << tmp->second << '\n';
        tmp--;
    }
    std::cout << tmp->first << " => " << tmp->second << '\n';

    while(tmp2 != other.begin())
    {
        std::cout << tmp2->first << " => " << tmp2->second << '\n';
        tmp2--;
    }
    std::cout << tmp2->first << " => " << tmp2->second << '\n';

    while(tmp3 != foo.end())
    {
        std::cout << tmp3->first << " => " << tmp3->second << '\n';
        tmp3++;
    }
    tmp3--;

    bar.swap(foo); //tmp3 iterates through bar
    //tmp iterates through foo

    print(other);
    print(foo);
    print(bar);

    while(tmp != foo.end())
    {
        std::cout << tmp->first << " => " << tmp->second << '\n';
        tmp++;
    }

    while(tmp2 != other.end())
    {
        std::cout << tmp2->first << " => " << tmp2->second << '\n';
        tmp2++;
    }

    while(tmp3 != bar.begin())
    {
        std::cout << tmp3->first << " => " << tmp3->second << '\n';
        tmp3--;
    }
    std::cout << tmp3->first << " => " << tmp3->second << '\n';

    return 0;
}
