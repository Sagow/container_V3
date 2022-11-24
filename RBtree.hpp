/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:01:55 by mdelwaul          #+#    #+#             */
/*   Updated: 2022/11/24 18:15:19 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	template <class T>
	struct RBnode{
		T				content;
		struct RBnode*	left;
		struct RBnode*	right;
		bool			colour;
	};

	template <class T>
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
				_trunk = new RBnode;
				_trunk->content = val;
				_trunk->left = NULL;
				_trunk->right = NULL;
				_trunk->colour = false;
				_leftest = _trunk;
				_rightest = _trunk;
			}
			RBnode*			getTrunck();
			RBnode*			getLeftest();
			RBnode*			getRightest();
			void			insertNode(T val)
			{
				RBnode *next = _trunk;

				if (!_trunck)
				{
					_trunk = new RBnode;
					_trunk->content = val;
					_trunk->left = NULL;
					_trunk->right = NULL;
					_trunk->colour = false;
					_leftest = _trunk;
					_rightest = _trunk;
				}
				else
				{
					while (next)
					{
						if (val > next->content)
							next = next->right;
						else
							next = next->left;
					}
					next = new RBnode;
					next->content = val;
					next->left = NULL;
					next->right = NULL;
					next->colour = false;
					balanceTree();
				}
			}
			void			deleteNode(T* ptr);
	};
}

