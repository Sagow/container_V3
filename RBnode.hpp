#pragma once
#include <memory>


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
			
			RBnode() : left(NULL), right(NULL), parent(NULL), colour(false)
			{}

			RBnode(RBnode &src) : content(src.content), left(src.left), right(src.right), parent(src.parent), colour(src.colour)
			{}
			
			RBnode(T val) : content(val), left(NULL), right(NULL), parent(NULL), colour(false)
			{}

			RBnode(RBnode &par, T val) : content(val), left(NULL), right(NULL), parent(&par), colour(false)
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
				size_t	depth = 0;
				RBnode *dad = parent;
				while (*dad)
				{
					if (!dad->colour)
						depth++;
				}
				return (depth);
			}

			void	leftRotate()
			{
				RBnode tmp(*right);

				right->parent = parent;
				right->left = this;
				parent = right;
				right = tmp.left;
				//check les couleurs
			}


			void	rightRotate()
			{
				RBnode tmp(*left);

				left->parent = parent;
				left->right = this;
				parent = left;
				left = tmp.right;
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
	};

	template <class T, class Allocator = std::allocator<RBnode<T> > >
	RBnode<T>*			createNode(T data, RBnode<T>* parent, Allocator alloc)
	{
		RBnode* ptr = alloc.allocate(sizeof(RBnode(parent, data)));
		return (ptr);
	};
}