//
// Created by groupe 12_2022-2023 on 11/11/22.
//
#include "Position.h"
#ifndef CHASSE_PAR_FAUVES_OCCUPANT_H
#define CHASSE_PAR_FAUVES_OCCUPANT_H


class Occupant {


public:
    Occupant();

    // Ce type nous aidera � d�terminer la mani�re d'afficher l'�l�ment
    virtual unsigned int getType()const=0;

};


#endif //CHASSE_PAR_FAUVES_OCCUPANT_H
