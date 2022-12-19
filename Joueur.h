//
// Created by oreste on 11/11/22.
//

#ifndef CHASSE_PAR_FAUVES_JOUEUR_H
#define CHASSE_PAR_FAUVES_JOUEUR_H


#include "Position.h"
#include "Participant.h"

class Joueur:public Participant {

public:

    explicit Joueur(unsigned int vie);
    explicit Joueur();

    void bouger(const Position &position) override;

    unsigned int getType() const override;


};


#endif //CHASSE_PAR_FAUVES_JOUEUR_H
