#ifndef NODE_HPP
#define NODE_HPP

#include <memory>

template <typename T>
class CNode
{
private:
    T m_Data;
    std::shared_ptr<CNode> m_LeftChild;
    std::shared_ptr<CNode> m_RightChild;
public:
    //constructor
    CNode (const T &  val, const std::shared_ptr<CNode> & ptrLC = nullptr, const std::shared_ptr<CNode> & ptrRC = nullptr);



    //getter / setter
    const T &getData () const;
    const std::shared_ptr<CNode> & getLeftChild() const;
    const std::shared_ptr<CNode> & getRightChild() const;
    void setLeftChild(const std::shared_ptr<CNode> &LC);
    void setRightChild(const std::shared_ptr<CNode> &RC);

};


template <typename T>
CNode<T>::CNode (const T & val, const std::shared_ptr<CNode> & leftChild,  const std::shared_ptr<CNode> & rightChild) :
    m_Data (val), m_LeftChild (leftChild), m_RightChild (rightChild)
{
}

template<typename T>
void CNode<T>::setLeftChild(const std::shared_ptr<CNode> &LC)
{
    m_LeftChild = LC;
}

template<typename T>
void CNode<T>::setRightChild(const std::shared_ptr<CNode> &RC)
{
    m_RightChild = RC;
}

template<typename T>
const std::shared_ptr<CNode<T>> &CNode<T>::getRightChild() const
{
    return m_RightChild;
}

template<typename T>
const std::shared_ptr<CNode<T>> &CNode<T>::getLeftChild() const
{
    return m_LeftChild;
}

template<typename T>
const T &CNode<T>::getData () const
{
    return m_Data;
}

#endif // NODE_HPP
