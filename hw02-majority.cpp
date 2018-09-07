#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
/*
 * @author Ryan Eisenbarth with template from Prof. Dulimarta
 * @version 9/20/17
 */

using namespace std;

/**
 * The following recursive function returns a candidate for the majority element in a vector of integers
 * @param a input vector consisting of positive integers
 * @return the candidate element or -1 if none is found
 */
int findCandidate(vector<int> a) {
    vector<int> b;

    //base case
    if (a.size() == 1)
        return a[0];


    //For even vectors
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == a[i + 1])
            b.push_back(a[i]);
        i++;
    }
    //For odd size vectors
    if(a.size()/2 != 0 && b.size() == 0){
        for (int i = 1; i < a.size(); i++) {
            if (a[i] == a[i + 1])
                b.push_back(a[i]);
            i++;
        }
        if ((b.size() == 0) && (a[0] == a[a.size()-1]))
            b.push_back(a[0]);
    }
    else if (b.size() == 0)
        return -1;

    //recursive call
    return findCandidate(b);
}

/**
 * The following function calls a recursive function.
 * Returns r the majority element in a vector of integers
 * @param a input vector consisting of positive integers
 * @return the majority element or -1 if none is found
 */
int majority(vector<int> a) {

    //holds the candidate int
    int cand;

    //helper int to see if candidate is majority
    int count = 0;

    // Using clog for debugging output
    clog << "Input vector is: ";
    for (auto &x : a)
        clog << x << " ";
    clog << endl;

    //determines if candidate is the majority of a vector
    cand = findCandidate(a);
    for (int i = 0; i < a.size(); i++)
        if (cand == a[i])
            count++;
    if (count > a.size() / 2)
        return cand;
    return -1;
}


int main(int argc, char *argv[]) {
    //Use clog for your debugging output
    clog << "This program runs from " << argv[0] << endl;
    if (argc < 2) {
        cerr << "Missing filename argument" << endl;
        exit(0);
    }

    /* The first command line argument is the input filename */
    ifstream inputfile{argv[1]};   /* input file stream */
    if (inputfile.good()) {
        int num_test, num_items_per_test;
        vector<int> testVector;

        inputfile >> num_test;  // read the number of test cases

        //Use clog for your debugging
        clog << "Number of test cases: " << num_test << endl;
        for (int k = 0; k < num_test; k++) {
            inputfile >> num_items_per_test;
            clog << "Test " << k << " has " << num_test << " data items" << endl;
            testVector.clear();
            for (int m = 0; m < num_items_per_test; m++) {
                int val;
                inputfile >> val;
                testVector.push_back(val);
            }
            // Use cout for the ACTUAL output
            cout << "Majority: " << majority(testVector) << endl;
        }
    } else {
        cerr << "Can't open data file " << argv[1] << endl;
    }
    return 0;
}