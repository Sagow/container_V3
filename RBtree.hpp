/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:01:55 by mdelwaul          #+#    #+#             */
/*   Updated: 2023/01/22 06:53:26 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <iomanip>
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
#include "RBnode.hpp"

namespace ft
{
	
	template <class T, class Allocator = std::allocator<RBnode<T> > >
	class RBtree
	{
		private:
			RBnode<T>	*_trunk;
			RBnode<T>	*_leftest;
			RBnode<T>	*_rightest;
			
		public:
		
			RBtree()
			{
				_trunk = NULL;
				_leftest = NULL;
				_rightest = NULL;
			}

			RBtree(T val)
			{
				Allocator alloc;
				_trunk = alloc.allocate(sizeof(RBnode<T>));
				alloc.construct(_trunk, RBnode<T>(val));
				_trunk->colour = false;
				_leftest = _trunk;
				_rightest = _trunk;
			}
			
			void	destroyRecu(RBnode<T> *node)
			{
				Allocator	alloc;
				if (node->left)
					destroyRecu(node->left);
				if (node->right)
					destroyRecu(node->right);
				alloc.destroy(node);
				alloc.deallocate(node, sizeof(RBnode<T>));
			}
			
			~RBtree()
			{
				destroyRecu(_trunk);
			}

			
			RBnode<T>*			getTrunk()
			{
				return (_trunk);
			}
			
			RBnode<T>*			getLeftest()
			{
				return (_leftest);
			}
			
			RBnode<T>*			getRightest()
			{
				return (_rightest);
			}
			
			void			insertNode(T val)
			{
				RBnode<T> *next = _trunk;
				RBnode<T> *parent = NULL;
				Allocator	alloc;
				
				if (!_trunk)
				{
					_trunk = alloc.allocate(sizeof(RBnode<T>));
					alloc.construct(_trunk, RBnode<T>(val));
					_leftest = _trunk;
					_rightest = _trunk;
				}
				else
				{
					while (next)
					{
						parent = next;
						if (next->content < val)
							next = next->right;
						else
							next = next->left;
					}

					if (parent->content < val)
					{
						parent->right = alloc.allocate(sizeof(RBnode<T>));
						next = parent->right;
					}
					else
					{
						parent->left = alloc.allocate(sizeof(RBnode<T>));
						next = parent->left;
					}
					alloc.construct(next, RBnode<T>(parent, val));
					balanceTree(next);
					if (val < _leftest->content)
						_leftest = next;
					else if (_rightest->content < val)
						_rightest = next;
				}
			}

			void	balanceTree(RBnode<T> *lastInserted)
			{
				if (!lastInserted)
					return ;
				//Version francaise de la page Wikipedia
				if (!lastInserted->parent)
					insertionCase1(lastInserted);
				else if (!lastInserted->parent->colour)
					return ;//l'arbre est ok
				else if (lastInserted->getUncle() && lastInserted->getUncle()->colour)
					insertionCase3(lastInserted);
				else
					insertionCase4(lastInserted);
			}
			
			void	insertionCase1(RBnode<T> *n)
			{
				if (!n->parent)
					n->colour = false;
			}
			
			//insertionCase2 n'est pas necessaire puisque c'est le cas ou l'arbre est valide
			
			void	insertionCase3(RBnode<T> *n)
			{
				n->getUncle()->colour = false;
				n->parent->colour = false;
				n->getGrandparent()->colour = true;
				balanceTree(n->getGrandparent());
			}

			void	insertionCase4(RBnode<T> *n)
			{
				RBnode<T>	*p = n->parent;
				RBnode<T>	*g = n->getGrandparent();
				if (!g)
					return ;
				if (g->left && n == g->left->right)
				{
					leftRotate(p);
					n = n->left;
				}
				else if (g->right && n == g->right->left)
				{
					rightRotate(p);
					n = n->right;
				}
				insertionCase5(n);
			}
			
			void	insertionCase5(RBnode<T> *n)
			{
				RBnode<T>	*p = n->parent;
				RBnode<T>	*g = n->getGrandparent();
				if (n->isLeftChild())
					rightRotate(g);
				else
					leftRotate(g);
				p->colour = false;
				g->colour = true;
			}
			
			void			deleteNode(T* ptr)
			{
				(void) ptr;
			}
			
			//ATTENTION ce n'est pas une deep copy
			RBtree &operator=(const RBtree &src)
			{
				if (this != &src)
				{
					_trunk = src._trunk;
					_leftest = src._leftest;
					_rightest = src._rightest;
				}
				return (*this);
			}
			
			void	print(void)
			{
				if (!_trunk)
				{
					std::cout << "Cet arbre est vide" << std::endl;
					return ;
				}
				std::cout << "L'arbre contient " << std::endl << _trunk->printRecur() << " elements" << std::endl;
			}
			

		private:
			void	leftRotate(RBnode<T> *n)
			{
				//je teste l'existence d'un parent pour verifier que la rotation a bien eu lieu
				if (n->leftRotate() && n->parent)
					_trunk = n->parent;
			}

			void	rightRotate(RBnode<T> *n)
			{
				//je teste l'existence d'un parent pour verifier que la rotation a bien eu lieu
				if (n->rightRotate() && n->parent)
					_trunk = n->parent;
			}
		
	};
}

