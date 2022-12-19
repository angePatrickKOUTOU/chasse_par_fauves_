//
// Created by oreste on 11/11/22.
//

#include "Jaguar.h"

Jaguar::Jaguar() : Enemie(5, 45) {}

void Jaguar::bouger(const Position &position) {

}

unsigned int Jaguar::getType() const {
    return JAGUAR;
}
