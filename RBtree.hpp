/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:01:55 by mdelwaul          #+#    #+#             */
/*   Updated: 2022/12/01 22:43:34 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <iomanip>
#include <vector>
#include <map>
#include <iterator>
#include <iostream>

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

			size_t			getDepth(size_t depth = 0)
			{
				size_t add;
				
				if (!this)
					return (depth);
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
				}
				return (depth);
			}
	};

	template <class T, class Allocator = std::allocator<RBnode<T>> >
	RBnode<T>*			createNode(T data, RBnode<T>* parent, Allocator alloc)
	{
		RBnode* ptr = alloc.allocate(sizeof(RBnode));
		content = data;
		left = NULL;
		right = NULL;
		parent = parent;
		colour = false;
		return (ptr);
	};
	
	template <class T, class Allocator = std::allocator<RBnode<T>> >
	class RBtree
	{
		private:
			struct RBnode	*_trunk;
			struct RBnode	*_leftest;
			struct RBnode	*_rightest;
			void			balanceTree()
			{
				//aussi penser a mettre a jour rightest et leftest
			}
		
		public:
			RBtree()
			{
				_trunk = NULL;
				_leftest = NULL;
				_rightest = NULL;
			}
			RBtree(T val)
			{
				_trunk = createNode(val, NULL, Allocator);
				_leftest = _trunk;
				_rightest = _trunk;
			}
			RBnode*			getTrunck();
			RBnode*			getLeftest();
			RBnode*			getRightest();
			void			insertNode(T val)
			{
				RBnode *next = _trunk;
				RBnode *parent = NULL;

				if (!_trunk)
				{
					_trunk = createNode(val, NULL, Allocator);
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
					next = createNode(val, parent, Allocator);
					balanceTree();
				}
			}
			void			deleteNode(T* ptr)
			{
				
			}

			void fillTab(std::map<int, vector<T*> > &tab, RBnode* node, int level, int maxlevel)
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
				for(std::map<int, std::vector<T*> >::iterator it = tab.begin(); it != tab.end(); it++)
				{
					for (std::vector<T*>::iterator ite = (*it).second.begin(); ite != (*it).second.end(); ite++)
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

