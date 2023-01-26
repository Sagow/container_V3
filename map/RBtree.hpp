/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:01:55 by mdelwaul          #+#    #+#             */
/*   Updated: 2023/01/26 21:56:56 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <memory>
#include <iomanip>
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
#include "RBnode.hpp"

namespace ft
{
	
	template <class Key, class T, class Comparator = ft::less<T>, class Allocator = std::allocator<RBnode<const Key, T> > >
	class RBtree
	{
		private:
			RBnode<const Key, T>	*_trunk;
			size_t			_size;
			
		public:
		
			RBtree()
			{
				_trunk = NULL;
				_size = 0;
			}

			void	insertRecu(RBnode<const Key, T> *node)
			{
				insertNode(node->pair);
				if (node->left)
					insertRecu(node->left);
				if (node->right)
					insertRecu(node->right);
			}
			RBtree(RBtree<const Key, T> &other)
			{
				insertRecu(other._trunk);
			}

			RBtree(ft::pair<const Key, T> val)
			{
				Allocator alloc;
				_trunk = alloc.allocate(sizeof(RBnode<const Key, T>));
				alloc.construct(_trunk, RBnode<const Key, T>(val));
				_size = 1;
				_trunk->colour = false;
			}

			//pas de setter parce que RBtree se gere seul
			size_t	getSize() const
			{
				return (_size);
			}
			
			void	destroyRecu(RBnode<const Key, T> *node)
			{
				Allocator	alloc;
				if (!node)
					return ;
				if (node->left)
					destroyRecu(node->left);
				if (node->right)
					destroyRecu(node->right);
				destroyNode(node);
				_size--;
			}
			
			~RBtree()
			{
				destroyRecu(_trunk);
			}

			
			RBnode<const Key, T>*			getTrunk()
			{
				return (_trunk);
			}
			
			void			insertNode(ft::pair<const Key, T> val)
			{
				RBnode<const Key, T> *next = _trunk;
				RBnode<const Key, T> *parent = NULL;
				Allocator	alloc;
				
				_size++;
				if (!_trunk)
				{
					_trunk = alloc.allocate(sizeof(RBnode<const Key, T>));
					alloc.construct(_trunk, RBnode<const Key, T>(val));
				}
				else
				{
					while (next)
					{
						parent = next;
						if (next->pair.first < val)
							next = next->right;
						else
							next = next->left;
					}

					if (parent->pair.first < val)
					{
						parent->right = alloc.allocate(sizeof(RBnode<const Key, T>));
						next = parent->right;
					}
					else
					{
						parent->left = alloc.allocate(sizeof(RBnode<const Key, T>));
						next = parent->left;
					}
					alloc.construct(next, RBnode<const Key, T>(parent, val));
					balanceTree(next);
				}
			}

			void	balanceTree(RBnode<const Key, T> *lastInserted)
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
			
			void	insertionCase1(RBnode<const Key, T> *n)
			{
				if (!n->parent)
					n->colour = false;
			}
			
			//insertionCase2 n'est pas necessaire puisque c'est le cas ou l'arbre est valide
			
			void	insertionCase3(RBnode<const Key, T> *n)
			{
				n->getUncle()->colour = false;
				n->parent->colour = false;
				n->getGrandparent()->colour = true;
				balanceTree(n->getGrandparent());
			}

			void	insertionCase4(RBnode<const Key, T> *n)
			{
				RBnode<const Key, T>	*p = n->parent;
				RBnode<const Key, T>	*g = n->getGrandparent();
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
			
			void	insertionCase5(RBnode<const Key, T> *n)
			{
				RBnode<const Key, T>	*p = n->parent;
				RBnode<const Key, T>	*g = n->getGrandparent();
				if (n->isLeftChild())
					rightRotate(g);
				else
					leftRotate(g);
				p->colour = false;
				g->colour = true;
			}

			RBnode<const Key, T>	*find(Key key)
			{
				return (_trunk->find(key));
			}

			//base sur https://www.programiz.com/dsa/deletion-from-a-red-black-tree
			void			deleteNode(T val)
			{
				RBnode<const Key, T>	*node = find(val);
				RBnode<const Key, T>	*x = NULL;
				RBnode<const Key, T>	*y = node;
				Allocator	alloc;


				if (!node)
					return ;
				bool	yColour = y->colour;
				_size--;
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
			
			//ATTENTION ce n'est pas une deep copy. pour une deep copy, passer par le constructeur
			RBtree &operator=(const RBtree &src)
			{
				if (this != &src)
				{
					_trunk = src._trunk;
					_size = src._sive;
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

			RBnode<const Key, T>	*leftest()
			{
				if (!_trunk)
					return (NULL);
				RBnode<const Key, T>	*node = _trunk;
				while (node->left)
					node = node->left;
				return (node);
			}

			RBnode<const Key, T>	*rightest()
			{
				if (!_trunk)
					return (NULL);
				RBnode<const Key, T>	*node = _trunk;
				while (node->right)
					node = node->right;
				return (node);
			}
			
			/*void		swap(RBnode	&a, RBnode &b)
			{
				RBnode	aTmp(a);
				RBnode	bTmp(b);

				//a creuser
			}*/

		private:
			void	leftRotate(RBnode<const Key, T> *n)
			{
				//je teste l'existence d'un parent pour verifier que la rotation a bien eu lieu
				if (n->leftRotate() && n->parent)
					_trunk = n->parent;
			}

			void	rightRotate(RBnode<const Key, T> *n)
			{
				//je teste l'existence d'un parent pour verifier que la rotation a bien eu lieu
				if (n->rightRotate() && n->parent)
					_trunk = n->parent;
			}

			void	transplant(RBnode<const Key, T> *u, RBnode<const Key, T> *v)
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

			RBnode<const Key, T>	*minimum(RBnode<const Key, T>	*n)
			{
				while (n->left)
					n = n->left;
				return (n);
			}

			void	deleteFix(RBnode<const Key, T>	*x)
			{
				RBnode<const Key, T>	*s;
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

			bool	isBlack(RBnode<const Key, T> *node)
			{
				if (!node || !node->colour)
					return (true);
				return (false);
			}
			
			void	destroyNode(RBnode<const Key, T>	*node)
			{
				Allocator	alloc;
				if (node->isLeftChild())
					node->parent->left = NULL;
				if (node->isRightChild())
					node->parent->right = NULL;
				alloc.destroy(node);
				alloc.deallocate(node, sizeof(RBnode<const Key, T>));
			}
		
	};

	template<typename T, typename Compare, typename Alloc>
	bool	operator==(RBtree<T, Compare, Alloc> const& t1, RBtree<T, Compare, Alloc> const& t2)
	{
		typedef typename RBtree<T, Compare, Alloc>::iterator iterator;

		iterator	it1;
		iterator	it2;
		for (it1 = t1.begin(), it2 = t2.begin(); it1 != t1.end() && it2 != t2.end(); it1++, it2++)
			if (*it1 != *it2)
				return (false);
		return (it1 == t1.end() && it2 == t2.end());
	}

	template<typename T, typename Compare, typename Alloc>
	bool	operator!=(RBtree<T, Compare, Alloc> const& t1, RBtree<T, Compare, Alloc> const& t2)
	{
		return (!(t1 == t2));
	}

	template<typename T, typename Compare, typename Alloc>
	bool	operator<(RBtree<T, Compare, Alloc> const& t1, RBtree<T, Compare, Alloc> const& t2)
	{
		return (ft::lexicographical_compare(t1.begin(), t1.end(), t2.begin(), t2.end()));
	}

	template<typename T, typename Compare, typename Alloc>
	bool	operator>(RBtree<T, Compare, Alloc> const& t1, RBtree<T, Compare, Alloc> const& t2)
	{
		return (t2 < t1);
	}

	template<typename T, typename Compare, typename Alloc>
	bool	operator<=(RBtree<T, Compare, Alloc> const& t1, RBtree<T, Compare, Alloc> const& t2)
	{
		return (!(t1 > t2));
	}
	template<typename T, typename Compare, typename Alloc>
	bool	operator>=(RBtree<T, Compare, Alloc> const& t1, RBtree<T, Compare, Alloc> const& t2)
	{
		return (!(t1 < t2));
	}
}

