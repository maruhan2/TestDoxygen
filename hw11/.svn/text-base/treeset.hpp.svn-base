/**
 * \file treeset.hpp
 * \author Kevin McSwiggen and Mars Park
 * 
 * \brief The declaration of TreeSet.
 *
 */

#ifndef TREESET_HPP_INCLUDED
#define TREESET_HPP_INCLUDED 1

#include <ostream>
#include <cstddef>

#include "abstractset.hpp"

/**
 * \class TreeSet
 * \brief TreeSet to be inherited.
 *
 * \details Uses an AVL Tree.
 */
template <typename T>
class TreeSet : public AbstractSet<T>
{
public: 
    /// Default constructor for TreeSet 
    TreeSet();

    /**
     * \brief Destructor for TreeSet
     *
     * \details Uses the destructor of the private class Node to recursively
     *          delete the tree.
     */
    ~TreeSet();

    /// Returns the number of objects stored in the tree.
    size_t size() const;

    /**
     * \brief Inserts an element into the tree.
     *
     * \details Calls a helper function to recursively find the insertion point
     *          and balance the tree.
     */
    void insert(const T& x);

    /**
     * \brief Checks if the element exists in the tree.
     *
     * \details Calls a helper function to recursively search for the element.
     */
    bool exists(const T& x) const;

    /**
     * \brief Returns the height of tree.
     *
     * \details Returns -1 for an empty tree.
     */
    int height() const;

    /// Prints the tree.
    std::ostream& print(std::ostream& out) const;

    /// Prints debugging information for the HashSet to cerr.
    void debug() const;

private:
    /**
     * \class Node
     * \brief Class that stores information about an element in the tree.
     *
     * \details Because it is an AVL tree, each node keeps track of its own
     *          height.
     *          Contains pointers to the root nodes of the left and right
     *          subtrees.
     */
    class Node 
    {
    public:
        Node(const T& x);
        /// Recursively deletes subtrees.
        ~Node();
        T value_;
        Node* left_;
        Node* right_;
        int height_;
    };

    /// Recursive helper function for exists(const T& x).
    bool exists(const T& x, Node* node) const;

    /// Returns the height of the specified node.
    int height(const Node* x) const;

    /// Left rotation on a node. Modified from the wiki notes.
    void rotateLeft(Node*& x);

    /// Right rotation on a node. Modified from the wiki notes.
    void rotateRight(Node*& x);

    /// Recursive helper function for insert.
    void insertAtNode(const T& x, Node*& node);

    /// Returns the value of the left-most node.
    T minElement(Node* node) const;

    /// Returns the value of the right-most node.
    T maxElement(Node* node) const;

    /// Recursive helper function for print(std::ostream& out).
    std::ostream& print(Node* node, std::ostream& out) const;

    /// Pointer to the root of the tree. An empty tree's root is a Null pointer.
    Node* root_;

    /// Size of the tree.
    size_t size_;

};

#include "treeset-private.hpp"

#endif // TREESET_HPP_INCLUDED
