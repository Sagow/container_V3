/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:01:55 by mdelwaul          #+#    #+#             */
/*   Updated: 2023/01/22 16:01:08 by mdelwaul         ###   ########.fr       */
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
			
		public:
		
			RBtree()
			{
				_trunk = NULL;
			}

			void	insertRecu(RBnode<T> *node)
			{
				insert(node->content);
				if (node->left)
					insertRecu(node->left);
				if (node->right)
					insertRecu(node->right);
			}
			RBtree(RBtree<T> &other)
			{
				insertRecu(_trunk);
			}

			RBtree(T val)
			{
				Allocator alloc;
				_trunk = alloc.allocate(sizeof(RBnode<T>));
				alloc.construct(_trunk, RBnode<T>(val));
				_trunk->colour = false;
			}
			
			void	destroyRecu(RBnode<T> *node)
			{
				Allocator	alloc;
				if (node->left)
					destroyRecu(node->left);
				if (node->right)
					destroyRecu(node->right);
				destroyNode(node);
			}
			
			~RBtree()
			{
				destroyRecu(_trunk);
			}

			
			RBnode<T>*			getTrunk()
			{
				return (_trunk);
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
				}
			}

			void	balanceTree(RBnode<T> *lastInserted)
			{
				if (!lastInserted)
					return ;
				//Version francaise de la page Wikipedia
				if (!lastInserted->parent)
					insertionCase1(lastInserted);
				else if (isBlack(lastInserted->parent))
					return ;//l'arbre est ok
				else if (!isBlack(lastInserted->getUncle()))
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

			RBnode<T>	*find(T val)
			{
				return (_trunk->find(val));
			}

			//base sur https://www.programiz.com/dsa/deletion-from-a-red-black-tree
			void			deleteNode(T val)
			{
				RBnode<T>	*node = find(val);
				RBnode<T>	*x = NULL;
				RBnode<T>	*y = node;
				Allocator	alloc;


				if (!node)
					return ;
				bool	yColour = y->colour;
				//cas ou au moins un des enfants est nul
				if (!node->left)
				{
					x = node->right;
					transplant(node, node->right);
				}
				else if (!node->right)
				{
					x = node->left;
					transplant(node, node->left);
				}
				//cas ou les deux enfants existent
				else
				{
					y = minimum(node->right);
					yColour = y->colour;
					x = y->right;
					if (y->parent == node)
						x->parent = y;
					else
					{
						transplant(y, y->right);
						y->right = node->right;
						y->right->parent = y;
					}
					transplant(node, y);
					y->left = node->left;
					y->left->parent = y;
					y->colour = node->colour;
				}
				destroyNode(node);
				if (!yColour)
					deleteFix(x);
			}
			
			//ATTENTION ce n'est pas une deep copy
			RBtree &operator=(const RBtree &src)
			{
				if (this != &src)
					_trunk = src._trunk;
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

			RBnode<T>	*leftest()
			{
				if (!_trunk)
					return (NULL);
				RBnode<T>	*node = _trunk;
				while (node->left)
					node = node->left;
				return (node);
			}

			RBnode<T>	*rightest()
			{
				if (!_trunk)
					return (NULL);
				RBnode<T>	*node = _trunk;
				while (node->right)
					node = node->right;
				return (node);
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

			void	transplant(RBnode<T> *u, RBnode<T> *v)
			{
				if (!u->parent)
					_trunk = v;
				else if (u->isLeftChild())
					u->parent->left = v;
				else
					u->parent->right = v;
				if (v)
					v->parent = u->parent;
			}

			RBnode<T>	*minimum(RBnode<T>	*n)
			{
				while (n->left)
					n = n->left;
				return (n);
			}

			void	deleteFix(RBnode<T>	*x)
			{
				RBnode<T>	*s;
				if (!x)
					return ;
				while (x != _trunk && isBlack(x))
				{
					if (x->isLeftChild())
					{
						s = x->parent->right;
						if (!isBlack(s))
						{
							s->colour = false;
							x->parent->colour = true;
							leftRotate(x->parent);
							s = x->parent->right;
						}
						if (isBlack(s->left) && isBlack(s->right))
						{
							s->colour = true;
							x = x->parent;
						}
						else
						{
							if (isBlack(s->right))
							{
								s->left->colour = false;
								s->colour = true;
								rightRotate(s);
								s = x->parent->right;
							}
							s->colour = x->parent->colour;
							x->parent->colour = false;
							s->right->colour = false;
							leftRotate(x->parent);
							x = _trunk;
						}
					}
					else
					{
						s = x->parent->left;
						if (!isBlack(s))
						{
							s->colour = false;
							x->parent->colour = true;
							rightRotate(x->parent);
							s = x->parent->left;
						}
						//j'ai fait une correction par rapport au code d'origine
						if (isBlack(s->left) && isBlack(s->right))
						{
							s->colour = true;
							x = x->parent;
						}
						else
						{
							if (isBlack(s->left))
							{
								s->right->colour = false;
								s->colour = true;
								leftRotate(s);
								s = x->parent->left;
							}
							s->colour = x->parent->colour;
							x->parent->colour = false;
							s->left->colour = false;
							rightRotate(x->parent);
							x = _trunk;
						}
					}
				}
				x->colour = false;
			}

			bool	isBlack(RBnode<T> *node)
			{
				if (!node || !node->colour)
					return (true);
				return (false);
			}
			
			void	destroyNode(RBnode<T>	*node)
			{
				Allocator	alloc;
				if (node->isLeftChild())
					node->parent->left = NULL;
				if (node->isRightChild())
					node->parent->right = NULL;
				alloc.destroy(node);
				alloc.deallocate(node, sizeof(RBnode<T>));
			}
		
	};
}

