//
// Created by oreste on 12/11/22.
//

#include "Lion.h"

Lion::Lion() : Enemie(5, 50) {}
void Lion::bouger(const Position &position) {

}

unsigned int Lion::getType() const {
    return LION;
}