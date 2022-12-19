//
// Created by oreste on 13/11/22.
//

#ifndef CHASSE_PAR_FAUVES_VIDE_H
#define CHASSE_PAR_FAUVES_VIDE_H


#include "Occupant.h"

class Vide: public Occupant {
public:
    explicit Vide();

    unsigned int getType() const override;

};


#endif //CHASSE_PAR_FAUVES_VIDE_H
