//
// Created by oreste on 11/11/22.
//

#ifndef CHASSE_PAR_FAUVES_PIEGE_H
#define CHASSE_PAR_FAUVES_PIEGE_H


#include "Occupant.h"

class Piege : public Occupant{

public:
    explicit Piege();

    unsigned int getType() const override;
};


#endif //CHASSE_PAR_FAUVES_PIEGE_H
