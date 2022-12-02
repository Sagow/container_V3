/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:26:00 by mdelwaul          #+#    #+#             */
/*   Updated: 2022/12/02 20:28:58 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

iterator ft::vector::begin();
const_iterator ft::vector::begin() const;
iterator ft::vector::end();
const_iterator ft::vector::end() const;
reverse_iterator ft::vector::rbegin();
const_reverse_iterator ft::vector::rbegin() const;
reverse_iterator ft::vector::rend();
const_reverse_iterator ft::vector::rend() const;