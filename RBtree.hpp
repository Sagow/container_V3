/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:01:55 by mdelwaul          #+#    #+#             */
/*   Updated: 2023/01/09 17:40:44 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <iomanip>
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
#include "RBnode.hpp"

/*Notes : pour resoudre les conflits de couleur, faire une rotation quand on a bien right et left de completes, sinon push la couleur plus haut dans l'arbre*/
//en vrai je suis plus sure. Franchement je sais pas c'est bizarre

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
				_trunk = createNode(val, NULL, alloc);
				_leftest = _trunk;
				_rightest = _trunk;
			}
			
			RBnode<T>*			getTrunck()
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
					_trunk = createNode(val, NULL, alloc);
					_leftest = _trunk;
					_rightest = _trunk;
				}
				else
				{
					while (next)
					{
						parent = next;
						if (val > next->content)
							next = next->right;
						else
							next = next->left;
					}
					if (val > parent->content)
					{
						parent->right = createNode(val, parent, alloc);
						balanceTree(parent->right);
					}
					else
					{
						parent->left = createNode(val, parent, alloc);
						balanceTree(parent->left);
					}
					
				}
			}

			bool	isBalanced(void)
			{
				RBnode<T> *testedNode = _leftest;
				size_t	depth = _leftest->getDepth();

				while (testedNode != _rightest)
				{
					testedNode = testedNode->nextLeaf();
					if (testedNode->getDepth() != depth)
						return (false);
				}
				return (true);
			}
/*
				bool	balancedThroughRecoloring(RBnode<T> &lastInserted)
				{
					if (lastInserted->parent == NULL)
						return (true);
					lastInserted->colour = true;
					if (lastInserted->parent->colour)
						lastInserted->parent->colour == false;
					
				}

				void	balanceTroughPivot()
				{
					
				}
*/
			void	balanceTree(RBnode<T> *lastInserted)
			{
				/*if (!(isBalanced()))
				{
					if (lastInserted->parent && lastInserted->onlyChild())
					{
						if (lastInserted->data < lastInserted->parent->data)
							lastInserted->parent.rightRotate();
						else
							lastInserted->parent.leftRotate();
					}
					if (!balancedThroughRecoloring(lastInserted))
						balanceTroughPivot();
				}*/

				//insert case I1
				if (!lastInserted->parent->colour)
					return ;
				//insert case I2
				if (lastInserted->parent && lastInserted->parent->colour && lastInserted->getUncle() && lastInserted->getUncle()->colour)
				{
					lastInserted->parent->colour = false;
					lastInserted->getUncle()->colour = false;
					lastInserted->parent->parent->colour = true;
					balanceTree(lastInserted->parent->parent);
				}
				//Insert case I3 (inside de I2)
				//Insert case I4
				if (lastInserted->parent && lastInserted->parent->colour && !lastInserted->parent->parent)
				{
					lastInserted->parent->colour = false;
					return ;
				}
				//Insert case I5 (inner grandchild)
				if (lastInserted->parent && lastInserted->parent->colour && lastInserted->getUncle() && !lastInserted->getUncle()->colour)
				{
					if (lastInserted->parent->parent && lastInserted->parent == lastInserted->parent->parent->left)
					{
						if (lastInserted == lastInserted->parent->right)
						{
							lastInserted->parent->leftRotate();
							lastInserted = lastInserted->left;
						}
					}
					else
					{
						if (lastInserted == lastInserted->parent->left)
						{
							lastInserted->parent->rightRotate();
							lastInserted = lastInserted->right;
						}
					}
				}
				//Insert case I6
				RBnode<T> *grandparent = lastInserted->getGrandparent();
				if (lastInserted->parent && grandparent && lastInserted->parent == grandparent->left)
				{
					grandparent->rightRotate();
					lastInserted->parent->colour = false;
					grandparent->colour = true;
				}
				else if (lastInserted->parent && grandparent && lastInserted->parent == grandparent->right)
				{
					grandparent->leftRotate();
					lastInserted->parent->colour = false;
					grandparent->colour = true;
				}
			}
				
			
			void			deleteNode(T* ptr)
			{
				
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
			/*void			balanceTree()
			{
				//aussi penser a mettre a jour rightest et leftest
				RBnode	*pivot = findUnbalancedNode();
				
				if (pivot)
				{
					//la branche gauche est plus lourde
					if (pivot->left.getDepth() > pivot->right.getDepth())
					{
						
					}
					//la branche droite est plus lourde
					else
					{
						
					}
				}
			}*/

			void fillTab(std::map<int, std::vector<T*> > &tab, RBnode<T>* node, int level, int maxlevel)
			{
				if (!node)
				{
					tab[level].push_back(NULL);
					level++;
					if (level < maxlevel)
					{
						fillTab(tab, NULL, level, maxlevel);
						fillTab(tab, NULL, level, maxlevel);
					}
				}
				else
				{
					tab[level].push_back(node->content);
					level++;
					if (level < maxlevel)
					{
						fillTab(tab, node->right, level, maxlevel);
						fillTab(tab, node->left, level, maxlevel);
					}
				}
			}
			void	print(void)
			{
				if (!_trunk)
				{
					std::cout << "Cet arbre est vide" << std::endl;
					return ;
				}
				std::map<int, std::vector<T*> > tab; //int pour la pronfondeur, mettre NULL si le node n existe pas
				int depth = _trunk->getDepth();
				fillTab(tab, _trunk, 0, depth);
				for(typename std::map<int, std::vector<T*> >::iterator it = tab.begin(); it != tab.end(); it++)
				{
					for (typename std::vector<T*>::iterator ite = (*it).second.begin(); ite != (*it).second.end(); ite++)
					{
						for (int i = 0; i < depth * 5 / (*it).first; i++)
							std::cout << " ";
						std::cout << std::setw(10) << std::setiosflags(std::ios::right) *it;
					}
					std::cout << std::endl << std::endl;
				}
				
			}
			
	};
}

