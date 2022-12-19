//
// Created by oreste on 11/11/22.
//
#include "Position.h"
#ifndef CHASSE_PAR_FAUVES_OCCUPANT_H
#define CHASSE_PAR_FAUVES_OCCUPANT_H


class Occupant {


public:
    Occupant();

    //This type will help us to determine the way to display the item
    virtual unsigned int getType()const=0;

};


#endif //CHASSE_PAR_FAUVES_OCCUPANT_H
