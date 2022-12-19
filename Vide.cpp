//
// Created by oreste on 13/11/22.
//

#include "Vide.h"

Vide::Vide(): Occupant() {}

unsigned int Vide::getType() const {
    return VIDE;
}
