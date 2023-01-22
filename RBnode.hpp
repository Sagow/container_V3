#pragma once
#include <memory>
#include <iostream>
#define BLACK "\e[1;30m"
#define RED "\e[1;31m"
#define END "\e[0m"

namespace ft
{
	template <class T>
	class RBnode{
		public:
			T				content;
			RBnode*			left;
			RBnode*			right;
			RBnode*			parent;
			bool			colour;
			
			RBnode() : left(NULL), right(NULL), parent(NULL), colour(true)
			{}

			RBnode(const RBnode &src) : content(src.content), left(src.left), right(src.right), parent(src.parent), colour(src.colour)
			{}
			
			RBnode(const T val) : content(val), left(NULL), right(NULL), parent(NULL), colour(true)
			{}

			RBnode(RBnode *par, const T val) : content(val), left(NULL), right(NULL), parent(par), colour(true)
			{}

			~RBnode()
			{}

			
			RBnode &operator=(const RBnode &src)
			{
				content = src.content;
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

			RBnode	*getUncle()
			{
				if (!parent || !parent->parent)
					return (NULL);
				if (parent->parent->left == parent)
					return (parent->parent->right);
				return (parent->parent->left);
			}

			RBnode *getGrandparent()
			{
				if (!parent)
					return (NULL);
				return (parent->parent);
			}

			size_t			getDepth(size_t depth = 0)
			{
				RBnode<T> *dad = parent;
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
				RBnode	*grandparent = parent;
				RBnode	*switchingWith = right;
				RBnode	*pendulum = right->left;
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
				RBnode	*grandparent = parent;
				RBnode	*switchingWith = left;
				RBnode	*pendulum = left->right;
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
			
			RBnode	*find(T val)
			{
				RBnode	*ret = NULL;
				if (content == val)
					ret = this;
				else
				{
					if (left)
						ret = left->find(val);
					if (!ret && right)
						ret = right->find(val);
				}
				return (ret);
			}

			RBnode	*nextLeaf()
			{
				RBnode	*current = this;
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
				std::cout << (colour ? RED : BLACK) << content << END << std::endl << std::endl;
				if (right)
					size += right->printRecur(decal + 1);
				return (size);
			}

	};
}