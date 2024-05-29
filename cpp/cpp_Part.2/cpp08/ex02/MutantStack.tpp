/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:02:14 by smonte-e          #+#    #+#             */
/*   Updated: 2024/05/29 16:24:09 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

// Public Constructors and Destructor
template<typename T>
MutantStack<T>::MutantStack() : std::stack<T, std::deque<T> >() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T, std::deque<T> >(src) {}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &rhs) {
    if (this != &rhs) {
        std::stack<T, std::deque<T> >::operator=(rhs);
    }
    return *this;
}

template<typename T>
MutantStack<T>::~MutantStack() {}

// Methods to get iterators
template<typename T>
typename std::deque<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template<typename T>
typename std::deque<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

template<typename T>
typename std::deque<T>::const_iterator MutantStack<T>::begin() const {
    return this->c.begin();
}

template<typename T>
typename std::deque<T>::const_iterator MutantStack<T>::end() const {
    return this->c.end();
}

template<typename T>
typename std::deque<T>::reverse_iterator MutantStack<T>::rbegin() {
    return this->c.rbegin();
}

template<typename T>
typename std::deque<T>::reverse_iterator MutantStack<T>::rend() {
    return this->c.rend();
}

template<typename T>
typename std::deque<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
    return this->c.rbegin();
}

template<typename T>
typename std::deque<T>::const_reverse_iterator MutantStack<T>::rend() const {
    return this->c.rend();
}

#endif
