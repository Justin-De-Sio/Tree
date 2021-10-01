//
// Created by Justin on 01/10/2021.
//

#ifndef RANDOMTREE_RANDOMTREE_HPP
#define RANDOMTREE_RANDOMTREE_HPP

#include "memory"
#include "iostream"
#include "node.hpp"

template<typename T>
class RandomTree {
private:
    std::shared_ptr<CNode<T>> m_Root;
public:
    RandomTree(const T &val);

    void add(const T &val);

    void show() const;
};

template<typename T>
RandomTree<T>::RandomTree(const T &val): m_Root(new CNode<T>(val)) {}

template<typename T>
void localShow(const std::shared_ptr<CNode<T>> &ptr) {
    if (ptr == nullptr) return;
    localShow(ptr->getLeftChild());
    std::cout << ptr->getData()<< "\n";
    localShow(ptr->getRightChild());
}

template<typename T>
void RandomTree<T>::show() const {
    std::cout << m_Root->getData() << "\n";
    localShow(m_Root->getLeftChild());
    localShow(m_Root->getRightChild());
}

template<typename T>
void localAdd(const std::shared_ptr<CNode<T>> &ptr, const T &val) {
    if (ptr->getLeftChild() == nullptr)
        ptr->setLeftChild(std::make_shared<CNode<T>>(val));
     else if (ptr->getRightChild() == nullptr)
        ptr->setRightChild(std::make_shared<CNode<T>>(val));
     else if (std::rand() % 2)
        localAdd(ptr->getLeftChild(), val);
    else
        localAdd(ptr->getRightChild(), val);
}

template<typename T>
void RandomTree<T>::add(const T &val) {
    localAdd(m_Root, val);
}

#endif //RANDOMTREE_RANDOMTREE_HPP
