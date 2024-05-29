/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:16:31 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/29 17:15:47 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
    // Public Constructors and Destructor
    MutantStack();
    MutantStack(const MutantStack& src);
    MutantStack& operator=(const MutantStack& rhs);
    ~MutantStack();

    // Type definitions for iterators
    typedef typename std::deque<T>::iterator                iterator;
    typedef typename std::deque<T>::const_iterator          const_iterator;
    typedef typename std::deque<T>::reverse_iterator        reverse_iterator;
    typedef typename std::deque<T>::const_reverse_iterator  const_reverse_iterator;

    // Methods to get iterators
    iterator                begin();
    iterator                end();
    const_iterator          begin() const;
    const_iterator          end() const;
    reverse_iterator        rbegin();
    reverse_iterator        rend();
    const_reverse_iterator  rbegin() const;
    const_reverse_iterator  rend() const;
};

#include "MutantStack.tpp"

#endif

