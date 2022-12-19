//
// Created by oreste on 11/11/22.
//

#include "Obstacle.h"

Obstacle::Obstacle(): Occupant() {}

unsigned int Obstacle::getType() const {
    return OBSTACLE;
}
