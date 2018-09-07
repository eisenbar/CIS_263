//
// Ryan Eisenbarth
//

#ifndef BINARYTREES_BINARYSEARCHTREE_H
#define BINARYTREES_BINARYSEARCHTREE_H
#include <memory>
#include <iostream>
#include <vector>

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

    bool isEmpty() const {
        return root != nullptr;
    }

    int number_of_nodes() const {
        int count = 0;
        count = nodeCount(root);

        return count;
    }

    int number_of_leaves() const {
        int leaves = 0;
        leaves = countLeaves( root );

        return leaves;
    }

    int number_of_full_nodes() const {
        int full = 0;
        full = countFull(root);

        return full;
    }

    vector<E> remove_leaves() {
        vector<E> result;

        if(root->left == nullptr && root->right == nullptr){
            result.push_back(root->data);
            root = nullptr;
        }
        else
            return remove_leaves(root, result);
        return result;
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

    void purge (shared_ptr<Node>& ptr) {
        if (ptr != nullptr) {
            purge (ptr->left);
            purge (ptr->right);
            ptr.reset();
        }
    }
    vector<E> remove_leaves( shared_ptr<Node> e, vector<E> result ){


        //left recursion
        if(e->left != nullptr) {
            if (e->left->left == nullptr && e->left->right == nullptr) {
                result.push_back(e->left->data);
                e->left = nullptr;
            }
            else
                remove_leaves(e->left, result);
        }

        //right recursion
        if(e->right != nullptr) {
            if (e->right->left == nullptr && e->right->right == nullptr) {
                result.push_back(e->right->data);
                e->right = nullptr;
            }
            else
                remove_leaves(e->right, result);
        }
        return result;
    }
    int countLeaves(shared_ptr<Node> e) const{

        if(e == nullptr)
            return 0;

        if(e->left == nullptr && e->right == nullptr)
            return 1;

        return countLeaves(e->left) + countLeaves(e->right);
    }
    int countFull(shared_ptr<Node> e) const{

        if(root == nullptr)
            return 0;

        if(e->left == nullptr && e->right == nullptr)
            return 0;

        if(e->left != nullptr && e->right != nullptr)
            return 1 + countFull(e->left) + countFull(e->right);

        if(e->left != nullptr && e->right == nullptr)
            return countFull(e->left);

        if(e->left == nullptr && e->right != nullptr)
            return countFull(e->right);
    }
    int nodeCount(shared_ptr<Node> e) const{

        if(e == nullptr)
            return 0;

        int ndeCnt = 1;

        if(e->left != nullptr)
            ndeCnt += nodeCount(e->left);
        if(e->right != nullptr)
            ndeCnt += nodeCount(e->right);

        return ndeCnt;
    }
};
#endif //BINARYTREES_BINARYSEARCHTREE_H