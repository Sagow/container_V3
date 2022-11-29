/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:01:55 by mdelwaul          #+#    #+#             */
/*   Updated: 2022/11/29 19:09:10 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

namespace ft
{
	template <class T>
	class RBnode{
		public:
			T				content;
			struct RBnode*	left;
			struct RBnode*	right;
			struct RBnode*	parent;
			bool			colour;
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
			RBnode()
			{
				_trunck = NULL;
				_leftest = NULL;
				_rightest = NULL;
			}
			RBnode(T val)
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

				if (!_trunck)
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
	};
}

