//
// Created by oreste on 11/11/22.
//

#ifndef CHASSE_PAR_FAUVES_OBSTACLE_H
#define CHASSE_PAR_FAUVES_OBSTACLE_H


#include "Occupant.h"

class Obstacle : public Occupant{
public:
    Obstacle();

    unsigned int getType() const override;
};


#endif //CHASSE_PAR_FAUVES_OBSTACLE_H
