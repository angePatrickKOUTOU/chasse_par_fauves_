//
// Created by oreste on 11/11/22.
//

#ifndef CHASSE_PAR_FAUVES_JAGUAR_H
#define CHASSE_PAR_FAUVES_JAGUAR_H


#include "Enemie.h"

class Jaguar : public Enemie{
public:
    Jaguar();

    void bouger(const Position &position) override;

    unsigned int getType() const override;


};


#endif //CHASSE_PAR_FAUVES_JAGUAR_H
