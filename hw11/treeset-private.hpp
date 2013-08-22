/**
 * \file treeset-private.hpp
 * \author Kevin McSwiggen and Mars Park
 * 
 * \brief The private implementation of the TreeSet template.
 *
 */

#include <iostream>
#include <cstddef>
#include <algorithm>

template <typename T>
TreeSet<T>::TreeSet()
    : root_(NULL), size_(0)
{
    //Nothing to do here.
}

template <typename T>
TreeSet<T>::~TreeSet()
{
    if (root_ != NULL)
    {
        delete root_; // This will call the destructor for Node.
    }
}

template <typename T>
TreeSet<T>::Node::Node(const T& x)
    : value_(x), left_(NULL), right_(NULL), height_(0)
{
    //Nothing to do here.
}

template <typename T>
TreeSet<T>::Node::~Node()
{
    if (left_ != NULL)
    {
        delete left_;
    }
    if (right_ != NULL)
    {
        delete right_;
    }
}

template <typename T>
size_t TreeSet<T>::size() const
{
    return size_;
}

template <typename T>
void TreeSet<T>::insert(const T& x)
{
    if (size_ == 0)
    {
        root_ = new Node(x);
    }
    else
    {
        insertAtNode(x, root_);
    }
    ++size_;
}

template <typename T>
int TreeSet<T>::height(const Node* x) const
{
    if (x == NULL)
    {
        return -1;
    }
    else
    {
        return x->height_;
    }
}

template <typename T>
void TreeSet<T>::insertAtNode(const T& x, Node*& node)
{
    if (x < node->value_)
    {
        if (node->left_ == NULL)
        {
            node->left_ = new Node(x);
        }
        else
        {
            insertAtNode(x, node->left_);
        }
    }
    else if (node->value_ < x)
    {
        if (node->right_ == NULL)
        {
            node->right_ = new Node(x);
        }
        else
        {
            insertAtNode(x, node->right_);
        }
    }

    //The following code is when the AVL tree becomes unbalanced.

    // If the balance factor of the node is 2, then it is not an AVL tree.
    // The left subtree outweighs the right subtree, so we rotate.
    if (height(node->left_) - height(node->right_) == 2)
    {
        // If the left child's balance factor is 1, then we right rotate
        // on node.
        if (height(node->left_->left_) - height(node->left_->right_) == 1)
        {
            rotateRight(node);
        }

        // If the left child's balance factor is -1, then we left rotate
        // on the left child and then right rotate on node.
        if (height(node->left_->left_) - height(node->left_->right_) == -1)
        {
            rotateLeft(node->left_);
            rotateRight(node);
        }
    }

    // If the balance factor of the node is -22, then it is not an AVL tree.
    // The right subtree outweighs the left subtree, so we rotate.
    if ( height(node->left_) - height(node->right_) == -2)
    {
        // If the right child's balance factor is -1, then we left rotate
        // on node.
        if (height(node->right_->left_) - height(node->right_->right_)
            == -1)
        {
            rotateLeft(node);
        }

        // If the right child's balance factor is 1, then we right rotate
        // on the right child and then left rotate on node.
        if (height(node->right_->left_) - height(node->right_->right_) == 1)
        {
            rotateRight(node->right_);
            rotateLeft(node);
        }
    }
    node->height_ = std::max(height(node->left_), height(node->right_)) + 1;
}

template <typename T>
T TreeSet<T>::minElement(Node* node) const
{
    if (node->left_ == NULL)
    {
        return node->value_;
    }
    else
    {
        return minElement(node->left_);
    }
}

template <typename T>
T TreeSet<T>::maxElement(Node* node) const
{
    if (node->right_ == NULL)
    {
        return node->value_;
    }
    else
    {
        return maxElement(node->right_);
    }
}

template <typename T>
bool TreeSet<T>::exists(const T& x) const
{
    return exists(x, root_);
}


template <typename T>
bool TreeSet<T>::exists(const T& x, Node* node) const
{
    if (node == NULL)
    {
        // If it reaches the end of its search path, then x is not there.
        return false;
    }
    else if (x < node->value_)
    {
        return exists(x, node->left_);
    }
    else if (node->value_ < x)
    {
        return exists(x, node->right_);
    }
    else
    {
        return true;
    }
}


template <typename T>
int TreeSet<T>::height() const
{
    return height(root_);
}

template <typename T>
std::ostream& TreeSet<T>::print(std::ostream& out) const
{
    print(root_, out);
    return out;
}

template <typename T>
std::ostream& TreeSet<T>::print(Node* node, std::ostream& out) const
{
    if (node == NULL)
    {
        out << "-";
    }
    else
    {
        out << "(";
        print(node->left_, out);
        out << ", " << node->value_ << ", ";
        print(node->right_, out);
        out << ")";
    }
    return out;
}

template <typename T>
void TreeSet<T>::debug() const
{
    std::cerr << "height " << height() << ", size " << size();
    if (size() != 0)
    {
    std::cerr << ", least element " << minElement(root_)
         << ", greatest element " << maxElement(root_)
         << ", root value " << root_->value_ << std::endl;
    }
}

template <typename T>
void TreeSet<T>::rotateLeft(Node*& x)
{
    Node* temp = x->right_;
    x->right_ = temp->left_;
    temp->left_ = x;
    x = temp;

    // Rotation needs to update the heights of the nodes being rotated.
    // Afterwards heights are correct for all subtrees of x.
    (x->left_)->height_ = std::max(height((x->left_)->left_), 
                                height((x->left_)->right_)) + 1;
    x->height_ = std::max(height(x->left_), 
                                height(x->right_)) + 1;
}

template <typename T>
void TreeSet<T>::rotateRight(Node*& x)
{
    Node* temp = x->left_;
    x->left_ = temp->right_;
    temp->right_ = x;
    x = temp;

    // Rotation needs to update the heights of the nodes being rotated.
    // Afterwards heights are correct for all subtrees of x.
    (x->right_)->height_ = std::max(height((x->right_)->left_), 
                                 height((x->right_)->right_)) + 1;
    x->height_ = std::max(height(x->left_), height(x->right_)) + 1;    
}
