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
				/*size_t add;
				
				if (!this)
					return (depth);
				if (!colour)
					depth++;
				if (right)
				{
					add = right->getDepth(depth);
					if (add > depth)
						depth = add;
				}
				if (left)
				{
					add = left->getDepth(depth);
					if (add > depth)
						depth = add;
				}*/
				RBnode<T> *dad = parent;
				while (dad)
				{
					//if (!dad->colour)
						depth++;
					dad = dad->parent;
				}
				return (depth);
			}

			//true si changement de racine
			bool	leftRotate()
			{
				bool	trunk = false;
				if (!right)
					return (false);
				if (!parent)
					trunk = true;
				RBnode tmp(*right);
				right->parent = parent;
				right->left = this;
				parent = right;
				right = tmp.left;
				return (trunk);
				//check les couleurs
			}

			//true si changement de racine
			bool	rightRotate()
			{
				bool	trunk = false;
				if (!left)
					return (false);
				if (!parent)
					trunk = true;
				RBnode tmp(*left);
				left->parent = parent;
				left->right = this;
				parent = left;
				left = tmp.right;
				return (trunk);
				//check les couleurs
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
	
			void	printRecur(int decal = 0)
			{
				if (left)
					left->printRecur(decal + 1);
				for (int i = 0; i < decal; i++)
					std::cout << "    ";
				std::cout << (colour ? RED : BLACK) << content << END << std::endl;
				if (right)
					right->printRecur(decal + 1);
			}
	};

	/*template <class T, class Allocator = std::allocator<RBnode<T> > >
	RBnode<T>*			createNode(T data, RBnode<T>* parent, Allocator alloc)
	{
		RBnode<T>* ptr = alloc.allocate(sizeof(RBnode<T>(parent, data)));
		return (ptr);
	};*/
}