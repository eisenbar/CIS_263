//
// Created by Ryan Eisenbarth on 9/6/17.
//Try to keep the .h similar to a java interface
//

#ifndef COINEXAMPLE_COIN_H
#define COINEXAMPLE_COIN_H

#include <string>
using std::string;

class Coin {
private:
    static int HEADS;
    static int TAILS;
    int face;

public:
    Coin();

    Coin(int face);

    void flip();

    //returns a NEW double flipped coin
    Coin* flipped() const;

    /* The following functions are immutable */
    bool isHeads() const;

    string toString() const;
};


#endif //COINEXAMPLE_COIN_H
