//
// Created by Ryan Eisenbarth on 10/21/17.
//

#ifndef HW_03_BINARYSEARCHTREE_H
#define HW_03_BINARYSEARCHTREE_H

#include <memory>
#include <iostream>

using namespace std;

template <typename E>     // textbook code E is Comparable
class BinarySearchTree {
public:
    /**
     * Default constructor
     */
    BinarySearchTree() {
    }

    /**
     * Destructor
     */
    ~BinarySearchTree() {
        purge(root);
    }

    void insert (E item) {
        insert (item, root);
    }

    void printTree(ostream& out = cout) const {
        print (out, root);
    }

    /* TODO: add the following public functions (lines 10-19, page 133 of textbook) .
     * findMin(), findMax(), contains(), isEmpty(), makeEmpty(), remove()
     *
     * and write their corresponding private functions in the private section below
     * Remember to use shared_ptr<Node> in place of Node* shown in text book code
     *
     */

    const E & findMin() const{
        return findMin(root)->data;
    }

    const E & findMax() const {
        return findMax(root)->data;
    }

    bool contains(const E & x) const{
        return contains(x, root);
    }

    bool isEmpty() const{
        return isEmpty(root);
    }

    void makeEmpty(){
        makeEmpty(root);
    }

    void remove(const E & x){
        remove(x, root);
    }

private:
    struct Node {
        E data;
        shared_ptr<Node> left, right;
    };

    shared_ptr<Node> root;

    void print (ostream& out, shared_ptr<Node> ptr) const {
        /* in order traversal */
        if (ptr != nullptr) {
            print (out, ptr->left);
            out << ptr->data << " ";
            print (out, ptr->right);
        }
    }

    void insert (E item, shared_ptr<Node>& ptr) const {
        if (ptr == nullptr) {
            ptr = make_shared<Node>();
            ptr->data = item;
        } else if (item < ptr->data) {
            insert(item, ptr->left);
        } else if (item > ptr->data) {
            insert(item, ptr->right);
        } else {
            // attempt to insert a duplicate item
        }
    }

    void purge (shared_ptr<Node> ptr) {
        if (ptr != nullptr) {
            purge (ptr->left);
            purge (ptr->right);
            ptr.reset();
        }
    }

    shared_ptr<Node> findMin( shared_ptr<Node> t) const{
        if( t == nullptr)
            return nullptr;
        if(t->left == nullptr)
            return t;
        return findMin(t->left);
    }

    shared_ptr<Node> findMax( shared_ptr<Node> t) const{
        if( t == nullptr)
            return nullptr;
        if(t->right == nullptr)
            return t;
        return findMax(t->right);
    }

    bool contains(const E & x, shared_ptr<Node> t) const{
        if( t == nullptr)
            return false;
        else if(x < t->data)
            return contains(x, t->left);
        else if(t->data < x)
            return contains(x, t->right);
        else {

            return true;
        }
    }
    void remove(const E & x, shared_ptr<Node> & t){
        if (t == nullptr)
            return;
        if (x < t->data)
            remove(x, t->left);
        else if(t->data < x)
            remove(x, t->right);
        else if(t->left != nullptr && t->right != nullptr){
            t->data = findMin(t->right)->data;
            remove(t->data, t->right);
        }
        else{
            shared_ptr<Node> old = t;
            t = (t->left != nullptr) ? t->left : t->right;
            old.reset();
        }
    }

    void makeEmpty(shared_ptr<Node> & t){
        if(t != nullptr){
            makeEmpty(t->left);
            makeEmpty(t->right);
            t.reset();
        }
        t = nullptr;
    }
    bool isEmpty(shared_ptr<Node> t) const{
        if(t == nullptr)
            return true;
        return false;
    }


};

#endif //HW_03_BINARYSEARCHTREE_H
