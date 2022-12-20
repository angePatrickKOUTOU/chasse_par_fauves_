//
// Created by groupe 12_2022-2023 on 12/11/22.
//

#ifndef CHASSE_PAR_FAUVES_LION_H
#define CHASSE_PAR_FAUVES_LION_H


#include "Enemie.h"

class Lion: public Enemie {

public:
    Lion();

    void bouger(const Position &position) override;

    unsigned int getType() const override;

};




#endif //CHASSE_PAR_FAUVES_LION_H
