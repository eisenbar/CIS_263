#include <iostream>
#include "BinarySearchTree.h"
/*
 * Ryan Eisenbarth
 *CIS 263 Dulimarta
 * HW 03
 * 10/22/17
 */

int main() {
    BinarySearchTree<int> me;
    me.insert (20);
    me.insert (30);
    me.insert (-2);
    me.insert (10);
    me.insert (7);
    me.insert (35);
    me.insert (24);

    me.printTree();
    cout << "\nDo I contain 7? : ";
    fputs( me.contains(7) ? "true" : "false", stdout );
    cout << "\nDo I contain 100? : ";
    fputs( me.contains(100) ? "true" : "false", stdout );

    cout << "\n\nThis is the min: " << me.findMin() << endl;
    cout << "This is the max: " << me.findMax() << endl;

    cout << "\nAbout to remove 35!\n";
    me.remove(35);
    me.printTree();

    cout << "\n\nThe tree is empty: ";
    fputs( me.isEmpty() ? "true" : "false", stdout );
    cout << "\n";
    cout << "About to empty tree!\n";
    me.makeEmpty();
    cout << "The tree is empty: ";
    fputs( me.isEmpty() ? "true" : "false", stdout );
    me.printTree();

    return 0;
}