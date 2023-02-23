#pragma once
#include <memory>
#include <iostream>
#define BLACK "\e[1;30m"
#define RED "\e[1;31m"
#define END "\e[0m"
#include "algorithm.hpp"
#include "RBtree.hpp"


namespace ft
{
    template <class Key, class T>
	class RBnode{
		public:
			typedef RBnode<Key, T>	node;
			typedef ft::pair<Key, T> pair;

		private:
			pair		_pair;
			node*		left;
			node*		right;
			node*		parent;
			bool		colour;
            RBtree<Key, T>* _belongsTo;
			
		public:

			pair* getPair(void)
			{
				return (&_pair);
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

			node*	getLeft(void)
			{
				return (left);
			}

			node*	getRight(void)
			{
				return (right);
			}

			node*	getParent(void)
			{
				return (parent);
			}

			void	setLeft(node *n)
			{
				left = n;
			}

			void	setRight(node *n)
			{
				right = n;
			}

			void	setParent(node *n)
			{
				parent = n;
			}

			bool&	getColour(void)
			{
				return (colour);
			}

            RBtree<Key, T>* getBelongsTo(void)
            {
                return (_belongsTo);
            }

            void    setBelongsTo(RBtree<Key, T> belongsTo)
            {
                _belongsTo = belongsTo;
            }

			RBnode(RBtree<Key, T>* belongsTo = NULL) : left(NULL), right(NULL), parent(NULL), colour(true), _belongsTo(belongsTo)
			{}

			RBnode(const node &src) : _pair(src._pair), left(src.left), right(src.right), parent(src.parent), colour(src.colour), _belongsTo(src._belongsTo)
			{}
			
			RBnode(ft::pair<Key, T> p, RBtree<Key, T>* belongsTo = NULL) : _pair(p), left(NULL), right(NULL), parent(NULL), colour(true), _belongsTo(belongsTo)
			{}

			RBnode(node *par, ft::pair<Key, T> p) : _pair(p), left(NULL), right(NULL), parent(par), colour(true), _belongsTo(par->_belongsTo)
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

            bool isNull(void)
            {
                if (getBelongsTo() && this == getBelongsTo()->getEndNode())
                    return (true);
                return (false);
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
				node	*n = this;
				if (right)
				{
					n = right;
					while (n->left)
						n = n->left;
					return (n);
				}
				else
				{
                    node    *prt = n->parent;
				    while(prt && n->isRightChild())
                    {
                        n = prt;
                        prt = n->parent;
                    }
                    return (prt);
				}
			}

			node	*getPrevious()
			{
				node	*n = this;
				if (left)
				{
					n = left;
					while (n->right)
						n = n->right;
					return (n);
				}
				else
                {
                    node    *prt = n->parent;
                    while(prt && n->isLeftChild())
                    {
                        n = prt;
                        prt = n->parent;
                    }
                    return (prt);
                }
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
                node	*switchingWith = right;

                right = switchingWith->left;
                if (switchingWith->left)
                    switchingWith->left->parent = this;
                switchingWith->parent = parent;
                if (parent && this->isRightChild())
                    parent->left = switchingWith;
                else if (parent && this->isLeftChild())
                    parent->left = switchingWith;

                switchingWith->left = this;
                parent = switchingWith;
                return (!switchingWith->parent);
			}

			//true si changement de racine
			bool	rightRotate()
			{
				if (!left)
				{
					std::cout << RED << "alerte on switch avec un truc vide" << END << std::endl;
					printRecur();
				}
				node	*switchingWith = left;

               left = switchingWith->right;
                if (switchingWith->right)
                    switchingWith->right->parent = this;
                switchingWith->parent = parent;
                if (parent && this->isLeftChild())
                    parent->left = switchingWith;
                else if (parent && this->isRightChild())
                    parent->right = switchingWith;

                switchingWith->right = this;
                parent = switchingWith;
                return (!switchingWith->parent);

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