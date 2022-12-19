//
// Created by oreste on 11/11/22.
//

#include "Joueur.h"


Joueur::Joueur(unsigned int vie) : Participant(vie) {}
Joueur::Joueur() :Joueur (5) {}

void Joueur::bouger(const Position &position) {

}

unsigned int Joueur::getType() const {
    return JOUEUR;
}
