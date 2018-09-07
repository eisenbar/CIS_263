//
// Created by Ryan Eisenbarth on 9/6/17.
//

#include "Coin.h"

int HEAD = 1000; //global variable
int Coin::HEADS = 0; //a variable of Coin
int Coin::TAILS = 1; //a variable of Coin

Coin::Coin(){
    flip();
}
Coin::Coin(int face){
    this-> face = face;
}
void Coin::flip() {
    face = 1 - face;
}

bool Coin::isHeads() const{
    return face == HEADS;
}

Coin* Coin::flipped() const {
    Coin* c = new Coin;
    c->flip();
    return c;
}
string Coin::toString() const{

    string faceName;

    if (face == HEADS)
        faceName = "Heads";
    else
        faceName = "Tails";

    return faceName;
}
