//
// Created by oreste on 11/11/22.
//

#include "Participant.h"


void decrementer(const unsigned int& puissance);

Participant::Participant(unsigned int vie) : Occupant(),vie(vie) {}

unsigned int Participant::getVie() const {
    return vie;
}

void Participant::setVie(unsigned int vie) {
    Participant::vie = vie;
}
