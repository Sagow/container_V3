/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:01:55 by mdelwaul          #+#    #+#             */
/*   Updated: 2023/02/27 18:06:36 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <memory>
#include <iomanip>
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
#include "algorithm.hpp"

namespace ft
{
    template <class Key, class T>
    class RBnode;
	
	template <class Key, class T, typename Comparator = std::less<Key>, class Allocator = std::allocator<RBnode<const Key, T> > >
	class RBtree
	{
		public:
			typedef RBnode<Key, T>	node;
			typedef ft::pair<Key, T> pair;

			node			*_trunk;
			size_t			_size;
			Comparator		_comp;
            Allocator       _alloc;
            node            *_endNode;
            node            *_startNode;

            RBtree(Comparator comp, Allocator alloc): _trunk(NULL), _size(0), _comp(comp), _alloc(alloc)
			{
                allocGardians();
			}

			void	insertRecu(node *n)
			{
                if (!n)
                    return ;
				insertNode(n->getPair());
				if (n->getLeft())
					insertRecu(n->getLeft());
				if (n->getRight())
					insertRecu(n->getRight());
			}
			RBtree(const RBtree<Key, T> &other): _trunk(NULL), _size(0), _comp(other._comp)
			{
                allocGardians();
				insertRecu(other._trunk);
			}


            ~RBtree()
            {

                destroyRecu(_trunk);
				destroyGardians();
            }

			void allocGardians()
			{
                _endNode = _alloc.allocate(sizeof(node));
                _alloc.construct(_endNode, node());
                _startNode = _alloc.allocate(sizeof(node));
                _alloc.construct(_startNode, node());
                _endNode->isEndNode = true;
                _startNode->isEndNode = true;
			}

			void	destroyGardians()
			{
				Allocator   alloc;

				alloc.destroy(_endNode);
				alloc.deallocate(_endNode, sizeof(_endNode));
				alloc.destroy(_startNode);
				alloc.deallocate(_startNode, sizeof(_startNode));
			}

            RBtree(pair val, Comparator &c): _trunk(NULL), _size(0), _comp(c)
			{
				allocGardians();
				Allocator alloc;
                insertNode(val);
				_size = 1;
				_trunk->getColour() = false;
			}

			//pas de setter parce que RBtree se gere seul
			size_t	getSize() const
			{
				return (_size);
			}
			
			void	destroyRecu(node *n)
			{
				Allocator	alloc;
				if (!n || n->isEndNode)
					return ;
				if (n->getLeft())
					destroyRecu(n->getLeft());
				if (n->getRight())
					destroyRecu(n->getRight());
				destroyNode(n);
				_size--;
			}

			
			node*			getTrunk()
			{
				return (_trunk);
			}

            void			setTrunk(node *n)
            {
                _trunk = n;
            }
			
			void			insertNode(pair val)
			{
				node *next = _trunk;
				node *parent = NULL;
				Allocator	alloc;

                leftest()->setLeft(NULL);
                rightest()->setRight(NULL);

				_size++;
				if (!_trunk)
				{
					_trunk = alloc.allocate(sizeof(node));
					alloc.construct(_trunk, node(val));
				}
				else
				{
					while (next)
					{
						parent = next;
						if (_comp((next->getPair()).first, val.first))
							next = next->getRight();
						else
							next = next->getLeft();
					}

					if (_comp(parent->getPair().first, val.first))
					{
						parent->setRight(alloc.allocate(sizeof(node)));
						next = parent->getRight();
					}
					else
					{
						parent->setLeft(alloc.allocate(sizeof(node)));
						next = parent->getLeft();
					}
					alloc.construct(next, node(parent, val));
					balanceTree(next);
				}
				node	*rst = rightest();
				if (rst->isEndNode)
                	_endNode->parent = NULL;
				else
                	_endNode->parent = rightest();
                _startNode->parent = leftest();
                leftest()->setLeft(_startNode);
                rightest()->setRight(_endNode);
			}

			void	balanceTree(node *lastInserted)
			{
				if (!lastInserted)
					return ;
				//Version francaise de la page Wikipedia
				if (!lastInserted->getParent())
					insertionCase1(lastInserted);
				else if (isBlack(lastInserted->getParent()))
					return ;//l'arbre est ok
				else if (!isBlack(lastInserted->getUncle()))
					insertionCase3(lastInserted);
				else
					insertionCase4(lastInserted);
			}
			
			void	insertionCase1(node *n)
			{
				if (!n->getParent())
					n->getColour() = false;
			}
			
			//insertionCase2 n'est pas necessaire puisque c'est le cas ou l'arbre est valide
			
			void	insertionCase3(node *n)
			{
				n->getUncle()->getColour() = false;
				n->getParent()->getColour() = false;
				n->getGrandparent()->getColour() = true;
				balanceTree(n->getGrandparent());
			}

			void	insertionCase4(node *n)
			{
				node	*p = n->getParent();
				node	*g = n->getGrandparent();
				if (!g)
					return ;
				if (g->getLeft() && n == g->getLeft()->getRight())
				{
					leftRotate(p);
					n = n->getLeft();
				}
				else if (g->getRight() && n == g->getRight()->getLeft())
				{
					rightRotate(p);
					n = n->getRight();
				}
				insertionCase5(n);
			}
			
			void	insertionCase5(node *n)
			{
				node	*p = n->getParent();
				node	*g = n->getGrandparent();
				if (n->isLeftChild())
					rightRotate(g);
				else
					leftRotate(g);
				p->getColour() = false;
				g->getColour() = true;
			}

			node	*find(Key key) const
			{
				if (!_trunk)
					return (_endNode);
                node *found = _find(ft::make_pair(key, T()));
                if (found)
				    return (found);
                return (_endNode);
			}

			node	*find(Key key)
			{
				if (!_trunk)
					return (_endNode);
                node *found = _find(ft::make_pair(key, T()));
                if (found)
				    return (found);
                return (_endNode);
			}

            node	*_find(const pair &val, node **leaf = NULL)
            {
                node	*n = _trunk;
				std::cerr << _endNode->isEndNode;
				

                while (n && n != _startNode && n != _endNode)
                {
                    if (leaf)
                        *leaf = n;
                    if (_comp(val.first, n->getPair().first))
                        n = n->left;
                    else if (_comp(n->getPair().first, val.first))
                        n = n->right;
                    else
                        return (n);
                }
				std::cerr << _endNode->isEndNode;
				
                return (n);
            }
            node	*_find(const pair &val, node **leaf = NULL) const
            {
                node	*n = _trunk;
				std::cerr << _endNode->isEndNode;
				

                while (n && n != _startNode && n != _endNode)
                {
                    if (leaf)
                        *leaf = n;
                    if (_comp(val.first, n->getPair().first))
                        n = n->left;
                    else if (_comp(n->getPair().first, val.first))
                        n = n->right;
                    else
                        return (n);
                }
				std::cerr << _endNode->isEndNode;
				
                return (n);
            }
			//base sur https://www.programiz.com/dsa/deletion-from-a-red-black-tree
			void			deleteNode(Key val)
			{
				node	*n = find(val);
				node	*x = NULL;
				node	*y = n;
				Allocator	alloc;

                leftest()->setLeft(NULL);
                rightest()->setRight(NULL);


				if (!n)
					return ;
				bool	yColour = y->getColour();
				_size--;
				//cas ou au moins un des enfants est nul
				if (!n->getLeft())
				{
					x = n->getRight();
					transplant(n, n->getRight());
				}
				else if (!n->getRight())
				{
					x = n->getLeft();
					transplant(n, n->getLeft());
				}
				//cas ou les deux enfants existent
				else
				{
					y = minimum(n->getRight());
					yColour = y->getColour();
					x = y->getRight();
					if (y->getParent() == n && x)
						x->setParent(y);
					else
					{
						transplant(y, y->getRight());
						y->setRight(n->getRight());
                        if (y->getRight())
						    y->getRight()->setParent(y);
					}
					transplant(n, y);
					y->setLeft(n->getLeft());
					y->getLeft()->setParent(y);
					y->getColour() = n->getColour();
				}
				destroyNode(n);
				if (!yColour)
					deleteFix(x);
                _endNode->parent = rightest();
                _startNode->parent = leftest();
                leftest()->setLeft(_startNode);
                rightest()->setRight(_endNode);
			}

			void	swap(RBtree &tree)
			{
				ft::__swap(_trunk, tree._trunk);
				ft::__swap(_size, tree._size);
				ft::__swap(_endNode, tree._endNode);
				ft::__swap(_comp, tree._comp);
				ft::__swap(_startNode, tree._startNode);
				ft::__swap(_alloc, tree._alloc);
			}

			//ATTENTION ce n'est pas une deep copy. pour une deep copy, passer par le constructeur
			RBtree &operator=(const RBtree &src)
			{
				if (this != &src)
				{
					if (_size)
						destroyRecu(_trunk);
					_trunk = NULL;
					insertRecu(src._trunk);
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

			node	*leftest() const
			{
				if (!_trunk)
					return (_endNode);
				node	*n = _trunk;
				while (n->getLeft() && !n->getLeft()->isEndNode)
					n = n->getLeft();
				return (n);
			}

			node	*rightest() const
			{
				if (!_trunk)
					return (_endNode);
				node	*n = _trunk;
				while (n->getRight() && !n->getRight()->isEndNode)
					n = n->getRight();
				return (n);
			}
			
			/*void		swap(RBnode	&a, RBnode &b)
			{
				RBnode	aTmp(a);
				RBnode	bTmp(b);

				//a creuser
			}*/

		private:
			void	leftRotate(node *n)
			{
				//je teste l'existence d'un parent pour verifier que la rotation a bien eu lieu
				if (n->leftRotate() && n->getParent())
					_trunk = n->getParent();
			}

			void	rightRotate(node *n)
			{
				//je teste l'existence d'un parent pour verifier que la rotation a bien eu lieu
				if (n->rightRotate() && n->getParent())
					_trunk = n->getParent();
			}

			void	transplant(node *u, node *v)
			{
				if (!u->getParent())
					_trunk = v;
				else if (u->isLeftChild())
					u->getParent()->setLeft(v);
				else
					u->getParent()->setRight(v);
				if (v)
					v->setParent(u->getParent());
			}

			node	*minimum(node	*n)
			{
				while (n->getLeft())
					n = n->getLeft();
				return (n);
			}

			void	deleteFix(node	*x)
			{
				node	*s;
				if (!x)
					return ;
				while (x != _trunk && isBlack(x))
				{
					if (x->isLeftChild())
					{
						s = x->getParent()->getRight();
						if (!isBlack(s))
						{
							s->getColour() = false;
							x->getParent()->getColour() = true;
							leftRotate(x->getParent());
							s = x->getParent()->getRight();
						}
						if (isBlack(s->getLeft()) && isBlack(s->getRight()))
						{
							s->getColour() = true;
							x = x->getParent();
						}
						else
						{
							if (isBlack(s->getRight()))
							{
								s->getLeft()->getColour() = false;
								s->getColour() = true;
								rightRotate(s);
								s = x->getParent()->getRight();
							}
							s->getColour() = x->getParent()->getColour();
							x->getParent()->getColour() = false;
							s->getRight()->getColour() = false;
							leftRotate(x->getParent());
							x = _trunk;
						}
					}
					else
					{
						s = x->getParent()->getLeft();
						if (!isBlack(s))
						{
							s->getColour() = false;
							x->getParent()->getColour() = true;
							rightRotate(x->getParent());
							s = x->getParent()->getLeft();
						}
						//j'ai fait une correction par rapport au code d'origine
						if (isBlack(s->getLeft()) && isBlack(s->getRight()))
						{
							s->getColour() = true;
							x = x->getParent();
						}
						else
						{
							if (isBlack(s->getLeft()))
							{
								s->getRight()->getColour() = false;
								s->getColour() = true;
								leftRotate(s);
								s = x->getParent()->getLeft();
							}
							s->getColour() = x->getParent()->getColour();
							x->getParent()->getColour() = false;
							s->getLeft()->getColour() = false;
							rightRotate(x->getParent());
							x = _trunk;
						}
					}
				}
				x->getColour() = false;
			}

			bool	isBlack(node *n)
			{
				if (!n || !n->getColour())
					return (true);
				return (false);
			}
			
			void	destroyNode(node	*n)
			{
				Allocator	alloc;
				if (n->isLeftChild())
					n->getParent()->setLeft(NULL);
				if (n->isRightChild())
					n->getParent()->setRight(NULL);
				alloc.destroy(n);
				alloc.deallocate(n, sizeof(node));
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

