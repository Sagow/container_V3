/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:01:55 by mdelwaul          #+#    #+#             */
/*   Updated: 2022/11/22 19:37:03 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	template <class T>
	struct RBnode{
		T*		content;
		struct RBnode*	left;
		struct RBnode*	right;
		bool			colour;
	};

	template <class T>
	class RBtree
	{
		private:
			struct RBnode	*trunk;
			struct RBnode	*leftest;
			struct RBnode	*rightest;
		
		public:
			RBnode*			getTrunck();
			RBnode*			getLeftest();
			RBnode*			getRightest();
	};
}