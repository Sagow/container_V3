#pragma once
#include <memory>
#include <iostream>
#define BLACK "\e[1;30m"
#define RED "\e[1;31m"
#define END "\e[0m"
#include "algorithm.hpp"

namespace ft
{
	template <class Key, class T >
	class RBnode{
		public:
			typedef RBnode<Key, T>	node;
			typedef ft::pair<const Key, T> pair;

		private:
			pair		_pair;
			node*		left;
			node*		right;
			node*		parent;
			bool		colour;
			
		public:

			pair& getPair(void) const
			{
				return (_pair);
			}

			void	setPair(pair p)
			{
				_pair = p;
			}

			Key	getKey(void) const
			{
				return (_pair.first);
			}

			//setKey ne peut pas exister puisque c'est const

			T&	getVal(void) const
			{
				return (_pair.second);
			}

			void	setVal(T v)
			{
				_pair.second = v;
			}

			node&	getLeft(void)
			{
				return (left);
			}

			node&	getRight(void)
			{
				return (right);
			}

			node&	getParent(void)
			{
				return (parent);
			}

			bool&	getColour(void)
			{
				return (colour);
			}

			RBnode() : left(NULL), right(NULL), parent(NULL), colour(true)
			{}

			RBnode(const node &src) : _pair(src._pair), left(src.left), right(src.right), parent(src.parent), colour(src.colour)
			{}
			
			RBnode(ft::pair<Key, T> p) : _pair(p), left(NULL), right(NULL), parent(NULL), colour(true)
			{}

			RBnode(node *par, ft::pair<Key, T> p) : _pair(p), left(NULL), right(NULL), parent(par), colour(true)
			{}

			~RBnode()
			{}

			
			node &operator=(const node &src)
			{
				_pair.second = src._pair.second;
				left = src.left;
				right = src.right;
				parent = src.parent;
				colour = src.colour;
				return (*this);
			}

			bool isLeftChild(void)
			{
				if (parent && parent->left == this)
					return (true);
				return (false);
			}

			bool isRightChild(void)
			{
				if (parent && parent->right == this)
					return (true);
				return (false);
			}

			node	*getUncle()
			{
				if (!parent || !parent->parent)
					return (NULL);
				if (parent->parent->left == parent)
					return (parent->parent->right);
				return (parent->parent->left);
			}

			node *getGrandparent()
			{
				if (!parent)
					return (NULL);
				return (parent->parent);
			}

			node	*getNext()
			{
				node	*node;
				if (right)
				{
					node = right;
					while (node->left)
						node = node->left;
					return (node);
				}
				else if (isLeftChild())
				{
					return (parent);
				}
				else if (biggerCousin())
				{
					node = biggerCousin();
					while (node->left)
						node = node->left;
					return (node);
				}
				else
					return (this + 1);
			}

			node	*getPrevious()
			{
				node	*node;
				if (left)
				{
					node = left;
					while (node->right)
						node = node->right;
					return (node);
				}
				else if (isRightChild())
				{
					return (parent);
				}
				else if (smallerCousin())
				{
					node = smallerCousin();
					while (node->left)
						node = node->left;
					return (node);
				}
				else
					return (this + 1);
			}

			node	*biggerCousin()
			{
				if (!parent)
					return (this);
				if (isLeftChild() && parent->right)
					return (parent->right);
				return (biggerCousin(parent));
			}

			node	*smallerCousin()
			{
				if (!parent)
					return (this);
				if (isRightChild() && parent->left)
					return (parent->left);
				return (smallerCousin(parent));
			}

			size_t			getDepth(size_t depth = 0)
			{
				node *dad = parent;
				while (dad)
				{
					if (!dad->colour)
						depth++;
					dad = dad->parent;
				}
				return (depth);
			}

			//true si changement de racine
			bool	leftRotate()
			{
				if (!right)
				{
					std::cout << RED << "alerte on switch avec un truc vide" << END << std::endl;
					printRecur();
				}
				node	*grandparent = parent;
				node	*switchingWith = right;
				node	*pendulum = right->left;
				if (isLeftChild())
					grandparent->left = switchingWith;
				else if (isRightChild())
					grandparent->right = switchingWith;
				parent = switchingWith;
				right = pendulum;
				switchingWith->parent = grandparent;
				switchingWith->left = this;
				return (!grandparent);
			}

			//true si changement de racine
			bool	rightRotate()
			{
				if (!left)
				{
					std::cout << RED << "alerte on switch avec un truc vide" << END << std::endl;
					printRecur();
				}
				node	*grandparent = parent;
				node	*switchingWith = left;
				node	*pendulum = left->right;
				if (isLeftChild())
					grandparent->left = switchingWith;
				else
					grandparent->right = switchingWith;
				parent = switchingWith;
				left = pendulum;
				switchingWith->parent = grandparent;
				switchingWith->right = this;
				return (!grandparent);
			}
			
			node	*find(Key val)
			{
				node	*ret = NULL;
				if (_pair.first == val)
					ret = this;
				else
				{
					if (_pair.first > val && left)
						ret = left->find(val);
					else if (right)
						ret = right->find(val);
				}
				return (ret);
			}

			node	*nextLeaf()
			{
				node	*current = this;
				if (current->parent == NULL)
					return (NULL);
				if (current->parent->left == current && current->parent->right)
				{
					return (current->parent->right);
				}
				while (current->parent->right == current)
				{
					if (current->parent == NULL)
						return (NULL); 
					current = current->parent;
				}
				current = current->right;
				while (current->left || current->right)
				{
					if (current->left)
						current = current->left;
					else
						current = current->right;
				}
				return (current);
			}

			bool	onlyChild()
			{
				if (this->parent == NULL)
					return (true);
				if (this->parent->left == NULL || this->parent->right == NULL)
					return (true);
				return (false);
			}
	
			int	printRecur(int decal = 0)
			{
				int size = 1;
				if (left)
					size += left->printRecur(decal + 1);
				for (int i = 0; i < decal; i++)
					std::cout << "    ";
				std::cout << (colour ? RED : BLACK) << _pair.first << ":" << _pair.second << END << std::endl << std::endl;
				if (right)
					size += right->printRecur(decal + 1);
				return (size);
			}

	};
}