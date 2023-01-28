#pragma once
#include <memory>
#include <iostream>
#define BLACK "\e[1;30m"
#define RED "\e[1;31m"
#define END "\e[0m"
#include "../algorithm.hpp"

namespace ft
{
	template <class Key, class T >
	class RBnode{
		public:
			ft::pair<const Key, T>			pair;
			RBnode<const Key, T>*			left;
			RBnode<const Key, T>*			right;
			RBnode<const Key, T>*			parent;
			bool			colour;
			
			RBnode() : left(NULL), right(NULL), parent(NULL), colour(true)
			{}

			RBnode(const RBnode<const Key, T> &src) : pair(src.pair), left(src.left), right(src.right), parent(src.parent), colour(src.colour)
			{}
			
			RBnode(ft::pair<const Key, T> p) : pair(p), left(NULL), right(NULL), parent(NULL), colour(true)
			{}

			RBnode(RBnode<const Key, T> *par, ft::pair<const Key, T> p) : pair(p), left(NULL), right(NULL), parent(par), colour(true)
			{}

			~RBnode()
			{}

			
			RBnode<const Key, T> &operator=(const RBnode<const Key, T> &src)
			{
				pair.second = src.pair.second;
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

			RBnode<const Key, T>	*getUncle()
			{
				if (!parent || !parent->parent)
					return (NULL);
				if (parent->parent->left == parent)
					return (parent->parent->right);
				return (parent->parent->left);
			}

			RBnode<const Key, T> *getGrandparent()
			{
				if (!parent)
					return (NULL);
				return (parent->parent);
			}

			RBnode<const Key, T>	*getNext()
			{
				RBnode<const Key, T>	*node;
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

			RBnode<const Key, T>	*getPrevious()
			{
				RBnode<const Key, T>	*node;
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

			RBnode<const Key, T>	*biggerCousin()
			{
				if (!parent)
					return (this);
				if (isLeftChild() && parent->right)
					return (parent->right);
				return (biggerCousin(parent));
			}

			RBnode<const Key, T>	*smallerCousin()
			{
				if (!parent)
					return (this);
				if (isRightChild() && parent->left)
					return (parent->left);
				return (smallerCousin(parent));
			}

			size_t			getDepth(size_t depth = 0)
			{
				RBnode<const Key, T> *dad = parent;
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
					std::cout << RED << "alerte on switch " << this << " avec un truc vide" << END << std::endl;
					printRecur();
				}
				RBnode<const Key, T>	*grandparent = parent;
				RBnode<const Key, T>	*switchingWith = right;
				RBnode<const Key, T>	*pendulum = right->left;
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
					std::cout << RED << "alerte on switch " << this->content << " avec un truc vide" << END << std::endl;
					printRecur();
				}
				RBnode<const Key, T>	*grandparent = parent;
				RBnode<const Key, T>	*switchingWith = left;
				RBnode<const Key, T>	*pendulum = left->right;
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
			
			RBnode<Key, T>	*find(Key val)
			{
				RBnode<const Key, T>	*ret = NULL;
				if (pair.first == val)
					ret = this;
				else
				{
					if (pair.first > val && left)
						ret = left->find(val);
					else if (right)
						ret = right->find(val);
				}
				return (ret);
			}

			RBnode<const Key, T>	*nextLeaf()
			{
				RBnode<const Key, T>	*current = this;
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
				std::cout << (colour ? RED : BLACK) << pair.first << ":" << pair.second << END << std::endl << std::endl;
				if (right)
					size += right->printRecur(decal + 1);
				return (size);
			}

	};
}