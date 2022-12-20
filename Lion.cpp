//
// Created by groupe 12_2022-2023 on 12/11/22.
//

#include "Lion.h"

Lion::Lion() : Enemie(5, 50) {}
void Lion::bouger(const Position &position) {

}

unsigned int Lion::getType() const {
    return LION;
}
